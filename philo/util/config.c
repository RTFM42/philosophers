/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:36:16 by yussato           #+#    #+#             */
/*   Updated: 2024/09/22 06:51:39 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	putusage(const char *fname);

static int	is_nbr(const char *str)
{
	if (!str)
		return (0);
	if (*str == '0' && *(str + 1))
		return (0);
	if (*str == '0')
		return (1);
	while ('0' <= *str && *str <= '9')
		str++;
	return (!*str);
}

static int	is_valid_args(int ac, char *av[])
{
	if (ac != 5 && ac != 6)
	{
		putusage(av[0]);
		return (0);
	}
	if (!is_nbr(av[1]) || !is_nbr(av[2]) || !is_nbr(av[3]) || !is_nbr(av[4])
		|| (ac == 6 && !is_nbr(av[5])))
	{
		ft_putstr_fd("Error: Arguments must be positive integers.\n", 2);
		return (0);
	}
	return (1);
}

t_config	*config_create(int ac, char *av[])
{
	t_config	*config;

	config = (t_config *)malloc(sizeof(t_config));
	memset(config, 0, sizeof(t_config));
	if (!is_valid_args(ac, av))
	{
		free(config);
		return (NULL);
	}
	if (config == NULL)
		return (NULL);
	config->num = ft_atoi(av[1]);
	config->dur_die = ft_atoi(av[2]);
	config->dur_eat = ft_atoi(av[3]);
	config->dur_slp = ft_atoi(av[4]);
	config->mst_eat = -1;
	if (ac == 6)
		config->mst_eat = ft_atoi(av[5]);
	if (config->num > 400 || config->mst_eat == 0)
	{
		free(config);
		ft_putstr_fd("Invalid arguments.\n", 2);
		return (NULL);
	}
	return (config);
}
