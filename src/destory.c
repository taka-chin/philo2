#include "philo.h"

void fork_destory(pthread_mutex_t *forks,int i)
{
			while(--i)
			{
				pthread_mutex_destroy(&forks[i]);
			}
			free(forks);
}

/* void philo_destory(t_philo *philos,int i) */
void philo_destory(t_philo *philos)
{
			/* while(--i) */
			/* { */
			/* 	pthread_mutex_destroy(&forks[i]); */
			/* } */
			free(philos);
}
