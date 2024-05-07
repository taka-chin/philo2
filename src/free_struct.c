#include "philo.h"

void *free_share(t_share *share)
{
		free(share);	
		return(NULL);
}

void *free_all_struct(t_philo *philo)
{
		int number;
		int i;
		
		number = philo->share->number;
		i = 0;
		free_share(philo->share);		
		while(i < number)
		{
			free(&philo[i]);
			i++;
		}
		return(NULL);
}
