#include "philo.h"

static void take_fork(t_philo *philo)
{
	put_log(philo,TAKE_FORK);
}

static void eating(t_philo *philo)
{
	put_log(philo,EATING);
}

static void sleeping(t_philo *philo)
{
	put_log(philo,SLEEPING);
}

static void thinking(t_philo *philo)
{
	put_log(philo,THINKING);
}

void *routine(void *arg)
{
	t_philo *philos;
	int eat_count;
	
	philos = (t_philo *)arg;
	eat_count = 0;
	while(true)
	{
		if(finish_check(philos))
			break;
		take_fork(philos);
		take_fork(philos);
		eating(philos);
		sleeping(philos);
		thinking(philos);
	}
	return(NULL);
}

