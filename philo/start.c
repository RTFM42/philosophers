/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:31:38 by yussato           #+#    #+#             */
/*   Updated: 2024/09/19 23:08:33 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"
#include "errno.h"

void	*sub_routine(t_philo_sub *sub)
{
	long	last_meal;
	long	now;
	int		die;

	while (1)
	{
		channel_recv(sub->last_meal, &last_meal);
		now = getms();
		if (die_check(&sub->philo))
			break ;
		if (now - last_meal > sub->philo.config.dur_die)
		{
			channel_recv(sub->philo.die, &die);
			if (die != 0)
				break ;
			channel_send(sub->philo.die, (int []){sub->philo.id});
			channel_recv(sub->philo.die, &die);
			if (die == sub->philo.id && !usleep(100000))
				printf("%ld %d died\n", now - sub->start_at, sub->philo.id);
			break ;
		}
		usleep(500);
	}
	return (NULL);
}

void	*routine(t_philo *philo)
{
	pthread_t	p_sub;
	t_philo_sub	sub;
	int			eat;

	sub.philo = *philo;
	sub.start_at = philo->start_at;
	sub.last_meal = channel_create(&philo->start_at, sizeof(long));
	while (philo->start_at > getms())
		usleep(500);
	if (philo->id != 1)
		usleep(500);
	if (philo->id % 2 == 0)
		usleep(500);
	pthread_create(&p_sub, NULL, (void *)(void *)sub_routine, &sub);
	eat = 0;
	while (!(take_the_left_fork(philo->id, philo->start_at, philo)
			|| take_the_right_fork(philo->id, philo->start_at, philo)
			|| have_a_meal(&sub, &eat)
			|| get_sleep(philo->id, philo->start_at, philo)))
		;
	pthread_join(p_sub, NULL);
	channel_destroy(sub.last_meal);
	return (NULL);
}

int	end(t_philo *data, pthread_t *philos,
			t_channel die, t_channel mst_eat_done)
{
	int	num;

	num = data->config.num;
	while (num--)
		pthread_join(philos[num], NULL);
	if (data)
		data = philos_data_destroy(data);
	if (philos)
		philos = philos_destroy(philos);
	channel_destroy(die);
	channel_destroy(mst_eat_done);
	return (0);
}

int	start(t_config *cfg)
{
	t_channel	die;
	t_channel	mst_eat_done;
	pthread_t	*philos;
	t_philo		*data;
	int			num;

	if (!channel_safe_create(&die, (int []){0}, sizeof(int)))
	{
		free(cfg);
		return (1);
	}
	if (!channel_safe_create(&mst_eat_done, (int []){0}, sizeof(int)))
	{
		channel_destroy(die);
		free(cfg);
		return (1);
	}
	philos = philos_create(cfg->num);
	if (!philos)
	{
		channel_destroy(die);
		channel_destroy(mst_eat_done);
		free(cfg);
		return (1);
	}
	data = philos_data_create(cfg, die, mst_eat_done);
	if (!data)
	{
		channel_destroy(die);
		channel_destroy(mst_eat_done);
		philos_destroy(philos);
		free(cfg);
		return (1);
	}
	num = 0;
	while (num < cfg->num)
	{
		if (pthread_create(
				&philos[num], 0, (void *)(void *)routine, &data[num]))
		{
			channel_send(die, (int []){num + 2});
			while (num--)
				pthread_join(philos[num], NULL);
			channel_destroy(die);
			channel_destroy(mst_eat_done);
			philos_data_destroy(data);
			philos_destroy(philos);
			free(cfg);
			return (1);
		}
		num++;
	}
	channel_destroy(die);
	channel_destroy(mst_eat_done);
	philos_data_destroy(data);
	philos_destroy(philos);
	free(cfg);
	return (0);
}
