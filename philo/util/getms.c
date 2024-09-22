/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:27:32 by yushsato          #+#    #+#             */
/*   Updated: 2024/09/22 16:27:33 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>

long	getms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((long)tv.tv_sec * 1000 + (long)tv.tv_usec / 1000);
}
