/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussato <yussato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:31:38 by yussato           #+#    #+#             */
/*   Updated: 2024/09/13 16:51:38 by yussato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void	*routine(void *philo)
{
	(void)philo;
	return (NULL);
}

int	start(t_config *cfg)
{
	t_channel	*die;
	pthread_t	*philos;
	t_philo		*data;
	int			num;

	num = cfg->num;
	die = channel_create((int[]){0}, sizeof(int));
	if (!die)
		return (1);
	philos = philos_create(cfg->num);
	if (!philos)
		return (!channel_destroy(die) * 0 + 1);
	data = philos_data_create(cfg, die);
	if (!data)
		return (!philos_destroy(philos) * !channel_destroy(die) * 0 + 1);
	while (num--)
		pthread_create(&philos[num], NULL, routine, &data[num]);
	num = cfg->num;
	while (num--)
		pthread_join(philos[num], NULL);
	data = philos_data_destroy(data);
	philos = philos_destroy(philos);
	die = channel_destroy(die);
	free(cfg);
	return (0);
}
