/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 19:10:59 by tyamauch          #+#    #+#             */
/*   Updated: 2024/01/06 22:41:53 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pthreads_join(t_philo *philo)
{
	t_philo	*p;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	/* printf("debug pthread_join\n"); */
	while (i < philo->share->info->number)
	{
		p = &philo[i];
		ret = pthread_join(p->thread, NULL);
		printf("ret is %d\n",ret);
		i++;
	}
}

void	pthreads_create(t_philo *philo)
{
	t_philo	*philo_p;
	int		i;

	i = 0;
	while (i < philo->share->info->number)
	{
		philo_p = &philo[i++];
		pthread_create(&philo_p->thread, NULL, dead_or_alive, philo_p);
	}
	pthread_mutex_lock(&philo->share->mutex_share);
	philo->share->thread_num = -1;
	gettimeofday(&philo->share->start_time, NULL);
	pthread_mutex_unlock(&philo->share->mutex_share);
	observe(philo);
}
