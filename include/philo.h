/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:53:20 by tyamauch          #+#    #+#             */
/*   Updated: 2024/04/20 20:53:22 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define ERROR 1
# define SUCCESS 0

/* 標準入力から受け取る構造体 */
typedef struct s_info
{
	int				number;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				must_eat;
}					t_info;

/* pthread_createに渡す構造体 */
typedef struct s_philo
{
	int				id;
	int				eat_count;
	struct timeval	start_time;
	long int		active_time;
	bool			is_dead;
	pthread_t		thread;
	pthread_mutex_t	mutex_philo;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	t_info			*info;
}					t_philo;

/* エラーのenum */
enum				e_error_type
{
	ARGS_ERROR,
	CALLOC_ERROR,
	PTHREAD_ERROR
};

/* 行動のenum */
enum				e_action_type
{
	TAKE_FORK,
	EATING,
	SLEEPING,
	THINKING,
	DIED
};

/* check */
bool				input_check(int argc, char **argv);
bool				finish_check(t_philo *philos);

/* init */
t_info				*init_info(int argc, char **argv);
pthread_mutex_t		*init_forks(t_info *input);
t_philo				*init_philos(t_info *input, pthread_mutex_t *forks);

/* destory */
void				fork_destory(pthread_mutex_t *forks, int i);
/* void philo_destory(t_philo *philos); */
void				philo_destory(t_philo *philos, int i);
void				all_free(t_info *input, pthread_mutex_t *forks,
						t_philo *philos);

/* philo */
void				dining_philo(t_philo *philos);
void				p_join(t_philo *philos);
void				*routine(void *arg);
void				put_log(t_philo *philo, int e_action);

/* utils */
int					ft_isdigit(int c);
int					ft_atoi(const char *str);
void				ft_put_error(int e_error_type);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
long int			create_log_time(t_philo *philo);
long int			get_now_time(void);
void				actual_usleep(long int sleep_time);
#endif
