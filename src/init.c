#include "philo.h"

t_info *init_info(int argc ,char **input)
{
	t_info *info;

	info = ft_calloc(1,sizeof(t_info));
	if(info == NULL)
	{
			ft_put_error(CALLOC_ERROR);
			return(NULL);
	}
	info -> number = ft_atoi(input[1]);
	info -> time_die = ft_atoi(input[2]);
	info -> time_eat = ft_atoi(input[3]);
	info -> time_sleep = ft_atoi(input[4]);
	if(argc == 6)
			info -> must_eat = ft_atoi(input[5]);
	else
			info -> must_eat = -1;
	return(info);
}
