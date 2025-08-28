/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:55:47 by emonacho          #+#    #+#             */
/*   Updated: 2025/08/28 17:32:44 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	init_philos(t_main *s)
{
	int	i;

	i = -1;
	while (++i < s->in[N_PHILO])
	{
		s->philos[i].id = i + 1;
		s->philos[i].meals_eaten = 0;
		s->philos[i].meals_toeat = s->in[MUST_EAT];
		if (s->philos[i].id % 2 == 0)
		{
			s->philos[i].frst_fork = &s->forks[(i + 1) % s->in[N_PHILO]];	//1st choice for 4 philos
			s->philos[i].scnd_fork = &s->forks[i]; 							//1st choice for 4 philos
		}
		else
		{
			s->philos[i].frst_fork = &s->forks[i];							//1st choice for 4 philos
			s->philos[i].scnd_fork = &s->forks[(i + 1) % s->in[N_PHILO]];	//1st choice for 4 philos
		}
		s->philos[i].tto_die = (long)s->in[TTO_DIE];
		s->philos[i].tto_eat = (long)s->in[TTO_EAT];
		s->philos[i].tto_slp = (long)s->in[TTO_SLEEP];
		s->philos[i].s = s;
	}
}

static int	init_forks(int n_philo, t_fork *forks)
{
	int	i;

	i = 0;
	while (i < n_philo)
	{
		if (handle_mutex(&(forks[i]).fork, INIT) != 0)
		{
			i--;
			while (i >= 0)
			{
				handle_mutex(&(forks[i]).fork, DESTROY);
				i--;
			}
			return (1);
		}
		forks[i].id = i;
		i++;
	}
	return (0);
}

static int	init_locks(t_main *s)
{
	if (handle_mutex(&s->main_lock, INIT) != 0)
		return (1);
	if (handle_mutex(&s->strv_lock, INIT) != 0)
		return (1);
	return (0);
}

static int	init_structs(t_main *s)
{
	s->philo_died = malloc(sizeof(bool));
	s->wait_time = s->in[TTO_DIE] / 2;			// TO DELETE ?
	if (!s->philo_died)
		return (1);
	*(s->philo_died) = false;
	s->philos = malloc(sizeof(t_philo) * (*s).in[N_PHILO]);
	s->forks = malloc(sizeof(t_fork) * (*s).in[N_PHILO]);
	if (!s->philos || !s->forks)
	{
		free_structs(s);
		ft_putstr_fd("Error: malloc failed", 2); // ??????? ./philo 400000000 410 200 200
		return (1);
	}
	return (0);
}

int	init_data(t_main *s)
{
	if (init_structs(s) != 0)
		return (1);
	if (init_locks(s) != 0)
	{
		free_structs(s);
		return (1);
	}
	if (init_forks(s->in[N_PHILO], s->forks) != 0)
	{
		handle_mutex(&s->main_lock, DESTROY);
		free_structs(s);
		return (1);
	}
	init_philos(s);
	return (0);
}
