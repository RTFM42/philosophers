/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:27:28 by yushsato          #+#    #+#             */
/*   Updated: 2024/09/22 16:27:29 by yushsato         ###   ########.fr       */
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
