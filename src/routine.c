#include "philo.h"

static void take_fork(t_philo *philo)
{
	if(philo->id % 2 == 0)
		pthread_mutex_lock(philo->r_fork);
	else
		pthread_mutex_lock(philo->l_fork);
	put_log(philo,TAKE_FORK);
	if(philo->r_fork == philo->l_fork)
	{
		pthread_mutex_unlock(philo->r_fork);
		exit(1);
	}
	if(philo->id % 2 == 0)
		pthread_mutex_lock(philo->l_fork);
	else
		pthread_mutex_lock(philo->r_fork);
	put_log(philo,TAKE_FORK);
}

static void eating(t_philo *philo)
{
	put_log(philo,EATING);
	actual_usleep(philo->info->time_eat );
	pthread_mutex_lock(&philo->mutex_philo);
	philo->active_time = get_now_time(); 
	philo->eat_count++;
	pthread_mutex_unlock(&philo->mutex_philo);
	/* if(philo->id % 2 == 0) */
	/* { */
	/* 	pthread_mutex_unlock(philo->r_fork); */
	/* 	pthread_mutex_unlock(philo->l_fork); */
	/* } */
	/* else */
	/* { */
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
	/* } */
}

static void sleeping(t_philo *philo)
{
	put_log(philo,SLEEPING);
	actual_usleep(philo->info->time_sleep );
}

static void thinking(t_philo *philo)
{
	put_log(philo,THINKING);
}

void *routine(void *arg)
{
	t_philo *philos;
	
	philos = (t_philo *)arg;
	/* if(philos->id %2 == 0) */
	/* 	actual_usleep(1); */
	while(true)
	{
		if(philos->is_dead)
			break;
		take_fork(philos);
		eating(philos);
		sleeping(philos);
		thinking(philos);
	}
	return(NULL);
}

