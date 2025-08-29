/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:20:59 by emonacho          #+#    #+#             */
/*   Updated: 2025/08/29 19:13:16 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"



static void	philo_wait(t_philo *p, int tto_wait)
{
	struct timeval	now;
	int				elapsed_time;

	elapsed_time = 0;
	if (gettimeofday(&now, NULL) != 0)
		return ; // error_handling
	while (elapsed_time < tto_wait)
	{
		elapsed_time = get_time_ms(now);
		//fprintf(stderr, "philo_wait | p[id][%d] | elapsed_wait: %d\n", p->id, elapsed_time);
		if (elapsed_time < 0)
			return ;
		if (elapsed_time > tto_wait)
			break ;
		if (dinner_is_done(p) == 1)
			return ;
		//usleep(500);
		usleep(500); // MacOS
		//ft_usleep(500);
	}
	//fprintf(stderr, "philo_wait | p[id][%d] | STOP WAITING | TIME ELAPSED: %llu\n", p->id, elaps_wait);
}

int	philo_think(t_philo *p)
{
	if (dinner_is_done(p) != 0)
		return (1);
	print_philo(p, "is thinking", false);
	//usleep(500);
	usleep(100); // MacOS
	return (0);
}

int	philo_sleep(t_philo *p)
{
	if (dinner_is_done(p) != 0)
		return (1);
	print_philo(p, "is sleeping", false);
	philo_wait(p, p->tto_slp);
	return (0);
}

int	philo_eat(t_philo *p)
{
	//handle_mutex(&p->s->main_lock, LOCK); //🖨️❗️
	//helper_print_philo(p); //🖨️❗️
	//handle_mutex(&p->s->main_lock, UNLOCK); //🖨️❗️
	if (pick_forks(p) != 0)
		return (1);
	print_philo(p, "is eating", false);
	philo_wait(p, p->tto_eat);
	handle_mutex(&p->frst_fork->fork, UNLOCK);
	handle_mutex(&p->scnd_fork->fork, UNLOCK);
	handle_mutex(&p->s->monitor_lock, LOCK);
	if (gettimeofday(&p->last_meal, NULL) != 0)
	{
		handle_mutex(&p->s->monitor_lock, UNLOCK);
		return (1);
	}
	p->meals_eaten++;
	p->priority = 3;
	handle_mutex(&p->s->monitor_lock, UNLOCK);
	if (dinner_is_done(p) != 0)
		return (0);
	//usleep(100);
	return (0);
}

void	print_philo(t_philo *p, char *status, bool end_dinner)
{
	t_time	now;

	now = get_time_ms(p->s->ref_time);
	handle_mutex(&p->s->main_lock, LOCK);
	if (end_dinner == true)
	{
		printf("%llu %d %s\n", now, p->id, status);
		handle_mutex(&p->s->main_lock, UNLOCK);
		return ;
	}
	if (*p->s->philo_died == true)
	{
		handle_mutex(&p->s->main_lock, UNLOCK);
		return ;
	}
	handle_mutex(&p->s->main_lock, UNLOCK);
	printf("%llu %d %s\n", now, p->id, status);
}
