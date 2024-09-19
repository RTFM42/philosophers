/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussato <yussato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 20:38:01 by yussato           #+#    #+#             */
/*   Updated: 2024/09/19 20:38:12 by yussato          ###   ########.fr       */
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
