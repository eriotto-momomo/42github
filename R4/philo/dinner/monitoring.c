/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 21:17:19 by emonacho          #+#    #+#             */
/*   Updated: 2025/08/29 21:27:30 by emonacho         ###   ########.fr       */
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

//static bool	philo_starved(t_philo *p)
//{
//	int				elapsed_time;

//	handle_mutex(&p->s->monitor_lock, LOCK);
//	elapsed_time = get_time_ms(p->last_meal);
//	//fprintf(stderr, "philo_starved[%d]| time from last meal[elapsed_time]: %d\n", p->id, elapsed_time);
//	handle_mutex(&p->s->monitor_lock, UNLOCK);
//	if (elapsed_time > p->tto_die)
//		return (true);
//	return (false);
//}

//v1
static bool	philo_starved(t_philo *p)
{
	int	elapsed_time;

	handle_mutex(&p->s->monitor_lock, LOCK);
	elapsed_time = get_time_ms(p->last_meal);
	//fprintf(stderr, "philo_starved | time from last meal: %d\n", elapsed_time);
	handle_mutex(&p->s->monitor_lock, UNLOCK);
	if (elapsed_time > p->tto_die)
		return (true);
	return (false);
}

static bool philo_died(t_philo *p)
{
	if (philo_starved(p))
	{
		print_philo(p, "died", true);
		handle_mutex(&p->s->main_lock, LOCK);
		*p->s->philo_died = true;
		handle_mutex(&p->s->main_lock, UNLOCK);
		return (true);
	}
	return (false);
}

void	*waiter_routine(void *data)
{
	t_main	*s;
	int		i;

	s = (t_main *)data;
	usleep(500);
	while (1)
	{
		handle_mutex(&s->main_lock, LOCK);
		if (*s->philo_died == true)
		{
			handle_mutex(&s->main_lock, UNLOCK);
			break ;
		}
		handle_mutex(&s->main_lock, UNLOCK);
		i = -1;
		while (++i < s->in[N_PHILO])
		{
			if (philo_died(&s->philos[i]) == true)
				return (NULL);
			if (all_philos_are_full(s) == true)
				return (NULL);
		}
		usleep(500);
	}
	return (NULL);
}
