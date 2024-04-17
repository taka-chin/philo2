#include "philo.h"

void *routine(void *arg)
{
	t_philo *philos;
	
	philos = (t_philo *)arg;

	printf("routine\n");
	return(NULL);
}
