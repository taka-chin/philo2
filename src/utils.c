/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:31:19 by tyamauch          #+#    #+#             */
/*   Updated: 2024/01/06 20:14:04 by tyamauch         ###   ########.fr       */
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
