#include "philo.h"

static void take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	put_log(philo,TAKE_FORK);
	pthread_mutex_lock(philo->l_fork);
	put_log(philo,TAKE_FORK);
}

static void eating(t_philo *philo)
{
	put_log(philo,EATING);
	pthread_mutex_lock(&philo->mutex_philo);
	philo->active_time = get_now_time(); 
	philo->eat_count++;
	pthread_mutex_unlock(&philo->mutex_philo);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	usleep(philo->info->time_eat *1000);
}

static void sleeping(t_philo *philo)
{
	put_log(philo,SLEEPING);
	usleep(philo->info->time_sleep *1000);
}

static void thinking(t_philo *philo)
{
	put_log(philo,THINKING);
}

void *routine(void *arg)
{
	t_philo *philos;
	
	philos = (t_philo *)arg;
	if(philos->id %2 == 0)
		usleep(1000);
	while(true)
	{
		/* if(finish_check(philos)) */
		/* 	break; */
		take_fork(philos);
		eating(philos);
		sleeping(philos);
		thinking(philos);
	}
	return(NULL);
}

