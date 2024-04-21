/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:59:23 by tyamauch          #+#    #+#             */
/*   Updated: 2024/04/21 13:16:44 by tyamauch         ###   ########.fr       */
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

pthread_mutex_t	*init_forks(t_info *input)
{
	int				i;
	pthread_mutex_t	*forks;

	i = 0;
	forks = ft_calloc(input->number, sizeof(pthread_mutex_t));
	if (forks == NULL)
	{
		ft_put_error(CALLOC_ERROR);
		return (NULL);
	}
	while (i < input->number)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
		{
			ft_put_error(PTHREAD_ERROR);
			fork_destory(forks, i);
			return (NULL);
		}
		i++;
	}
	return (forks);
}

static bool	set_value(t_info *input, t_philo *philos, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < input->number)
	{
		if (pthread_mutex_init(&philos[i].mutex_philo, NULL) != 0)
		{
			ft_put_error(PTHREAD_ERROR);
			philo_destory(philos, i);
			return (false);
		}
		philos[i].id = i + 1;
		philos[i].eat_count = 0;
		philos[i].active_time = 0;
		philos[i].is_dead = false;
		philos[i].r_fork = &forks[i];
		if (i == input->number - 1)
			philos[i].l_fork = &forks[0];
		else
			philos[i].l_fork = &forks[i + 1];
		philos[i].info = input;
		i++;
	}
	return (true);
}

t_philo	*init_philos(t_info *input, pthread_mutex_t *forks)
{
	int		i;
	t_philo	*philos;

	i = 0;
	philos = ft_calloc(input->number, sizeof(t_philo));
	if (philos == NULL)
	{
		ft_put_error(CALLOC_ERROR);
		return (NULL);
	}
	if (!set_value(input, philos, forks))
		return (NULL);
	return (philos);
}
