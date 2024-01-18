/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 19:26:29 by tyamauch          #+#    #+#             */
/*   Updated: 2024/01/14 02:15:04 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	put_log(t_philo *philo, int e_state)
{
	long int	log_time;
	bool		fin_flag;

	log_time = create_time(philo);
	pthread_mutex_lock(&philo->share->mutex_share);
	fin_flag = philo->share->finish;
	pthread_mutex_unlock(&philo->share->mutex_share);
	if (fin_flag)
		return ;
	else if (e_state == DIED)
		printf("%ld %d died\n", log_time, philo->id);
	else if (e_state == BEFORE_EAT)
		printf("%ld %d has taken a fork\n", log_time, philo->id);
	else if (e_state == EAT)
	{
		pthread_mutex_lock(&philo->mutex_philo);
		printf("%d %p\n",philo->left_fork->id,&philo->left_fork);
		printf("%d %p\n",philo->right_fork->id,&philo->right_fork); 
		philo->active_time = log_time;
		pthread_mutex_unlock(&philo->mutex_philo);
		printf("%ld %d is eating\n", log_time, philo->id);
	}
	else if (e_state == SLEEP)
		printf("%ld %d is sleeping\n", log_time, philo->id);
	else if (e_state == THINK)
		printf("%ld %d is thinking\n", log_time, philo->id);
}
