/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:19:07 by emonacho          #+#    #+#             */
/*   Updated: 2025/08/21 18:06:19 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <errno.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

# define R "\033[1;31m"
# define G "\033[1;32m"
# define Y "\033[1;33m"
# define B "\033[1;34m"
# define P "\033[1;35m"
# define C "\033[1;36m"
# define RST "\033[0m"

typedef unsigned long long	t_time;

typedef enum	e_routines
{
	CREATE,
	DETACH,
	JOIN,
	INIT,
	DESTROY,
	LOCK,
	UNLOCK,
}	t_routines;

typedef enum	e_values
{
	ZERO,
	N_PHILO,
	TTO_DIE,
	TTO_EAT,
	TTO_SLEEP,
	MUST_EAT
}	t_val;

typedef struct		s_philo
{
	int				id;
	int				eaten_meals;
	t_time			start_time;
	t_time			last_meal;
	t_time			tto_die;
	t_time			tto_eat;
	t_time			tto_sleep;
	pthread_t		thread;
	int				*philo_died;
	pthread_mutex_t	*frst_fork;
	pthread_mutex_t	*scnd_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}	t_philo;

typedef struct		s_fork
{
	int				id;
	pthread_mutex_t	fork;
}	t_fork;

typedef struct		s_main_struct
{
	int				*in;
	int				philo_died;
	t_philo			*philos;
	t_fork			*forks;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
}	t_main;


// main.c
int		main(int ac, char **av);

// clean_free.c
void	free_structs(t_main *s);
void	destroy_mutex(t_main *s);
void	clean_free(t_main *s);

// init.c
int		init_data(t_main *s);

// parse_input.c
int		parse_input(int ac, char **av, t_main *s);

// pasta_party.c
int		pasta_party(t_main *s);

// threads.c
int		handle_thread(pthread_t *thread, t_routines mode, void *(*foo)(void *), void *data);
int		handle_mutex(pthread_mutex_t *mutex, t_routines mode);

// utils_1.c
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(char *s);
int		ft_usleep(size_t milliseconds);

// utils_2.c
void	get_forks(t_main *s, t_fork *fork, t_philo *p);

#endif
