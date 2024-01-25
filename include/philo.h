#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sysexits.h>
# include <unistd.h>

#  define RED	"\033[31m"
#  define GREEN	"\033[32m"
#  define BLUE	"\033[34m"
#  define ERROR 1

enum				e_error_type
{
	ARGS_ERROR,
	CALLOC_ERROR,
	PTHREAD_ERROR
};

typedef struct s_share
{
	int				number;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				must_eat;
}					t_share;

typedef struct s_philo
{
	t_share			*share;
	pthread_t		thread;
	pthread_mutex_t	mutex_philo;
	pthread_mutex_t			*left_fork;
	pthread_mutex_t			*right_fork;
	int				id;
	int				eat_count;
	long int		active_time;
	int 		status;
}					t_philo;

typedef struct s_thread_data
{
	t_philo			*philo;
	pthread_mutex_t			mutex_read;
	pthread_mutex_t			mutex_write;
}					t_thread_data;	

#endif
