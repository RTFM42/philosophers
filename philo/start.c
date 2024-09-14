/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussato <yussato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:31:38 by yussato           #+#    #+#             */
/*   Updated: 2024/09/14 22:16:16 by yussato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

static void	philo_delay(int id)
{
	if (id != 1)
		usleep(50);
	if (id % 2 == 0)
		usleep(50);
}

void	*routine(t_philo *philo)
{
	t_channel	*die;
	long		start_at;

	(void)die;
	start_at = getms();
	philo_delay(philo->id);
	if (philo->lfork == philo->rfork && !usleep(philo->config.dur_die * 1000)
		&& printf("%ld %d died\n", getms() - start_at, philo->id))
		return (NULL);
	while (1)
	{
		printf("%ld %d is thinking\n", getms() - start_at, philo->id);
		pthread_mutex_lock(philo->lfork);
		printf("%ld %d has taken a fork\n", getms() - start_at, philo->id);
		pthread_mutex_lock(philo->rfork);
		printf("%ld %d has taken a fork\n", getms() - start_at, philo->id);
		printf("%ld %d is eating\n", getms() - start_at, philo->id);
		usleep(philo->config.dur_eat * 1000);
		pthread_mutex_unlock(philo->lfork);
		pthread_mutex_unlock(philo->rfork);
		printf("%ld %d is sleeping\n", getms() - start_at, philo->id);
		usleep(philo->config.dur_slp * 1000);
	}
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
