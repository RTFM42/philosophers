/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 21:30:08 by yushsato          #+#    #+#             */
/*   Updated: 2024/09/19 20:54:55 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	putusage(const char *fname)
{
	ft_putstr_fd("Usage: ", 2);
	ft_putstr_fd(fname, 2);
	ft_putstr_fd(" number_of_philosophers "
		"time_to_die time_to_eat time_to_sleep "
		"[number_of_times_each_philosopher_must_eat]\n", 2);
}
