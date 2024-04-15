#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>
#include <stdint.h>

#define PHILOS 5
#define DELAY 5000
#define FOOD 100

void * philosopher(void *id);
void grab_chopstick(int , int , char *);
void down_chopsticks(int , int );
int food_on_table();
void get_token();
void return_token();

pthread_mutex_t chopstick[PHILOS];
pthread_t philo[PHILOS];
pthread_mutex_t food_lock;
pthread_mutex_t num_can_eat_lock;
int sleep_seconds = 0;
uint32_t num_can_eat = PHILOS - 1;
#endif
