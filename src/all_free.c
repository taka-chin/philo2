#include "philo.h"

void all_free(t_info *input,pthread_mutex_t *forks)
{
				int number;

				number = input->number;
				if(input != NULL)
						free(input);
				if(forks != NULL)
						fork_destory(forks,number);
}
