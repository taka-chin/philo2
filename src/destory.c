/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 22:19:39 by tyamauch          #+#    #+#             */
/*   Updated: 2024/04/20 22:20:01 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fork_destory(pthread_mutex_t *forks, int i)
{
	while (--i)
	{
		pthread_mutex_destroy(&forks[i]);
	}
	free(forks);
}

void	philo_destory(t_philo *philos, int i)
{
	while (--i)
	{
		pthread_mutex_destroy(&philos[i].mutex_philo);
	}
	free(philos);
}
