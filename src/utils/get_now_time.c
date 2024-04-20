/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_now_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 22:16:08 by tyamauch          #+#    #+#             */
/*   Updated: 2024/04/20 22:16:37 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	get_now_time(void)
{
	struct timeval	tp;
	long int		now_time;

	gettimeofday(&tp, NULL);
	now_time = tp.tv_sec * 1000000;
	now_time += tp.tv_usec ;
	now_time = now_time / 1000;
	return (now_time);
}
