#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <limits.h>

#define ERROR 1
#define SUCCESS 0

typedef struct s_info
{
	int number;
	int time_die;
	int time_eat;
	int time_sleep;
	int must_eat;
}t_info;

enum e_error_type
{
	ARGS_ERROR,
	CALLOC_ERROR,
};

bool input_check(int argc ,char **argv);
t_info *init_info(int argc,char **argv);

/* utils */
int ft_isdigit(int c);
int ft_atoi(const char *str);
void ft_put_error(int e_error_type);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
#endif
