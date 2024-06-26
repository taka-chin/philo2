/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 22:14:41 by tyamauch          #+#    #+#             */
/*   Updated: 2024/04/22 16:57:19 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_put_error(int e_error_type)
{
	if (e_error_type == ARGS_ERROR)
		write(2, "invaild args\n", 14);
	else if (e_error_type == CALLOC_ERROR)
		write(2, "calloc error\n", 14);
	else if (e_error_type == PTHREAD_ERROR)
		write(2, "pthread error\n", 15);
	else if (e_error_type == OVER_FLOW_ERROR)
		write(2, "overflow error\n", 16);
}
