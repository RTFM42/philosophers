/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:27:03 by yushsato          #+#    #+#             */
/*   Updated: 2024/09/22 16:27:04 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	main(int ac, char *av[])
{
	t_config	*cfg;

	cfg = config_create(ac, av);
	if (!cfg)
		return (1);
	if (start(cfg))
	{
		free(cfg);
		return (1);
	}
	free(cfg);
	return (0);
}
