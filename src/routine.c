/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 22:10:39 by tyamauch          #+#    #+#             */
/*   Updated: 2024/04/23 15:35:07 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	take_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
		pthread_mutex_lock(philo->r_fork);
	else
		pthread_mutex_lock(philo->l_fork);
	put_log(philo, TAKE_FORK);
	if (philo->r_fork == philo->l_fork)
	{
		pthread_mutex_unlock(philo->r_fork);
		return (false);
	}
	if (philo->id % 2 == 0)
		pthread_mutex_lock(philo->l_fork);
	else
		pthread_mutex_lock(philo->r_fork);
	put_log(philo, TAKE_FORK);
	return (true);
}

static void	eating(t_philo *philo)
{
	put_log(philo, EATING);
	pthread_mutex_lock(&philo->mutex_philo);
	gettimeofday(&philo->active_time, NULL);
	philo->eat_count++;
	pthread_mutex_unlock(&philo->mutex_philo);
	actual_usleep(philo->info->time_eat);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

static void	sleeping(t_philo *philo)
{
	put_log(philo, SLEEPING);
	actual_usleep(philo->info->time_sleep);
}

static void	thinking(t_philo *philo)
{
	put_log(philo, THINKING);
}

void	*routine(void *arg)
{
	t_philo	*philos;

	philos = (t_philo *)arg;
	if (philos->id % 2 == 0)
		usleep(10);
	while (true)
	{
		pthread_mutex_lock(&philos->mutex_philo);
		if (philos->is_dead)
		{
			pthread_mutex_unlock(&philos->mutex_philo);
			break ;
		}
		pthread_mutex_unlock(&philos->mutex_philo);
		if (!take_fork(philos))
			break ;
		eating(philos);
		sleeping(philos);
		thinking(philos);
		usleep(1000);
	}
	return (NULL);
}
