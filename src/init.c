/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:19:44 by tyamauch          #+#    #+#             */
/*   Updated: 2024/01/11 20:31:09 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_info	*init_share(int argc, char **input)
{
	t_info	*info;

	info = ft_calloc(1, sizeof(t_info));
	if (info == NULL)
	{
		ft_put_error(CALLOC_ERROR);
		return (NULL);
	}
	info->number = ft_atoi(input[1]);
	info->time_die = ft_atoi(input[2]);
	info->time_eat = ft_atoi(input[3]);
	info->time_sleep = ft_atoi(input[4]);
	if (argc == 6)
		info->must_eat = ft_atoi(input[5]);
	else
		info->must_eat = -1;
	return (info);
}

t_philo	*init_philo(t_share *share)
{
	t_philo	*philo;

	philo = ft_calloc(share->number, sizeof(t_philo));
	if (info == NULL)
	{
		ft_put_error(CALLOC_ERROR);
		return (NULL);
	}
	return (philo);
}
