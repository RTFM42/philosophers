/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:36:16 by yussato           #+#    #+#             */
/*   Updated: 2024/09/22 06:59:53 by yushsato         ###   ########.fr       */
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
		ft_putstr_fd("Invalid arguments.\n", 2);
		return (0);
	}
	return (1);
}

void	*config_err(t_config *config)
{
	free(config);
	ft_putstr_fd("Invalid arguments.\n", 2);
	return (NULL);
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
	if (config->num <= 0 || config->num >= 300 || config->dur_die <= 0
		|| config->dur_eat <= 0 || config->dur_slp <= 0
		|| (ac == 6 && config->mst_eat <= 0))
		return (config_err(config));
	return (config);
}
