/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:20:59 by emonacho          #+#    #+#             */
/*   Updated: 2025/08/30 13:37:45 by emonacho         ###   ########.fr       */
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
	print_philo(p, "is thinking", false);
	return (0);
}

int	philo_sleep(t_philo *p)
{
	if (dinner_is_done(p) != 0)
		return (1);
	print_philo(p, "is sleeping", false);
	philo_wait(p, p->tto_slp); // error_handling
	return (0);
}

int	philo_eat(t_philo *p)
{
	if (pick_forks(p) != 0)
		return (1);
	print_philo(p, "is eating", false);
	philo_wait(p, p->tto_eat); // error_handling
	if (give_forks(p) != 0)
		return (1);
	handle_mutex(&p->s->monitor_lock, LOCK);
	if (gettimeofday(&p->last_meal, NULL) != 0)
	{
		handle_mutex(&p->s->monitor_lock, UNLOCK);
		return (1);
	}
	p->meals_eaten++;
	handle_mutex(&p->s->monitor_lock, UNLOCK);
	if (dinner_is_done(p) != 0)
		return (0);
	return (0);
}

int	print_philo(t_philo *p, char *status, bool end_dinner)
{
	int	now;  //now == %d a la place de %llu

	now = get_time_ms(p->s->ref_time); // error_handling
	if (now < 0)
		return (1);
	handle_mutex(&p->s->main_lock, LOCK);
	if (end_dinner == true)
	{
		printf("%d %d %s\n", now, p->id, status);  //now == %d a la place de %llu
		handle_mutex(&p->s->main_lock, UNLOCK);
		return (0);
	}
	if (*p->s->philo_died == true)
	{
		handle_mutex(&p->s->main_lock, UNLOCK);
		return (0);
	}
	printf("%d %d %s\n", now, p->id, status); //now == %d a la place de %llu
	handle_mutex(&p->s->main_lock, UNLOCK);
	return (0);
}
