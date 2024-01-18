
#include "philo.h"

void actual_usleep(long int sleep_time)
{
	while(get_now_time() < sleep_time)
		usleep(500);
}
