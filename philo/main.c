/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussato <yussato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:21:45 by yussato           #+#    #+#             */
/*   Updated: 2024/09/11 18:56:18 by yussato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	main(int ac, char *av[])
{
	t_config	*cfg;
	t_channel	*die;

	cfg = config_create(ac, av);
	die = channel_create((int[]){0}, sizeof(int));
	if (!cfg || !die)
		return (1);
	die = channel_destroy(die);
	return (0);
}
