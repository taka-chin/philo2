#include "philo.h"

static void waiting(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork->mutex_fork);
	put_log(philo, BEFORE_EAT);
	if(philo->share->info->number != 1)
	{
		pthread_mutex_lock(&philo->right_fork->mutex_fork);
		put_log(philo, BEFORE_EAT);
	}
	/* pthread_mutex_unlock(&philo->left_fork->mutex_fork); */
}

static void eating(t_philo *philo)
{
		put_log(philo, EAT);
		pthread_mutex_lock(&philo->mutex_philo);
		philo->eat_count++;
		pthread_mutex_unlock(&philo->mutex_philo);
		usleep(philo->share->info->time_eat * 1000);
		pthread_mutex_unlock(&philo->left_fork->mutex_fork);
		if(philo->share->info->number != 1)
			pthread_mutex_unlock(&philo->right_fork->mutex_fork);
}

static void sleeping(t_philo *philo)
{
		put_log(philo, SLEEP);
		usleep(philo->share->info->time_sleep * 1000);
}

static void thinking(t_philo *philo)
{
		put_log(philo, THINK);
}

void death_game(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep(5000);
	waiting(philo);
	eating(philo);
	sleeping(philo);
	thinking(philo);
}
