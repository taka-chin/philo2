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
		printf("\033[31m%ld %d died\033[0m\n", log_time, philo->id);
	else if (e_state == TAKE_FORK)
		printf("\033[32m%ld %d has taken a fork\033[0m\n", log_time, philo->id);
	else if (e_state == EAT)
	{
		pthread_mutex_lock(&philo->mutex_philo);
		printf("\033[31m%d %p\033[0m\n",philo->left_fork->id,&philo->left_fork);
		printf("\033[31m%d %p\033[0m\n",philo->right_fork->id,&philo->right_fork); 
		philo->active_time = log_time;
		pthread_mutex_unlock(&philo->mutex_philo);
		printf("\033[34m%ld %d is eating\033[0m\n", log_time, philo->id);
	}
	else if (e_state == SLEEP)
		printf("\033[34m%ld %d is sleeping\033[0m\n", log_time, philo->id);
	else if (e_state == THINK)
		printf("\033[34m%ld %d is thinking\033[0m\n", log_time, philo->id);
}
