/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_now_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 22:16:08 by tyamauch          #+#    #+#             */
/*   Updated: 2024/04/21 17:14:18 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	get_now_time(void)
{
	struct timeval	tp;
	long int		now_time;

	gettimeofday(&tp, NULL);
	now_time = tp.tv_sec * 1000;
	now_time += tp.tv_usec / 1000;
	return (now_time);
}
