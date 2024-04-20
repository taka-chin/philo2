/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actual_usleep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 22:13:57 by tyamauch          #+#    #+#             */
/*   Updated: 2024/04/20 22:13:59 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	actual_usleep(long int sleep_time)
{
	long int	now;

	now = get_now_time();
	while (get_now_time() - now < sleep_time)
		usleep(100);
}
