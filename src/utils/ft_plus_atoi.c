/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:26:42 by tyamauch          #+#    #+#             */
/*   Updated: 2024/04/22 17:22:27 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	over_flow_check(int num, int check, const char *s)
{
	long long	ov_div;
	long long	ov_mod;

	ov_div = INT_MAX / 10;
	ov_mod = INT_MAX % 10;
	if (check == -1)
		ov_mod += 1;
	if (num > ov_div)
		return (1);
	else if (num == ov_div && ov_mod < (*s - '0'))
		return (1);
	return (0);
}

int	ft_plus_atoi(const char *str)
{
	int			check;
	long long	num;

	num = 0;
	check = 1;
	while (('\t' <= *str && *str <= '\r') || (*str == ' '))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			check = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		if (over_flow_check(num, check, str) && check == 1)
			return (-1);
		if (over_flow_check(num, check, str) && check == -1)
			return ((int)LLONG_MIN);
		num = num * 10 + (*str - '0');
		str++;
	}
	num *= check;
	return (num);
}
