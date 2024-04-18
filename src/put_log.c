#include "philo.h"

void put_log(t_philo *philo,int e_action_type)
{
	long int log_time;

	log_time = create_log_time(philo);
	if(e_action_type == TAKE_FORK)
		printf("\033[31m%ld %d has taken a fork\033[0m\n", log_time, philo->id);
	else if(e_action_type == EATING)
		printf("\033[32m%ld %d is eating\033[0m\n", log_time, philo->id);
	else if(e_action_type == SLEEPING)
		printf("\033[33m%ld %d is sleeping\033[0m\n", log_time, philo->id);
	else if(e_action_type == THINKING)
		printf("\033[34m%ld %d is thinking\033[0m\n", log_time, philo->id);
}
