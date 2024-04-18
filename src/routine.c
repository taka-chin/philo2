#include "philo.h"

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
		/* mutex lock */
		eat_count++;
		/* mutex unlock*/
		printf("routine\n");
	}
	return(NULL);
}
