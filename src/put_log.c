/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_log.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:20:53 by tyamauch          #+#    #+#             */
/*   Updated: 2024/04/21 13:44:39 by tyamauch         ###   ########.fr       */
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
			printf("%ld %d has taken a fork\n", log_time, philo->id);
		else if (e_action_type == EATING)
			printf("%ld %d is eating\n", log_time, philo->id);
		else if (e_action_type == SLEEPING)
			printf("%ld %d is sleeping\n", log_time, philo->id);
		else if (e_action_type == THINKING)
			printf("%ld %d is thinking\n", log_time, philo->id);
		else if (e_action_type == DIED)
		{
			if (!died_flag)
				printf("%ld %d is died\n", log_time, philo->id);
			died_flag = true;
		}
	}
	pthread_mutex_unlock(&put_lock);
}
