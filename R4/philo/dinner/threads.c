/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:20:59 by emonacho          #+#    #+#             */
/*   Updated: 2025/08/30 16:51:35 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	dinner_is_done(t_philo *p)
{
	if (handle_mutex(&p->s->main_lock, LOCK) != 0)
		return (1);
	if (*p->s->philo_died == true)
	{
		handle_mutex(&p->s->main_lock, UNLOCK);
		return (1);
	}
	if (handle_mutex(&p->s->main_lock, UNLOCK) != 0)
		return (1);
	if (p->meals_eaten == p->meals_toeat)
	{
		if (handle_mutex(&p->s->monitor_lock, LOCK) != 0)
			return (1);
		p->s->philos_full++;
		handle_mutex(&p->s->monitor_lock, UNLOCK);
		return (1);
	}
	return (0);
}

static int	big_dinner(t_philo *p)
{
	if (p->id % 2 == 0)
		usleep(500);
	while (1)
	{
		if (dinner_is_done(p) != 0)
			break ;
		if (philo_eat(p) != 0)
			break ;
		if (philo_sleep(p) != 0)
			break ;
		if (philo_think(p) != 0)
			break ;
	}
	return (0);
}

static int	solo_dinner(t_philo *p)
{
	if (dinner_is_done(p) == 0)
	{
		if (handle_mutex(&p->frst_fork->fork, LOCK) != 0)
			return (1);
		if (print_philo(p, "has taken a fork", false) != 0)
		{
			handle_mutex(&p->frst_fork->fork, UNLOCK);
			return (1);
		}
		while (1)
		{
			if (dinner_is_done(p) != 0)
				break ;
		}
		if (handle_mutex(&p->frst_fork->fork, UNLOCK) != 0)
			return (1);
	}
	return (0);
}

static void	*start_dinner(void *data)
{
	t_philo	*p;

	p = (t_philo *)data;
	if (handle_mutex(&p->s->start_lock, LOCK) != 0)
		return (NULL);
	if (gettimeofday(&p->start_time, NULL) != 0)
	{
		handle_mutex(&p->s->start_lock, UNLOCK);
		return (NULL);
	}
	p->last_meal = p->start_time;
	if (p->n_philos > 1)
	{
		if (handle_mutex(&p->s->start_lock, UNLOCK) != 0)
			return (NULL);
		big_dinner(p);
		return (NULL);
	}
	if (handle_mutex(&p->s->start_lock, UNLOCK) != 0)
		return (NULL);
	solo_dinner(p);
	return (NULL);
}

int	dinner(t_main *s)
{
	int	i;

	while (++s->philos_init < s->in[N_PHILO])
	{
		if (handle_thread(&s->philos[s->philos_init].thread, CREATE,
				start_dinner, &s->philos[s->philos_init]) != 0)
		{
			if (handle_mutex(&s->main_lock, LOCK) != 0)
				return (1);
			*s->philo_died = true;
			if (handle_mutex(&s->main_lock, UNLOCK) != 0)
				return (1);
			break ;
		}
	}
	if (handle_thread(&s->monitoring, CREATE, waiter_routine, s) != 0)
		return (1);
	i = -1;
	while (++i < s->philos_init)
		if (handle_thread(&s->philos[i].thread, JOIN, NULL, NULL) != 0)
			return (1);
	if (handle_thread(&s->monitoring, JOIN, NULL, NULL) != 0)
		return (1);
	return (0);
}
