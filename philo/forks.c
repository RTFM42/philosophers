/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussato <yussato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:00:49 by yussato           #+#    #+#             */
/*   Updated: 2024/09/13 16:09:38 by yussato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

pthread_mutex_t	*forks_create(int num)
{
	pthread_mutex_t	*forks;

	forks = malloc(sizeof(pthread_mutex_t) * (num + 1));
	if (!forks)
		return (NULL);
	memset(forks, 0, sizeof(pthread_mutex_t) * (num + 1));
	if (!forks)
		return (NULL);
	while (num--)
		pthread_mutex_init(&forks[num], NULL);
	return (forks);
}

void	forks_destroy(pthread_mutex_t *forks, int num)
{
	while (num--)
		pthread_mutex_destroy(&forks[num]);
	free(forks);
}
