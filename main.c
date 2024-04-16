#include "philo.h"

int main(int argc, char **argv)
{
			t_info info;

			if (!input_check(argc, argv))
				return (ERROR);
			input = init_info(argc, argv);
			if (!input)
				return (ERROR);

			pthread_mutex_init(&food_lock, NULL);
			for(i = 0; i < PHILOS; i++)
					pthread_mutex_init(&chopstick[i],NULL);
			for(i = 0; i < PHILOS; i++)
					pthread_create(&philo[i],NULL,philosopher,(void *)i);
			for(i = 0; i < PHILOS; i++)
					pthread_join(philo[i],NULL);
			return (0);
}
