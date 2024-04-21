/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_log.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:20:53 by tyamauch          #+#    #+#             */
/*   Updated: 2024/04/21 13:25:18 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	put_log(t_philo *philo, int e_action_type)
{
	long int				log_time;
	static int				died_flag = false;
	static pthread_mutex_t	put_lock = PTHREAD_MUTEX_INITIALIZER;

	pthread_mutex_lock(&put_lock);
	if (!died_flag)
	{
		log_time = create_log_time(philo);
		if (e_action_type == TAKE_FORK)
			printf("\033[31m%ld %d has taken a fork\033[0m\n", log_time, philo->id);
		else if (e_action_type == EATING)
			printf("\033[32m%ld %d is eating\033[0m\n", log_time, philo->id);
		else if (e_action_type == SLEEPING)
			printf("\033[33m%ld %d is sleeping\033[0m\n", log_time, philo->id);
		else if (e_action_type == THINKING)
			printf("\033[34m%ld %d is thinking\033[0m\n", log_time, philo->id);
		else if (e_action_type == DIED)
		{
			if (!died_flag)
				printf("\033[35m%ld %d is died\033[0m\n", log_time, philo->id);
			died_flag = true;
		}
	}
	pthread_mutex_unlock(&put_lock);
}
