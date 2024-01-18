
#include "philo.h"

int	get_thread_num(t_share *share)
{
	int	thread_num;

	pthread_mutex_lock(&share->mutex_share);
	thread_num = share->thread_num;
	pthread_mutex_unlock(&share->mutex_share);
	return (thread_num);
}
