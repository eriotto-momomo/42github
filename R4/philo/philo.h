/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:49:52 by emonacho          #+#    #+#             */
/*   Updated: 2025/08/30 13:17:05 by emonacho         ###   ########.fr       */
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
	pthread_mutex_t	fork;
}	t_fork;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	int				meals_toeat;
	int				n_philos;
	struct timeval	last_meal;
	struct timeval	start_time;
	t_fork			*frst_fork;
	t_fork			*scnd_fork;
	pthread_t		thread;
	int				tto_die;
	int				tto_eat;
	int				tto_slp;
	t_main			*s;
}	t_philo;

typedef struct s_main_struct
{
	int				*in;
	bool			*philo_died;
	t_fork			*forks;
	t_philo			*philos;
	struct timeval	ref_time;
	int				philos_init;
	int				philos_full;
	pthread_t		monitoring;
	pthread_mutex_t	main_lock;
	pthread_mutex_t	start_lock;
	pthread_mutex_t	monitor_lock;
}	t_main;

int		init_data(t_main *s);
int		parse_input(int ac, char **av, t_main *s);
int		give_forks(t_philo *p);
int		pick_forks(t_philo *p);
int		handle_thread(pthread_t *thread, t_routines mode,
			void *(*foo)(void *), void *data);
int		handle_mutex(pthread_mutex_t *mutex, t_routines mode);
void	*waiter_routine(void *data);
int		philo_think(t_philo *p);
int		philo_sleep(t_philo *p);
int		philo_eat(t_philo *p);
int		print_philo(t_philo *p, char *status, bool end_dinner);
int		dinner(t_main *s);
int		dinner_is_done(t_philo *p);
void	free_structs(t_main *s);
void	destroy_mutex(t_main *s);
void	clean_free(t_main *s);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(char *s);
int		get_time_ms(struct timeval ref_time);

#endif
