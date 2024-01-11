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

t_info	*init_info(int argc, char **input)
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

t_fork	*init_fork(t_info *input)
{
	t_fork	*fork;
	t_fork	*fork_p;
	int		i;

	i = 0;
	fork = ft_calloc(input->number, sizeof(t_fork));
	if (fork == NULL)
	{
		ft_put_error(CALLOC_ERROR);
		return (NULL);
	}
	while (i < input->number)
	{
		fork_p = &fork[i];
		if (pthread_mutex_init(&fork_p->mutex_fork, NULL) != 0)
		{
			fork_destory(fork, i);
			return (NULL);
		}
		i++;
	}
	return (fork);
}

t_share	*init_share(t_info *input)
{
	t_share	*share;

	share = ft_calloc(1, sizeof(t_share));
	if (share == NULL)
	{
		ft_put_error(CALLOC_ERROR);
		return (NULL);
	}
	if (pthread_mutex_init(&share->mutex_share, NULL) != 0)
	{
		share_destory(share);
		return (NULL);
	}
	share->thread_num = 1;
	share->info = input;
	return (share);
}

static bool	set_philo_value(int number, t_fork *fork, t_share *share,
		t_philo *philo)
{
	t_philo	*philo_p;
	int		i;

	i = 0;
	while (i < number)
	{
		philo_p = &philo[i];
		if (pthread_mutex_init(&philo_p->mutex_philo, NULL) != 0)
		{
			philo_destory(philo, i);
			return (false);
		}
		philo[i].id = i + 1;
		philo[i].share = share;
		if(i != number - 1)
		{
			philo[i].left_fork = &fork[i];
			if(i == 0 && number != 1)
				philo[i].right_fork = &fork[number - 1];
		}
		i++;
	}
	return (true);
}

t_philo	*init_philo(t_info *input, t_fork *fork, t_share *share)
{
	int		number;
	t_philo	*philo;

	number = input->number;
	philo = ft_calloc(number, sizeof(t_philo));
	if (philo == NULL)
	{
		ft_put_error(CALLOC_ERROR);
		return (NULL);
	}
	set_philo_value(number, fork, share, philo);
	return (philo);
}
