/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 20:38:01 by yussato           #+#    #+#             */
/*   Updated: 2024/09/19 20:54:31 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/channel.h"

int	channel_safe_create(t_channel *channel, void *data, size_t type_size)
{
	*channel = channel_create(data, type_size);
	if (!channel->data || !channel->mutex)
	{
		channel_destroy(*channel);
		return (0);
	}
	return (1);
}
