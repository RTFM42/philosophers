/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussato <yussato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:23:04 by yussato           #+#    #+#             */
/*   Updated: 2024/09/18 00:18:40 by yussato          ###   ########.fr       */
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
# include "lib.h"

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
	long			start_at;
	t_config		config;
	pthread_mutex_t	*lfork;
	pthread_mutex_t	*rfork;
	t_channel		die;
}	t_philo;

typedef struct s_philo_sub
{
	t_philo		philo;
	long		start_at;
	t_channel	*last_meal;
}	t_philo_sub;

long			getms(void);
t_config		*config_create(int ac, char *av[]);
pthread_mutex_t	*forks_create(int num);
void			forks_destroy(pthread_mutex_t *forks, int num);
pthread_t		*philos_create(int num);
pthread_t		*philos_destroy(pthread_t *threads);
t_philo			*philos_data_create(t_config *cfg, t_channel *die);
t_philo			*philos_data_destroy(t_philo *philos);
int				start(t_config *cfg);

#endif
