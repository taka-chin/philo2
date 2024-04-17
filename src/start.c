#include "philo.h"

static void p_create(t_philo *philos)
{
	int i;
	t_philo *p;

	i  = 0;
	while(i < philos->info->number)
	{
		p = &philos[i++];
		pthread_create(&p->thread,NULL,routine,p);
	}
}

static void p_join(t_philo *philos)
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

void start(t_philo *philos)
{
	p_create(philos);
	p_join(philos);
}
