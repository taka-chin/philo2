/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 19:26:18 by tyamauch          #+#    #+#             */
/*   Updated: 2024/01/06 19:26:21 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_put_error(int e_error_type)
{
	if (e_error_type == ARGS_ERROR)
		write(2, "invaild args\n", 13);
	else if (e_error_type == CALLOC_ERROR)
		write(2, "calloc error\n", 13);
	else if (e_error_type == PTHREAD_ERROR)
		write(2, "pthreads error\n", 15);
}
