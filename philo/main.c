/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:21:45 by yussato           #+#    #+#             */
/*   Updated: 2024/09/19 22:52:56 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	main(int ac, char *av[])
{
	t_config	*cfg;

	cfg = config_create(ac, av);
	if (!cfg)
		return (1);
	return (start(cfg));
}
