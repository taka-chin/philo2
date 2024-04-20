/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_log_time.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 22:15:40 by tyamauch          #+#    #+#             */
/*   Updated: 2024/04/20 22:15:42 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	create_log_time(t_philo *philo)
{
	struct timeval	tp;
	long int		log_time;

	gettimeofday(&tp, NULL);
	log_time = (tp.tv_sec - philo->start_time.tv_sec) * 1000000;
	log_time += (tp.tv_usec - philo->start_time.tv_usec);
	log_time /= 1000;
	return (log_time);
}
