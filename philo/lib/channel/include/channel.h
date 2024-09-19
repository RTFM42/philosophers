/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   channel.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussato <yussato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:46:12 by yussato           #+#    #+#             */
/*   Updated: 2024/09/19 20:39:48 by yussato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_H
# define CHANNEL_H

# include <pthread.h>
# include <string.h>
# include <stdlib.h>

typedef struct s_channel
{
	void			*data;
	size_t			type_size;
	pthread_mutex_t	*mutex;
}	t_channel;

t_channel	channel_create(void *data, size_t type_size);
int			channel_destroy(t_channel channel);
int			channel_send(t_channel channel, void *src);
int			channel_recv(t_channel channel, void *dst);
int			channel_safe_create(
				t_channel *channel, void *data, size_t type_size);

#endif
