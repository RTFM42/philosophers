/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   channel.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussato <yussato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:44:59 by yussato           #+#    #+#             */
/*   Updated: 2024/09/17 19:45:03 by yussato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "channel.h"

void	*ch_memcpy(void *dst, const void *src, size_t n)
{
	char	*s;
	char	*d;

	if (!dst && !src)
		return (NULL);
	d = dst;
	s = (char *)src;
	while (n--)
		*d++ = *s++;
	return (dst);
}

t_channel	*channel_create(void *data, size_t type_size)
{
	t_channel	*channel;

	channel = (t_channel *)malloc(sizeof(t_channel));
	memset(channel, 0, sizeof(t_channel));
	channel->data = (void *)malloc(type_size);
	channel->mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	ch_memcpy(channel->data, data, type_size);
	channel->type_size = type_size;
	pthread_mutex_init(channel->mutex, NULL);
	return (channel);
}

t_channel	*channel_destroy(t_channel *channel)
{
	if (!channel)
		return (NULL);
	pthread_mutex_destroy(channel->mutex);
	free(channel->data);
	free(channel->mutex);
	free(channel);
	return (NULL);
}

int	channel_send(t_channel *channel, void *data)
{
	if (channel && !pthread_mutex_lock(channel->mutex))
	{
		ch_memcpy(channel->data, data, channel->type_size);
		pthread_mutex_unlock(channel->mutex);
	}
	else
		return (1);
	return (0);
}

int	channel_recv(t_channel *channel, void *data)
{
	if (channel && !pthread_mutex_lock(channel->mutex))
	{
		ch_memcpy(data, channel->data, channel->type_size);
		pthread_mutex_unlock(channel->mutex);
	}
	else
		return (1);
	return (0);
}
