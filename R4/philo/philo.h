/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/08/28 14:28:09 by emonacho         ###   ########.fr       */
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
# include <stdbool.h>

# define R "\033[1;31m"
# define G "\033[1;32m"
# define Y "\033[1;33m"
# define B "\033[1;34m"
# define P "\033[1;35m"
# define C "\033[1;36m"
# define RST "\033[0m"

typedef unsigned long long		t_time;
typedef struct s_main_struct	t_main;

typedef enum e_routines
{
	CREATE,
	DETACH,
	JOIN,
	INIT,
	DESTROY,
	LOCK,
	UNLOCK,
}	t_routines;

typedef enum e_values
{
	N_PHILO,
	TTO_DIE,
	TTO_EAT,
	TTO_SLEEP,
	MUST_EAT
}	t_val;

typedef struct s_fork
{
	int				id;
	pthread_mutex_t	fork;
}	t_fork;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	int				meals_toeat;
	t_fork			*frst_fork;
	t_fork			*scnd_fork;
	pthread_t		thread;
	t_time			start_time;
	t_time			last_meal;
	t_time			starving_time;
	t_time			tto_die;
	t_time			tto_eat;
	t_time			tto_slp;
	t_main			*s;
}	t_philo;

typedef struct s_main_struct
{
	int				*in;
	int				philos_init;
	t_time			wait_time;
	t_time			start_time;
	t_philo			*philos;
	t_fork			*forks;
	bool			*philo_died;
	pthread_mutex_t	main_lock;
	pthread_mutex_t	strv_lock;
}	t_main;

void	helper_print_philo(t_philo *p);	// HELPER
void	helper_print_data(t_main *s);	// HELPER


// init.c & parse_input.c
int		init_data(t_main *s);
int		parse_input(int ac, char **av, t_main *s);

// handlers.c
void	pick_forks(t_philo *p);
int		handle_thread(pthread_t *thread, t_routines mode,
			void *(*foo)(void *), void *data);
int		handle_mutex(pthread_mutex_t *mutex, t_routines mode);

// philos.c
int		philo_think(t_philo *p);
int		philo_sleep(t_philo *p);
int		philo_eat(t_philo *p);
int		print_philo(t_philo *p, char *status, bool end_dinner);

// threads.c
int		dinner_is_done(t_philo *p);
int		dinner(t_main *s);

// clean_free.c
void	free_structs(t_main *s);
void	destroy_mutex(t_main *s);
void	clean_free(t_main *s);

// utils.c
int		quit_dinner(t_philo *p);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(char *s);
int		ft_usleep(size_t milliseconds);
t_time	get_time(void);

#endif
