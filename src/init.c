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

t_share	*init_share(int argc, char **input)
{
	t_share	*share;

	share = ft_calloc(1, sizeof(t_share));
	if (share == NULL)
	{
		ft_put_error(CALLOC_ERROR);
		return (NULL);
	}
	share->number = ft_atoi(input[1]);
	share->time_die = ft_atoi(input[2]);
	share->time_eat = ft_atoi(input[3]);
	share->time_sleep = ft_atoi(input[4]);
	if (argc == 6)
		share->must_eat = ft_atoi(input[5]);
	else
		share->must_eat = -1;
	return (share);
}

static bool init_forks(t_philo *philo)
{
	int	i;
	int	number;
	pthread_mutex_t	*forks;

	i = 0;
	number = philo->share->number;
	forks = ft_calloc(number, sizeof(pthread_mutex_t));
	if (forks == NULL)
	{
		ft_put_error(CALLOC_ERROR);
		return (false);
	}
	while (i < number)
	{
		philo[i].right_fork = &forks[i];
		philo[i].left_fork = &forks[(i + 1) % number];
		i++;
	}
	return (true);
}

t_philo	*init_philo(t_share *share)
{
	t_philo	*philo;
	int i;

	philo = ft_calloc(share->number, sizeof(t_philo));
	i = 0;
	if (philo == NULL)
	{
		ft_put_error(CALLOC_ERROR);
		return (NULL);
	}
	while(i < share->number)
	{
		philo[i]->share = share;
		if(pthread_mutex_init(philo[i]->mutex_read, NULL) !=0)
						return(NULL);
		if(pthread_mutex_init(philo[i]->mutex_write, NULL) !=0)
						return(NULL);
		i++;
	}
	if(!init_forks(philo))
		return (NULL);
	return (philo);
}
