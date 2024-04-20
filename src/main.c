#include "philo.h"

static void *observe(t_philo *philos)
{
	int i;
	t_philo *p;

	i = 0;
	while(true)
	{
		if(finish_check(philos))
				break;
		actual_usleep(1);
	}
	while(i < philos->info->number)
	{
		p = &philos[i++];
		pthread_mutex_lock(&p->mutex_philo);
		p->is_dead = true;
		pthread_mutex_unlock(&p->mutex_philo);
		i++;
	}
	return(NULL);
}

int main(int argc, char **argv)
{
			t_info *input;
			pthread_mutex_t *forks;
			t_philo *philos;

			if (!input_check(argc, argv))
				return (ERROR);
			input = init_info(argc, argv);
			if (!input)
				return (ERROR);
			forks = init_forks(input);
			if (!forks)
			{
				all_free(input,NULL,NULL);
				return (ERROR);
			}
			philos = init_philos(input,forks);
			if (!philos)
			{
				all_free(input,forks,NULL);
				return (ERROR);
			}
			dining_philo(philos);
			observe(philos);
			p_join(philos);
			all_free(input,forks,philos);
			return (SUCCESS);
}
