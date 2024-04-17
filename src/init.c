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

pthread_mutex_t *init_forks(t_info *input)
{
				int i;
				pthread_mutex_t *forks;

				i = 0;
				forks = ft_calloc(input->number,sizeof(pthread_mutex_t));
				if(forks == NULL)
				{
						ft_put_error(CALLOC_ERROR);
						return(NULL);
				}
				while(i < input->number)
				{
							if(pthread_mutex_init(&forks[i],NULL)!= 0)
							{
									fork_destory(forks,i);
									return(NULL);
							}
							i++;
				}
				return(forks);
}
