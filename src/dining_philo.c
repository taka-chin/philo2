/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:58:29 by tyamauch          #+#    #+#             */
/*   Updated: 2024/04/22 18:51:19 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	p_create(t_philo *philos)
{
	int				i;
	t_philo			*p;
	struct timeval	base_time;

	i = 0;
	gettimeofday(&base_time, NULL);
	while (i < philos->info->number)
	{
		p = &philos[i++];
		p->start_time.tv_sec = base_time.tv_sec;
		p->start_time.tv_usec = base_time.tv_usec;
		p->active_time.tv_sec = base_time.tv_sec;
		p->active_time.tv_usec = base_time.tv_usec;
		pthread_create(&p->thread, NULL, routine, p);
	}
}

void	p_join(t_philo *philos)
{
	int		i;
	t_philo	*p;

	i = 0;
	while (i < philos->info->number)
	{
		p = &philos[i];
		pthread_join(p->thread, NULL);
		i++;
	}
}

void	dining_philo(t_philo *philos)
{
	p_create(philos);
}
