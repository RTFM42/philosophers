/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussato <yussato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 21:30:08 by yushsato          #+#    #+#             */
/*   Updated: 2024/08/29 23:45:12 by yussato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	putusage(const char *fname)
{
	ft_putstr_fd("Usage: ", 2);
	ft_putstr_fd(fname, 2);
	ft_putstr_fd(" number_of_philosophers"
		"time_to_die time_to_eat time_to_sleep "
		"[number_of_times_each_philosopher_must_eat]\n", 2);
}
