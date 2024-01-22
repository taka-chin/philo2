#include "philo.h"

static bool take_fork(t_philo *philo)
{
	bool take_forks ;

	take_forks= false;
	pthread_mutex_lock(&philo->left_fork->mutex_fork);
	put_log(philo, TAKE_FORK);
	if(&philo->left_fork->id != &philo->right_fork->id)
	{
		pthread_mutex_lock(&philo->right_fork->mutex_fork);
		put_log(philo, TAKE_FORK);
		take_forks = true;
	}
	return(take_forks);
}

static void eating(t_philo *philo)
{
		put_log(philo, EAT);
		pthread_mutex_lock(&philo->mutex_philo);
		philo->eat_count++;
		pthread_mutex_unlock(&philo->mutex_philo);
		actual_usleep(philo->share->info->time_eat);
}

static void put_fork(t_philo *philo)
{
		pthread_mutex_unlock(&philo->left_fork->mutex_fork);
		if(&philo->left_fork->id != &philo->right_fork->id)
			pthread_mutex_unlock(&philo->right_fork->mutex_fork);
}

static void sleeping(t_philo *philo)
{
		put_log(philo, SLEEP);
		actual_usleep(philo->share->info->time_sleep);
}

static void thinking(t_philo *philo)
{
		put_log(philo, THINK);
}

void death_game(t_philo *philo)
{
	if (philo->id % 2 == 0)
		actual_usleep(500);
	if(take_fork(philo))
	{
		eating(philo);
		put_fork(philo);
		sleeping(philo);
		thinking(philo);
	}
	else
		put_fork(philo);
}
