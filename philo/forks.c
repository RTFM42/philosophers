/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:00:49 by yussato           #+#    #+#             */
/*   Updated: 2024/09/19 20:55:01 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

t_channel	*forks_create(int num)
{
	t_channel	*forks;

	forks = malloc(sizeof(t_channel) * (num + 1));
	if (!forks)
		return (NULL);
	memset(forks, 0, sizeof(t_channel) * (num + 1));
	if (!forks)
		return (NULL);
	while (num--)
		forks[num] = channel_create((int []){0}, sizeof(int));
	return (forks);
}

void	forks_destroy(t_channel *forks, int num)
{
	while (num--)
		channel_destroy(forks[num]);
	free(forks);
}
