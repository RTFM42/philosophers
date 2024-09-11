/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getms.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussato <yussato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 02:40:17 by yussato           #+#    #+#             */
/*   Updated: 2024/08/28 02:41:52 by yussato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>

long	ft_getms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((long)tv.tv_sec * 1000 + (long)tv.tv_usec / 1000);
}
