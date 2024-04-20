/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:58:29 by tyamauch          #+#    #+#             */
/*   Updated: 2024/04/20 20:58:49 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	p_create(t_philo *philos)
{
	int		i;
	t_philo	*p;

	i = 0;
	while (i < philos->info->number)
	{
		p = &philos[i++];
		gettimeofday(&p->start_time, NULL);
		p->active_time = get_now_time();
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
		p = &philos[i++];
		pthread_join(p->thread, NULL);
		i++;
	}
}

void	dining_philo(t_philo *philos)
{
	p_create(philos);
}
