/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:18:24 by tyamauch          #+#    #+#             */
/*   Updated: 2024/01/06 20:13:00 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fork_destory(t_fork *fork, int i)
{
	while (--i)
	{
		pthread_mutex_destroy(&(fork[i].mutex_fork));
	}
	free(fork);
}

void	share_destory(t_share *share)
{
	pthread_mutex_destroy(&share -> mutex_finish);
	free(share);
}

void	philo_destory(t_philo *philo, int i)
{
	while (--i)
	{
		pthread_mutex_destroy(&(philo[i].mutex_philo));
	}
	free(philo);
}
