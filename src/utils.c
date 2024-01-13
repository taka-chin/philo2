/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:31:19 by tyamauch          #+#    #+#             */
/*   Updated: 2024/01/14 02:11:56 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_thread_num(t_share *share)
{
	int	thread_num;

	pthread_mutex_lock(&share->mutex_share);
	thread_num = share->thread_num;
	pthread_mutex_unlock(&share->mutex_share);
	return (thread_num);
}

long int	create_time(t_philo *philo)
{
	struct timeval	tp;
	long int		log_time;

	gettimeofday(&tp, NULL);
	log_time = (tp.tv_sec - philo->share->start_time.tv_sec) * 1000000;
	log_time += (tp.tv_usec - philo->share->start_time.tv_usec);
	log_time /= 1000;
	return (log_time);
}

void actual_usleep(long int sleep_time)
{
	long int  now;

	now = create_time()
	while(create_time() - now < sleep_time)
		usleep(500);
}

int	all_free(t_info *input, t_fork *fork, t_share *share, t_philo *philo)
{
	int	number;

	number = input->number;
	if (input != NULL)
		free(input);
	if (fork != NULL)
		fork_destory(fork, number);
	if (share != NULL)
		share_destory(share);
	if (philo != NULL)
		philo_destory(philo, number);
	return (1);
}
