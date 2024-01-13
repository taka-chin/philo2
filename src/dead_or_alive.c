/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_or_alive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 19:27:28 by tyamauch          #+#    #+#             */
/*   Updated: 2024/01/14 02:19:32 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*dead_or_alive(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (true)
	{
		if (get_thread_num(philo->share) == -1)
			break ;
		actual_usleep(100);
	}
	put_log(philo, THINK);
	while (true)
	{
		if (check_finish(philo))
			break ;
		death_game(philo);
	}
	return (NULL);
}
