/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:54:32 by tyamauch          #+#    #+#             */
/*   Updated: 2024/04/20 20:54:35 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	all_free(t_info *input, pthread_mutex_t *forks, t_philo *philos)
{
	int	number;

	number = input->number;
	if (input != NULL)
		free(input);
	if (forks != NULL)
		fork_destory(forks, number);
	if (philos != NULL)
		philo_destory(philos, number);
}
