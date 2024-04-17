#include "philo.h"

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
			start(philos);
			all_free(input,forks,philos);
			return (SUCCESS);
}
