/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:20:59 by emonacho          #+#    #+#             */
/*   Updated: 2025/08/30 14:53:34 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	philo_wait(t_philo *p, int tto_wait)
{
	struct timeval	now;
	int				elapsed_time;

	elapsed_time = 0;
	if (gettimeofday(&now, NULL) != 0)
		return (1);
	while (elapsed_time < tto_wait)
	{
		elapsed_time = get_time_ms(now);
		if (elapsed_time < 0)
			return (1);
		if (elapsed_time > tto_wait)
			break ;
		if (dinner_is_done(p) == 1)
			return (1);
		usleep(500);
	}
	return (0);
}

int	philo_think(t_philo *p)
{
	if (dinner_is_done(p) != 0)
		return (1);
	if (print_philo(p, "is thinking", false) != 0)
		return (1);
	return (0);
}

int	philo_sleep(t_philo *p)
{
	if (dinner_is_done(p) != 0)
		return (1);
	if (print_philo(p, "is sleeping", false) != 0)
		return (1);
	if (philo_wait(p, p->tto_slp) != 0)
		return (1);
	return (0);
}

int	philo_eat(t_philo *p)
{
	if (pick_forks(p) != 0)
		return (1);
	if (print_philo(p, "is eating", false) != 0)
		return (give_forks(p), 1);
	if (philo_wait(p, p->tto_eat) != 0)
		return (give_forks(p), 1);
	if (give_forks(p) != 0)
		return (1);
	if (handle_mutex(&p->s->monitor_lock, LOCK) != 0)
		return (1);
	if (gettimeofday(&p->last_meal, NULL) != 0)
	{
		handle_mutex(&p->s->monitor_lock, UNLOCK);
		return (1);
	}
	p->meals_eaten++;
	if (handle_mutex(&p->s->monitor_lock, UNLOCK) != 0)
		return (1);
	if (dinner_is_done(p) != 0)
		return (1);
	return (0);
}

int	print_philo(t_philo *p, char *status, bool end_dinner)
{
	int	now;

	now = get_time_ms(p->s->ref_time);
	if (now < 0)
		return (1);
	if (handle_mutex(&p->s->main_lock, LOCK) != 0)
		return (1);
	if (end_dinner == true)
	{
		printf("%d %d %s\n", now, p->id, status);
		handle_mutex(&p->s->main_lock, UNLOCK);
		return (1);
	}
	if (*p->s->philo_died == true)
	{
		handle_mutex(&p->s->main_lock, UNLOCK);
		return (1);
	}
	printf("%d %d %s\n", now, p->id, status);
	if (handle_mutex(&p->s->main_lock, UNLOCK) != 0)
		return (1);
	return (0);
}
