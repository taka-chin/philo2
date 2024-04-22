/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actual_usleep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 22:13:57 by tyamauch          #+#    #+#             */
/*   Updated: 2024/04/22 17:43:41 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long int	diff_time(struct timeval now)
{
	struct timeval	tp;
	long int		log_stime;
	long int		log_utime;

	gettimeofday(&tp, NULL);
	log_stime = (tp.tv_sec - now.tv_sec) * 1000000;
	log_utime = (tp.tv_usec - now.tv_usec);
	return ((log_stime + log_utime) / 1000);
}

void	actual_usleep(long int sleep_time)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	while (diff_time(now) < sleep_time)
		usleep(100);
}
