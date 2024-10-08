/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:26:57 by yushsato          #+#    #+#             */
/*   Updated: 2024/09/22 16:26:59 by yushsato         ###   ########.fr       */
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

t_philo	*philos_data_create_2(t_config *cfg, t_channel die)
{
	t_channel	*forks;
	t_philo		*philos;
	int			num;

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
		philos[num].die = die;
		if (num + 1 < cfg->num)
			philos[num].rfork = &forks[(num + 1)];
	}
	return (philos);
}

t_philo	*philos_data_create(
	t_config *cfg, t_channel die, t_channel mst_eat_done)
{
	t_philo	*philos;
	long	start_at;
	int		num;

	philos = philos_data_create_2(cfg, die);
	start_at = getms() + cfg->num * 20;
	num = cfg->num;
	while (num--)
	{
		philos[num].start_at = start_at;
		philos[num].mst_eat_done = mst_eat_done;
	}
	return (philos);
}

t_philo	*philos_data_destroy(t_philo *philos)
{
	int	num;

	if (philos)
	{
		num = philos->config.num;
		while (num--)
			channel_destroy(*philos[num].lfork);
		free(philos->lfork);
		free(philos);
	}
	return (NULL);
}
