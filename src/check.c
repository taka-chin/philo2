/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:55:31 by tyamauch          #+#    #+#             */
/*   Updated: 2024/04/21 15:37:26 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	input_check(int argc, char **argv)
{
	const char	*str;

	if ((argc < 5 || argc > 6 || *argv[1] == '0')
		|| (argc == 6 && *argv[5] == '0'))
	{
		ft_put_error(ARGS_ERROR);
		return (false);
	}
	while (*++argv)
	{
		str = *argv;
		while (*str)
		{
			if (!ft_isdigit(*str))
			{
				ft_put_error(ARGS_ERROR);
				return (false);
			}
			str++;
		}
	}
	return (true);
}

static bool	is_hunger(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->info->number)
	{
		pthread_mutex_lock(&philos[i].mutex_philo);
		if (get_now_time() - philos[i].active_time > philos->info->time_die)
		{
			pthread_mutex_unlock(&philos[i].mutex_philo);
			put_log(&philos[i], DIED);
			return (true);
		}
		pthread_mutex_unlock(&philos[i].mutex_philo);
		i++;
	}
	return (false);
}

static bool	is_satiety(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->info->number)
	{
		pthread_mutex_lock(&philos[i].mutex_philo);
		if (philos[i].eat_count < philos->info->must_eat)
		{
			pthread_mutex_unlock(&philos[i].mutex_philo);
			return (false);
		}
		pthread_mutex_unlock(&philos[i].mutex_philo);
		i++;
	}
	return (true);
}

bool	finish_check(t_philo *philos)
{
	if (philos->info->must_eat == -1)
	{
		if (is_hunger(philos))
			return (true);
		else
			return (false);
	}
	else
	{
		if (is_hunger(philos) || is_satiety(philos))
			return (true);
		else
			return (false);
	}
}
