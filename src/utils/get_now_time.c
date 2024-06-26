/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_now_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 22:16:08 by tyamauch          #+#    #+#             */
/*   Updated: 2024/04/22 19:04:15 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	get_now_time(void)
{
	struct timeval	tp;
	long long		now_stime;
	long long		now_utime;

	gettimeofday(&tp, NULL);
	now_stime = tp.tv_sec * 1000000;
	now_utime = tp.tv_usec;
	return ((now_stime + now_utime) / 1000);
}
