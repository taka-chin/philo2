#include "philo.h"

void all_free(t_info *input,pthread_mutex_t *forks,t_philo *philos)
{
				int number;

				number = input->number;
				if(input != NULL)
						free(input);
				if(forks != NULL)
						fork_destory(forks,number);
				if(philos != NULL)
						philo_destory(philos,number);
}
