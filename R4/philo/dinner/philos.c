/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:20:59 by emonacho          #+#    #+#             */
/*   Updated: 2025/08/26 20:17:51 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	philo_wait(t_philo *p, t_time tto_wait)
{
	t_time	time;

	time = get_time();
	while ((get_time() - time) < tto_wait)
	{
		if (dinner_is_done(p) != 0)
			return ;
		ft_usleep(10);
	}
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

//V2
int	philo_eat(t_philo *p)
{
	if (dinner_is_done(p) != 0)
		return (0);
	handle_mutex(&p->frst_fork->fork, LOCK);
	print_philo(p, "has taken a fork", false);
	handle_mutex(&p->scnd_fork->fork, LOCK);
	if (dinner_is_done(p) != 0)
	{
		handle_mutex(&p->frst_fork->fork, UNLOCK);
		handle_mutex(&p->scnd_fork->fork, UNLOCK);
		return (0);
	}
	handle_mutex(&p->s->main_lock, LOCK);
	p->meals_eaten++;
	p->last_meal = get_time();
	handle_mutex(&p->s->main_lock, UNLOCK);
	print_philo(p, "has taken a fork", false);
	print_philo(p, "is eating", false);
	philo_wait(p, p->tto_eat);
	handle_mutex(&p->frst_fork->fork, UNLOCK);
	handle_mutex(&p->scnd_fork->fork, UNLOCK);
	return (0);
}

//V1
//int	philo_eat(t_philo *p)
//{
//	if (dinner_is_done(p) != 0)
//		return (0);
//	handle_mutex(&p->frst_fork->fork, LOCK);
//	print_philo(p, "has taken a fork", false);
//	handle_mutex(&p->scnd_fork->fork, LOCK);
//	if (dinner_is_done(p) != 0)
//	{
//		handle_mutex(&p->frst_fork->fork, UNLOCK);
//		return (handle_mutex(&p->scnd_fork->fork, UNLOCK));
//	}
//	print_philo(p, "has taken a fork", false);
//	handle_mutex(&p->s->main_lock, LOCK);
//	p->meals_eaten++;
//	p->last_meal = get_time();
//	handle_mutex(&p->s->main_lock, UNLOCK);
//	print_philo(p, "is eating", false);
//	philo_wait(p, p->tto_eat);
//	handle_mutex(&p->frst_fork->fork, UNLOCK);
//	handle_mutex(&p->scnd_fork->fork, UNLOCK);
//	return (0);
//}

int	print_philo(t_philo *p, char *status, bool end_dinner)
{
	if (handle_mutex(&p->s->main_lock, LOCK) != 0)
		return (1);
	if (*p->s->philo_died == false)
	{
		printf("%llu %d %s\n", (get_time() - p->start_time), p->id, status);
		if (end_dinner == true)
			*p->s->philo_died = true;
	}
	if (handle_mutex(&p->s->main_lock, UNLOCK) != 0)
		return (1);
	dinner_is_done(p);
	return (0);
}
