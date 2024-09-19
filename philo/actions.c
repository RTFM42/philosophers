/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussato <yussato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:23:45 by yussato           #+#    #+#             */
/*   Updated: 2024/09/19 20:29:43 by yussato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	die_check(t_philo *philo)
{
	int	die;

	channel_recv(philo->die, &die);
	return (die);
}

int	take_the_left_fork(int id, long start_at, t_philo *philo)
{
	long	now;
	int		fork_id;

	while (1)
	{
		if (die_check(philo))
			return (1);
		channel_recv(*philo->lfork, &fork_id);
		if (fork_id == 0)
			break ;
		usleep(100);
	}
	channel_send(*philo->lfork, (int []){id});
	now = getms() - start_at;
	if (die_check(philo))
		return (1);
	printf("%ld %d has taken a fork\n", now, id);
	return (0);
}

int	take_the_right_fork(int id, long start_at, t_philo *philo)
{
	long	now;
	int		fork_id;

	while (1)
	{
		if (die_check(philo))
			return (1);
		channel_recv(*philo->rfork, &fork_id);
		if (fork_id == 0)
			break ;
		usleep(100);
	}
	channel_send(*philo->rfork, (int []){id});
	now = getms() - start_at;
	if (die_check(philo))
		return (1);
	printf("%ld %d has taken a fork\n", now, id);
	return (0);
}

int	have_a_meal(t_philo_sub *sub, int *eat)
{
	const long	now = getms();
	int			mst_eat_done;

	if (die_check(&sub->philo))
		return (1);
	printf("%ld %d is eating\n", getms() - sub->start_at, sub->philo.id);
	channel_send(sub->last_meal, (long []){now + sub->philo.config.dur_eat});
	usleep(sub->philo.config.dur_eat * 1000);
	channel_send(sub->last_meal, (long []){now + sub->philo.config.dur_eat});
	channel_send(*sub->philo.lfork, (int []){0});
	channel_send(*sub->philo.rfork, (int []){0});
	if (sub->philo.config.mst_eat > -1 && ++(*eat))
	{
		if (*eat == sub->philo.config.mst_eat)
		{
			channel_recv(sub->philo.mst_eat_done, &mst_eat_done);
			mst_eat_done++;
			channel_send(sub->philo.mst_eat_done, &mst_eat_done);
			if (mst_eat_done == sub->philo.config.num)
				return (channel_send(sub->philo.die,
						(int []){sub->philo.config.num + 2}) * 0 + 1);
		}
	}
	return (0);
}

int	get_sleep(int id, long start_at, t_philo *philo)
{
	long	now;

	now = getms() - start_at;
	if (die_check(philo))
		return (1);
	printf("%ld %d is sleeping\n", now, id);
	usleep(philo->config.dur_slp * 1000);
	if (die_check(philo))
		return (1);
	now = getms() - start_at;
	printf("%ld %d is thinking\n", now, id);
	return (0);
}
