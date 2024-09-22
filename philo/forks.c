/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:27:17 by yushsato          #+#    #+#             */
/*   Updated: 2024/09/22 16:27:18 by yushsato         ###   ########.fr       */
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
