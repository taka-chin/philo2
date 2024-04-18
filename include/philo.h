#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <limits.h>
#include <pthread.h>
#include <stdio.h>

#define ERROR 1
#define SUCCESS 0

/* 標準入力から受け取る構造体 */
typedef struct s_info
{
	int number;
	int time_die;
	int time_eat;
	int time_sleep;
	int must_eat;
}t_info;

/* pthread_createに渡す構造体 */
typedef struct s_philo
{
	int id;
	int eat_count;
	pthread_t thread;
	pthread_mutex_t *r_fork;
	pthread_mutex_t *l_fork;
	t_info *info;
}t_philo;

/* エラーのenum */
enum e_error_type
{
	ARGS_ERROR,
	CALLOC_ERROR,
};

/* check */
bool input_check(int argc ,char **argv);
bool finish_check(t_philo *philos);

/* init */
t_info *init_info(int argc,char **argv);
pthread_mutex_t *init_forks(t_info *input);
t_philo *init_philos(t_info *input,pthread_mutex_t *forks);

/* destory */
void fork_destory(pthread_mutex_t *forks,int i);
void philo_destory(t_philo *philos);
void all_free(t_info *input,pthread_mutex_t *forks,t_philo *philos);

/* philo */
void dining_philo(t_philo *philos);
void *routine(void *arg);

/* utils */
int ft_isdigit(int c);
int ft_atoi(const char *str);
void ft_put_error(int e_error_type);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
#endif
