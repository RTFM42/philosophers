/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   channel.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:28:13 by yushsato          #+#    #+#             */
/*   Updated: 2024/09/22 16:28:14 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "channel.h"

static void	*ch_memcpy(void *dst, const void *src, size_t n)
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

t_channel	channel_create(void *data, size_t type_size)
{
	t_channel	channel;

	memset(&channel, 0, sizeof(t_channel));
	channel.data = (void *)malloc(type_size);
	channel.mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(channel.mutex, NULL);
	ch_memcpy(channel.data, data, type_size);
	channel = (t_channel){channel.data, type_size, channel.mutex};
	return (channel);
}

int	channel_destroy(t_channel channel)
{
	pthread_mutex_destroy(channel.mutex);
	if (channel.data)
		free(channel.data);
	if (channel.mutex)
		free(channel.mutex);
	channel.data = NULL;
	channel.mutex = NULL;
	return (0);
}

int	channel_send(t_channel channel, void *src)
{
	if (!pthread_mutex_lock(channel.mutex))
	{
		ch_memcpy(channel.data, src, channel.type_size);
		pthread_mutex_unlock(channel.mutex);
	}
	else
		return (1);
	return (0);
}

int	channel_recv(t_channel channel, void *dst)
{
	if (!pthread_mutex_lock(channel.mutex))
	{
		ch_memcpy(dst, channel.data, channel.type_size);
		pthread_mutex_unlock(channel.mutex);
	}
	else
		return (1);
	return (0);
}
