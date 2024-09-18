/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussato <yussato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:31:38 by yussato           #+#    #+#             */
/*   Updated: 2024/09/18 18:24:55 by yussato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	die_check(t_philo *philo)
{
	int	die;

	channel_recv(&philo->die, &die);
	return (die);
}

int	take_the_left_fork(int id, long start_at, t_philo *philo)
{
	long	now;

	if (die_check(philo))
		return (1);
	pthread_mutex_lock(philo->lfork);
	now = getms() - start_at;
	if (die_check(philo))
		return (1);
	printf("%ld %d has taken a fork\n", now, id);
	return (0);
}

int	take_the_right_fork(int id, long start_at, t_philo *philo)
{
	long	now;

	if (die_check(philo))
		return (1);
	pthread_mutex_lock(philo->rfork);
	now = getms() - start_at;
	if (die_check(philo))
		return (1);
	printf("%ld %d has taken a fork\n", now, id);
	return (0);
}

int	have_a_meal(int id, long start_at, t_philo *philo, t_channel *last_meal)
{
	const long	now = getms();

	if (die_check(philo))
	{
		pthread_mutex_unlock(philo->lfork);
		pthread_mutex_unlock(philo->rfork);
		return (1);
	}
	printf("%ld %d is eating\n", now - start_at, id);
	usleep(philo->config.dur_eat * 1000);
	pthread_mutex_unlock(philo->lfork);
	pthread_mutex_unlock(philo->rfork);
	channel_send(last_meal, (long []){now + philo->config.dur_eat});
	return (0);
}

int	get_sleep(int id, long start_at, t_philo *philo)
{
	const long	now = getms() - start_at;
	
	if (die_check(philo))
		return (1);
	printf("%ld %d is sleeping\n", now, id);
	usleep(philo->config.dur_slp * 1000);
	return (0);
}

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
			channel_send(&sub->philo.die, (int []){sub->philo.id});
			usleep(10000);
			channel_recv(&sub->philo.die, &die);
			if (die == sub->philo.id)
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
	t_philo_sub sub;

	sub.philo = *philo;
	sub.start_at = philo->start_at;
	sub.last_meal = channel_create(&philo->start_at, sizeof(long));
	pthread_create(&p_sub, NULL, (void *)(void *)sub_routine, &sub);
	while (philo->start_at > getms())
		usleep(500);
	if (philo->id != 1)
		usleep(500);
	if (philo->id % 2 == 0)
		usleep(500);
	while (1)
		if (take_the_left_fork(philo->id, philo->start_at, philo)
			|| take_the_right_fork(philo->id, philo->start_at, philo)
			|| have_a_meal(philo->id, philo->start_at, philo, sub.last_meal)
			|| get_sleep(philo->id, philo->start_at, philo))
			break ;
	pthread_join(p_sub, NULL);
	channel_destroy(sub.last_meal);
	return (NULL);
}

int	start(t_config *cfg)
{
	t_channel	*die;
	pthread_t	*philos;
	t_philo		*data;
	int			num;

	num = cfg->num;
	die = channel_create((int []){0}, sizeof(int));
	if (!die)
		return (1);
	philos = philos_create(cfg->num);
	if (!philos)
		return (!channel_destroy(die) * 0 + 1);
	data = philos_data_create(cfg, die);
	if (!data)
		return (!philos_destroy(philos) * !channel_destroy(die) * 0 + 1);
	while (num--)
		pthread_create(&philos[num], 0, (void *)(void *)routine, &data[num]);
	num = cfg->num;
	while (num--)
		pthread_join(philos[num], NULL);
	data = philos_data_destroy(data);
	philos = philos_destroy(philos);
	die = channel_destroy(die);
	free(cfg);
	return (0);
}
