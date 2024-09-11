/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussato <yussato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:23:04 by yussato           #+#    #+#             */
/*   Updated: 2024/09/11 19:03:21 by yussato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>
# include "channel.h"

typedef struct s_config
{
	int	num;
	int	dur_die;
	int	dur_eat;
	int	dur_slp;
	int	mst_eat;
}	t_config;

typedef struct s_philo
{
	int				id;
	t_config		config;
	pthread_mutex_t	*lfork;
	pthread_mutex_t	*rfork;
	pthread_mutex_t	*state_mutex;
	int				*state;
}	t_philo;

int			ft_atoi(const char *str);
void		ft_putstr_fd(const char *str, int fd);
size_t		ft_strlen(const char *str);

long		getms(void);

t_config	*config_create(int ac, char *av[]);

#endif
