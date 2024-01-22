
#include "philo.h"

void actual_usleep(long int sleep_time)
{
	/* long int		start_time; */

	/* start_time = get_now_time(); */
	/* while(get_now_time() - start_time < sleep_time) */
	/* 				; */
	usleep(sleep_time * 1000);
}
