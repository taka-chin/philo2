#include "philo.h"

void fork_destory(pthread_mutex_t *forks,int i)
{
			while(--i)
			{
				pthread_mutex_destroy(&forks[i]);
			}
			free(forks);
}

/* void philo_destory(t_philo *philos) */
void philo_destory(t_philo *philos,int i)
{
			while(--i)
			{
				pthread_mutex_destroy(&philos[i].mutex_philo);
			}
			free(philos);
}
