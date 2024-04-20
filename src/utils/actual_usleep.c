#include "philo.h"

void actual_usleep(long int sleep_time)
{
	long int  now;

	now = get_now_time();
	while(get_now_time() - now < sleep_time)
		usleep(100);
}
