#include "philo.h"

int main(int argc, char **argv)
{
			t_info *input;
			pthread_mutex_t *forks;

			if (!input_check(argc, argv))
				return (ERROR);
			input = init_info(argc, argv);
			if (!input)
				return (ERROR);
			forks = init_forks(input);
			if (!forks)
				return (ERROR);

			return (SUCCESS);
}
