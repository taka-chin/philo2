#include "philo.h"

void actual_usleep(long int sleep_time)
{
	long int  now;

	now = get_now_time();
	while(get_now_time() - now < sleep_time)
		usleep(100);
		/* usleep(sleep_time); */
	/* while(1) */
	/* { */
	/* 	diff = get_now_time() - now; */
	/* 	/1* printf("diff :%ld\n",diff); *1/ */
	/* 	if(diff > sleep_time) */
	/* 		break; */
	/* 	usleep(100); */
	/* } */
}
