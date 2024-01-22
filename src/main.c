/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:23:20 by tyamauch          #+#    #+#             */
/*   Updated: 2024/01/06 20:13:35 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char *argv[])
{
	t_info	*input;
	t_fork	*fork;
	t_share	*share;
	t_philo	*philo;

	if (!input_check(argc, argv))
		return (ERROR);
	input = init_info(argc, argv);
	if (!input)
		return (ERROR);
	fork = init_fork(input);
	if (!fork)
		return (all_free(input, NULL, NULL, NULL));
	share = init_share(input);
	if (!share)
		return (all_free(input, fork, NULL, NULL));
	philo = init_philo(input, fork, share);
	if (!philo)
		return (all_free(input, fork, share, NULL));
	pthreads_create(philo);
	pthreads_join(philo);
	all_free(input, fork, share, philo);
	return (0);
}
