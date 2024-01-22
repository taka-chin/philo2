
#include "philo.h"

long int get_now_time()
{
	struct timeval	tp;
	long int		now_time;

	gettimeofday(&tp, NULL);
	now_time = tp.tv_sec * 1000;
	now_time += tp.tv_usec /1000;
	return(now_time);
}
