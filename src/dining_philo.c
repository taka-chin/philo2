#include "philo.h"

static void p_create(t_philo *philos)
{
	int i;
	t_philo *p;

	i  = 0;
	while(i < philos->info->number)
	{
		p = &philos[i++];
		gettimeofday(&p->start_time,NULL); 
		/* p->active_time = get_now_time(); */ 
		p->active_time = (p->start_time.tv_sec * 1000 + p->start_time.tv_usec /1000); 
		pthread_create(&p->thread,NULL,routine,p);
	}
}

/* static void p_join(t_philo *philos) */
void p_join(t_philo *philos)
{
	int i;
	t_philo *p;

	i = 0;
	while(i < philos->info->number)
	{
		p = &philos[i++];
		pthread_join(p->thread,NULL);
		i++;
	}
}

void dining_philo(t_philo *philos)
{
	p_create(philos);
	/* p_join(philos); */
}
