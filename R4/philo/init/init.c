/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:55:47 by emonacho          #+#    #+#             */
/*   Updated: 2025/08/23 16:44:54 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	init_philos(t_main *s)
{
	int	i;

	i = 0;
	while (i < s->in[N_PHILO])
	{
		s->philos[i].id = i + 1;
		s->philos[i].philo_died = &s->philo_died;
		s->philos[i].meals_toeat = s->in[MUST_EAT];
		s->philos[i].meals_eaten = 0;
		s->philos[i].start_time = get_time();
		s->philos[i].last_meal = get_time();
		s->philos[i].frst_fork = &s->forks[i];
		s->philos[i].scnd_fork = &s->forks[(i + 1) % s->in[N_PHILO]];
		i++;
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

static int	init_mutex(t_main *s)
{
	if (handle_mutex(&s->write_lock, INIT) != 0)
			return (1);
	if (handle_mutex(&s->dead_lock, INIT) != 0)
	{
		handle_mutex(&s->write_lock, DESTROY);
		return (1);
	}
	if (handle_mutex(&s->meal_lock, INIT) != 0)
	{
		handle_mutex(&s->write_lock, DESTROY);
		handle_mutex(&s->dead_lock, DESTROY);
		return (1);
	}
	return (0);
}

static int	init_structs(t_main *s)
{
	s->philo_died = malloc(sizeof(int));
	if (!s->philo_died)
		return (ft_putstr_fd("Error: malloc failed", 2), 1);
	s->philo_died = true;
	s->philos = malloc(sizeof(t_philo) * (*s).in[N_PHILO]);
	if (!(*s).philos)
		return (ft_putstr_fd("Error: malloc failed", 2), 1);
	s->forks = malloc(sizeof(t_fork) * (*s).in[N_PHILO]);
	if (!(*s).forks)
	{
		free((*s).philos);
		return (ft_putstr_fd("Error: malloc failed", 2), 1);
	}
	return (0);
}

int	init_data(t_main *s)
{
	if (init_structs(s) != 0)
		return (1);
	if (init_mutex(s) != 0)
	{
		free_structs(s);
		return (1);
	}
	if (init_forks(s->in[N_PHILO], s->forks) != 0)
	{
		clean_free(s);
		return (1);
	}
	init_philos(s);
	return (0);
}
