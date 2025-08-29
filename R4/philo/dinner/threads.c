/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/08/29 15:31:00 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../philo.h"

static int	big_dinner(t_philo *p)
{
	fprintf(stderr, "✅ start time.....: %s%llu%s\n", Y, p->start_time, RST); //🖨️❗️
	if (p->id % 2 == 0)
		usleep(100);
	while (1)
	{
		if (dinner_is_done(p) != 0)
			break ;
		if (philo_eat(p) == 1)
			break ;
		if (philo_sleep(p) == 1)
			break ;
		if (philo_think(p) == 1)
			break ;
	}
	return (0);
}

static int	solo_dinner(t_philo *p)
{
	int	ret;

	ret = dinner_is_done(p);
	if (ret == 0)
	{
		if (handle_mutex(&p->frst_fork->fork, LOCK) != 0)
			return (1);
		print_philo(p, "has taken a fork", false);
		while (1)
		{
			if (ret == 1)
				break ;
			else if (ret == -1)
				return (1);
			ret = dinner_is_done(p);
		}
		if (handle_mutex(&p->frst_fork->fork, UNLOCK) != 0)
			return (1);
	}
	else if (ret == -1)
		return (1);
	return (0);
}

static void	sync_philos(t_main *s)
{
	while (1)
	{
		handle_mutex(&s->start_lock, LOCK);
		if (s->start_flag == true)
		{
			handle_mutex(&s->start_lock, UNLOCK);
			break ;
		}
		handle_mutex(&s->start_lock, UNLOCK);
		usleep(100);
	}
}

static void	*start_dinner(void *data)
{
	t_philo	*p;
	t_main	*s;

	p = (t_philo *)data;
	s = p->s;
	sync_philos(s);
	handle_mutex(&s->start_lock, LOCK);
	p->start_time = get_time();
	p->last_meal = p->start_time;
	p->starving_time = p->last_meal + p->tto_die;
	if (p->n_philos > 1)
	{
		handle_mutex(&s->start_lock, UNLOCK);
		big_dinner(p);
		return (NULL);
	}
	handle_mutex(&s->start_lock, UNLOCK);
	solo_dinner(p);
	return (NULL);
}

int	dinner(t_main *s)
{
	int	i;

	i = 0;
	while (i < s->in[N_PHILO])
	{
		if (handle_thread(&s->philos[i].thread, CREATE,
				start_dinner, &s->philos[i]) != 0)
			return (1);
		i++;
	}
	s->philos_init = i;
	if (handle_thread(&s->waiter_thread, CREATE, waiter_routine, s) != 0)
		return (1);
	handle_mutex(&s->start_lock, LOCK);
	s->start_flag = true;
	handle_mutex(&s->start_lock, UNLOCK);
	i = -1;
	while (++i < s->philos_init)
	{
		if (handle_thread(&s->philos[i].thread, JOIN, NULL, NULL) != 0)
			return (1);
	}
	if (handle_thread(&s->waiter_thread, JOIN, NULL, NULL) != 0)
		return (1);
	return (0);
}
