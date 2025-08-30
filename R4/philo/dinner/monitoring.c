/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 21:17:19 by emonacho          #+#    #+#             */
/*   Updated: 2025/08/30 14:49:45 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static bool	all_philos_are_full(t_main *s)
{
	if (handle_mutex(&s->monitor_lock, LOCK) != 0)
		return (true);
	if (s->philos_full == s->in[N_PHILO])
	{
		handle_mutex(&s->monitor_lock, UNLOCK);
		return (true);
	}
	if (handle_mutex(&s->monitor_lock, UNLOCK) != 0)
		return (true);
	return (false);
}

static bool	philo_starved(t_philo *p)
{
	int	elapsed_time;

	if (handle_mutex(&p->s->monitor_lock, LOCK) != 0)
		return (true);
	elapsed_time = get_time_ms(p->last_meal);
	if (elapsed_time < 0)
	{
		handle_mutex(&p->s->monitor_lock, UNLOCK);
		return (true);
	}
	if (elapsed_time > p->tto_die)
	{
		handle_mutex(&p->s->monitor_lock, UNLOCK);
		return (true);
	}
	if (handle_mutex(&p->s->monitor_lock, UNLOCK) != 0)
		return (true);
	return (false);
}

static bool	philo_died(t_philo *p)
{
	if (philo_starved(p))
	{
		if (handle_mutex(&p->s->main_lock, LOCK) != 0)
			return (true);
		*p->s->philo_died = true;
		if (handle_mutex(&p->s->main_lock, UNLOCK) != 0)
			return (true);
		print_philo(p, "died", true);
		return (true);
	}
	return (false);
}

static int	check_philos(t_main *s)
{
	int	i;

	i = -1;
	while (++i < s->in[N_PHILO])
	{
		if (philo_died(&s->philos[i]) == true)
			return (1);
		if (all_philos_are_full(s) == true)
			return (1);
	}
	return (0);
}

void	*waiter_routine(void *data)
{
	t_main	*s;

	s = (t_main *)data;
	usleep(500);
	while (1)
	{
		if (handle_mutex(&s->main_lock, LOCK) != 0)
			return (NULL);
		if (*s->philo_died == true)
		{
			handle_mutex(&s->main_lock, UNLOCK);
			break ;
		}
		if (handle_mutex(&s->main_lock, UNLOCK) != 0)
			return (NULL);
		if (check_philos(s) != 0)
			return (NULL);
		usleep(500);
	}
	return (NULL);
}
