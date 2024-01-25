/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:42:27 by tyamauch          #+#    #+#             */
/*   Updated: 2024/01/07 17:44:13 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/philo.h"

/* コマンドライン引数をチェックする関数 */
/* 受け取る引数は、以下の通り */
/* 1. 哲学者の数 1以上*/
/* 2. 死亡までの時間 (miliseconds)*/
/* 3. 食事を終えるまでの時間 (miliseconds)*/	
/* 4. 睡眠を終えるまでの時間 (miliseconds)*/	
/* 5. 必要な食事の回数（任意） */	

bool	input_check(int argc, char **input)
{
	const char	*str;

	if (argc < 5 || argc >= 7 || *input[1] == '0')
	{
		ft_put_error(ARGS_ERROR);
		return (false);
	}
	while (*++input)
	{
		str = *input;
		if (str[0] == '+')
			str++;
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
