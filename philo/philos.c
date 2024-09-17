/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussato <yussato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:16:47 by yussato           #+#    #+#             */
/*   Updated: 2024/09/18 00:27:20 by yussato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

pthread_t	*philos_create(int num)
{
	pthread_t	*threads;

	if (num < 1)
		return (NULL);
	threads = malloc(sizeof(pthread_t) * (num + 1));
	if (!threads)
		return (NULL);
	memset(threads, 0, sizeof(pthread_t) * (num + 1));
	return (threads);
}

pthread_t	*philos_destroy(pthread_t *threads)
{
	free(threads);
	return (NULL);
}

t_philo	*philos_data_create_2(t_config *cfg, t_channel *die)
{
	pthread_mutex_t	*forks;
	t_philo			*philos;
	int				num;

	num = cfg->num;
	if (num < 1)
		return (NULL);
	forks = forks_create(num);
	if (forks == NULL)
		return (NULL);
	philos = malloc(sizeof(t_philo) * (num + 1));
	if (!philos)
		return (NULL);
	memset(philos, 0, sizeof(t_philo) * (num + 1));
	while (num--)
	{
		philos[num].id = num + 1;
		philos[num].config = *cfg;
		philos[num].lfork = &forks[num];
		philos[num].rfork = &forks[0];
		philos[num].die = *die;
		if (num + 1 < cfg->num)
			philos[num].rfork = &forks[(num + 1)];
	}
	return (philos);
}

t_philo	*philos_data_create(t_config *cfg, t_channel *die)
{
	t_philo	*philos;
	long	start_at;
	int		num;

	philos = philos_data_create_2(cfg, die);
	start_at = getms() + cfg->num * 20;
	num = cfg->num;
	while (num--)
		philos[num].start_at = start_at;
	return (philos);
}

t_philo	*philos_data_destroy(t_philo *philos)
{
	int	num;

	if (philos)
	{
		num = philos->config.num;
		while (num--)
			pthread_mutex_destroy(philos[num].lfork);
		free(philos->lfork);
		free(philos);
	}
	return (NULL);
}
