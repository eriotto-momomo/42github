/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:20:59 by emonacho          #+#    #+#             */
/*   Updated: 2025/08/28 17:55:32 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	philo_wait(t_philo *p, long tto_wait)
{
	struct timeval	now;
	struct timeval	time_to_wait;
	long			elapsed;

	if (handle_mutex(&p->s->main_lock, LOCK) != 0) //🖨️❗️
		return ; //🖨️❗️
	gettimeofday(&now, NULL);
	if (handle_mutex(&p->s->main_lock, UNLOCK) != 0) //🖨️❗️
		return ; //🖨️❗️
	while (elapsed < tto_wait)
	{
		gettimeofday(&time_to_wait, NULL);
		elapsed = diff_timeval_us(&time_to_wait, &now);
		fprintf(stderr, "philo_wait | p[id][%d] | elapsed wiat: %ld\n", p->id, elapsed);
		if (elapsed > tto_wait)
			break ;
		if (dinner_is_done(p) == 1)
			return ;
		usleep(500);
		//ft_usleep(10);
	}
	//fprintf(stderr, "philo_wait | p[id][%d] | STOP WAITING | TIME ELAPSED: %llu\n", p->id, elaps_wait);
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
	philo_wait(p, p->tto_slp);
	return (0);
}

int	philo_eat(t_philo *p)
{
	//handle_mutex(&p->s->main_lock, LOCK); //🖨️❗️
	//helper_print_philo(p); //🖨️❗️
	//handle_mutex(&p->s->main_lock, UNLOCK); //🖨️❗️
	fprintf(stderr, "philo_eat| p[id][%d] | 1\n", p->id);
	if (dinner_is_done(p) != 0)
		return (0);
	pick_forks(p);
	if (dinner_is_done(p) != 0)
	{
		handle_mutex(&p->frst_fork->fork, UNLOCK);
		handle_mutex(&p->scnd_fork->fork, UNLOCK);
		return (0);
	}
	print_philo(p, "has taken a fork", false);
	handle_mutex(&p->s->main_lock, LOCK);
	gettimeofday(&p->last_meal, NULL);
	//p->last_meal = get_time();
	//p->starving_time = p->last_meal + p->tto_die;
	p->meals_eaten++;
	handle_mutex(&p->s->main_lock, UNLOCK);
	print_philo(p, "is eating", false);
	philo_wait(p, p->tto_eat);
	handle_mutex(&p->frst_fork->fork, UNLOCK);
	handle_mutex(&p->scnd_fork->fork, UNLOCK);


	return (0);
}

int	print_philo(t_philo *p, char *status, bool end_dinner)
{
	struct timeval	now;
	long			elapsed;

	if (handle_mutex(&p->s->main_lock, LOCK) != 0)
		return (1);
	gettimeofday(&now, NULL);
	elapsed = diff_timeval_us(&now, &p->s->start_time);
	if (*p->s->philo_died == false)
	{
		printf("%ld %d %s\n", elapsed, p->id, status);
		if (end_dinner == true)
			*p->s->philo_died = true;
	}
	if (handle_mutex(&p->s->main_lock, UNLOCK) != 0)
		return (1);
	dinner_is_done(p);
	return (0);
}
