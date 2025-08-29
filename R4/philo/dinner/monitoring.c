/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 21:17:19 by emonacho          #+#    #+#             */
/*   Updated: 2025/08/29 15:28:45 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../philo.h"


/*
* Fonction give_priority et qui check et qui du coup fais wait les philos qui ont mange il y'a moins de 2 / tto_die*/

static bool all_philos_are_full(t_main *s)
{
	handle_mutex(&s->monitor_lock, LOCK);
	if (s->philos_full == s->in[N_PHILO])
	{
		handle_mutex(&s->monitor_lock, UNLOCK);
		return (true);
	}
	handle_mutex(&s->monitor_lock, UNLOCK);
	return (false);
}

static bool philo_died(t_philo *p)
{
	handle_mutex(&p->s->monitor_lock, LOCK);
	if (get_time() >= p->starving_time)
	{
		handle_mutex(&p->s->monitor_lock, UNLOCK);
		print_philo(p, "died", true);
		handle_mutex(&p->s->main_lock, LOCK);
		*p->s->philo_died = true;
		handle_mutex(&p->s->main_lock, UNLOCK);
		return (true);
	}
	handle_mutex(&p->s->monitor_lock, UNLOCK);
	return (false);
}

void	*waiter_routine(void *data)
{
	t_main	*s;
	int		i;

	s = (t_main *)data;
	handle_mutex(&s->main_lock, LOCK);
	usleep(500);
	while (!*s->philo_died)
	{
		handle_mutex(&s->main_lock, UNLOCK);
		i = 0;
		while (i < s->in[N_PHILO])
		{
			if (all_philos_are_full(s) == true)
				return (NULL);
			if (philo_died(&s->philos[i]) == true)
				return (NULL);
			i++;
		}
		usleep(500);
		handle_mutex(&s->main_lock, LOCK);
	}
	return (NULL);
}
