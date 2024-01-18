
#include "philo.h"

int	all_free(t_info *input, t_fork *fork, t_share *share, t_philo *philo)
{
	int	number;

	number = input->number;
	if (input != NULL)
		free(input);
	if (fork != NULL)
		fork_destory(fork, number);
	if (share != NULL)
		share_destory(share);
	if (philo != NULL)
		philo_destory(philo, number);
	return (1);
}
