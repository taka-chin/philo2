/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 19:26:41 by tyamauch          #+#    #+#             */
/*   Updated: 2024/01/14 02:16:11 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	happy_end(t_philo *philo)
{
	bool	flag;

	flag = false;
	if (is_stuffed(philo))
	{
		pthread_mutex_lock(&philo->share->mutex_share);
		philo->share->finish = true;
		pthread_mutex_unlock(&philo->share->mutex_share);
		flag = true;
	}
	return (flag);
}

static bool	bad_end(t_philo *philo)
{
	bool	flag;

	flag = false;
	if (is_dead(philo))
	{
		pthread_mutex_lock(&philo->share->mutex_share);
		philo->share->finish = true;
		pthread_mutex_unlock(&philo->share->mutex_share);
		flag = true;
	}
	return (flag);
}

void	*observe(t_philo *philo)
{
	while (true)
	{
		if (get_thread_num(philo->share) == -1)
			break ;
		actual_usleep(100);
	}
	while (true)
	{
		if (bad_end(philo) || happy_end(philo))
			break ;
		actual_usleep(100);
	}
	return (NULL);
}
