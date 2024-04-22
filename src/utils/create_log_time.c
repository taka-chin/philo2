/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_log_time.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 22:15:40 by tyamauch          #+#    #+#             */
/*   Updated: 2024/04/22 19:03:59 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	create_log_time(t_philo *philo)
{
	struct timeval	tp;
	long long		log_stime;
	long long		log_utime;

	gettimeofday(&tp, NULL);
	log_stime = (tp.tv_sec - philo->start_time.tv_sec) * 1000000;
	log_utime = (tp.tv_usec - philo->start_time.tv_usec);
	return ((log_stime + log_utime) / 1000);
}
