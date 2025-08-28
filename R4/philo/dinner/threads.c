/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/08/28 16:44:02 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../philo.h"

// return(1) = TRUE
// return(0) = FALSE
// return(-1)= ERROR
int	dinner_is_done(t_philo *p)
{
	t_time	now;

	if (p->meals_eaten == p->meals_toeat)
		return (1);
	if (handle_mutex(&p->s->main_lock, LOCK) != 0)
		return (-1);
	if (*p->s->philo_died == true)
		return (quit_dinner(p));
	now = get_time();
	if ((p->starving_time - now) > p->tto_die)
	{
		helper_print_philo(p); //🖨️❗️
		if (handle_mutex(&p->s->main_lock, UNLOCK) != 0)
			return (-1);
		print_philo(p, "died", true);
		return (1);
	}
	if (handle_mutex(&p->s->main_lock, UNLOCK) != 0)
		return (-1);
	return (0);
}

static int	big_dinner(t_philo *p)
{
	int	ret;

	while (1)
	{
		ret = dinner_is_done(p);
		if (ret == 1)
			break ;
		else if (ret == -1)
			return (1);
		philo_eat(p);
		philo_sleep(p);
		philo_think(p);
		//handle_mutex(&p->s->main_lock, LOCK); //🖨️❗️
		//helper_print_philo(p); //🖨️❗️
		//handle_mutex(&p->s->main_lock, UNLOCK); //🖨️❗️
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

	philo = (t_philo *)data;
	if (philo->s->in[N_PHILO] > 1)
		big_dinner(philo);
	else
		solo_dinner(philo);
	return (NULL);
}

int	dinner(t_main *s)
{
	int	i;
	int	ret;

	i = 0;
	while (i < s->in[N_PHILO])
	{
		s->philos[i].start_time = get_time();
		s->philos[i].last_meal = s->philos[i].start_time;
		s->philos[i].starving_time = s->philos[i].last_meal + s->philos[i].tto_die;
		if (handle_thread(&s->philos[i].thread, CREATE,
				start_dinner, &s->philos[i]) != 0)
			return (1);
		ret = dinner_is_done(&s->philos[i]);
		i++;
		if (ret != 0)
			break ;
	}
	s->philos_init = i;
	i = -1;
	while (++i < s->philos_init)
	{
		if (handle_thread(&s->philos[i].thread, JOIN, NULL, NULL) != 0)
			return (1);
	}
	if (ret == -1)
		return (1);
	return (0);
}
