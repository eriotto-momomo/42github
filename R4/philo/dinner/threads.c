/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/08/29 13:16:01 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../philo.h"

// return(1) = TRUE
// return(0) = FALSE
// return(-1)= ERROR
int	dinner_is_done(t_philo *p)
{
	if (handle_mutex(&p->s->main_lock, LOCK) != 0)
		return (-1);
	if (*p->s->philo_died == true)
	{
		if (handle_mutex(&p->s->main_lock, UNLOCK) != 0)
			return (-1);
		return (1);
	}
	if (handle_mutex(&p->s->main_lock, UNLOCK) != 0)
		return (-1);
	if (p->meals_eaten == p->meals_toeat)
	{
		handle_mutex(&p->s->read_lock, LOCK);
		p->s->philos_full++;
		handle_mutex(&p->s->read_lock, UNLOCK);
		return (1);
	}
	//handle_mutex(&p->s->main_lock, LOCK); //🖨️❗️
	//helper_print_philo(p); //🖨️❗️
	//handle_mutex(&p->s->main_lock, UNLOCK); //🖨️❗️
	return (0);
}

static int	big_dinner(t_philo *p)
{
	fprintf(stderr, "✅ start time.....: %s%llu%s\n", Y, p->start_time, RST); //🖨️❗️
	if (p->id % 2 == 0)
		usleep(100);
	while (1)
	{
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

static void	*start_dinner(void *data)
{
	t_philo	*philo;
	t_main	*s;

	philo = (t_philo *)data;
	s = philo->s;
	while (1)
	{
		handle_mutex(&s->start_lock, LOCK);
		if (s->start_flag == true)
			break ;
		handle_mutex(&s->start_lock, UNLOCK);
		usleep(100);
	}
	handle_mutex(&s->start_lock, UNLOCK);
	philo->start_time = get_time();
	philo->last_meal = philo->start_time;
	philo->starving_time = philo->last_meal + philo->tto_die;
	if (philo->s->in[N_PHILO] > 1)
		big_dinner(philo);
	else
		solo_dinner(philo);
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
