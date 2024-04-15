#include "philo.h"

int main(int argc, char **argv)
{
			int i;

			if(argc == 2)
					sleep_seconds = atoi(argv[1]);

			pthread_mutex_init(&food_lock, NULL);
			for(i = 0; i < PHILOS; i++)
					pthread_mutex_init(&chopstick[i],NULL);
			for(i = 0; i < PHILOS; i++)
					pthread_create(&philo[i],NULL,philosopher,(void *)i);
			for(i = 0; i < PHILOS; i++)
					pthread_join(philo[i],NULL);
			return (0);
}
