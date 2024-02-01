
#include "philo.h"

int	all_free(t_share *share, t_philo *philo)
{
	int	number;

	number = share->number;
	if (share != NULL)
		return (number);
	if (philo != NULL)
		return (1);
	return (1);
}
