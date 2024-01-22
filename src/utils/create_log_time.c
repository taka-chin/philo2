
#include "philo.h"

long int	create_log_time(t_philo *philo)
{
	struct timeval	tp;
	long int		log_time;

	gettimeofday(&tp, NULL);
	log_time = (tp.tv_sec - philo->share->start_time.tv_sec) * 1000000;
	log_time += (tp.tv_usec - philo->share->start_time.tv_usec) ;
	log_time /= 1000;
	return (log_time);
}
