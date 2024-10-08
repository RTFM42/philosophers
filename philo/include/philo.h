/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:28:28 by yushsato          #+#    #+#             */
/*   Updated: 2024/09/22 16:28:29 by yushsato         ###   ########.fr       */
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
	int			id;
	long		start_at;
	t_config	config;
	t_channel	*lfork;
	t_channel	*rfork;
	t_channel	die;
	t_channel	mst_eat_done;
}	t_philo;

typedef struct s_philo_sub
{
	t_philo		philo;
	long		start_at;
	t_channel	last_meal;
}	t_philo_sub;

long		getms(void);
t_config	*config_create(int ac, char *av[]);
t_channel	*forks_create(int num);
void		forks_destroy(t_channel *forks, int num);
pthread_t	*philos_create(int num);
pthread_t	*philos_destroy(pthread_t *threads);
t_philo		*philos_data_create(
				t_config *cfg, t_channel die, t_channel mst_eat_done);
t_philo		*philos_data_destroy(t_philo *philos);
int			start(t_config *cfg);
int			get_sleep(int id, long start_at, t_philo *philo);
int			have_a_meal(t_philo_sub *sub, int *eat);
int			take_the_right_fork(int id, long start_at, t_philo *philo);
int			take_the_left_fork(int id, long start_at, t_philo *philo);
int			die_check(t_philo *philo);

#endif
