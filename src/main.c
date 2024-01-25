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
	t_share	*share;
	t_philo	*philo;

	if (!input_check(argc, argv))
		return (ERROR);
	share = init_share(argc, argv);
	if (!share)
		return (ERROR);
	philo = init_philo(share);
	if (!philo)
		return (all_free(share, NULL));
	return (SUCCESS);
}
