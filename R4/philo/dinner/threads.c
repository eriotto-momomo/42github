/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/08/27 19:22:57 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../philo.h"

// return(1) = TRUE
// return(0) = FALSE
// return(-1)= ERROR
int	dinner_is_done(t_philo *p)
{
	t_time	now;

	if (handle_mutex(&p->s->main_lock, LOCK) != 0)
		return (-1);
	if (p->meals_eaten == p->meals_toeat)
		return (quit_dinner(p));
	if (*p->s->philo_died == true)
		return (quit_dinner(p));
	now = get_time();
	if ((now - p->last_meal - p->start_time) > p->tto_die)
	{
		fprintf(stderr, "☠️❗️[%d] | time_elapsed from last_meal: %llu\np->last_meal: %llu | now: %llu\n", p->id, now - p->last_meal - p->start_time, p->last_meal, now);
		if (handle_mutex(&p->s->main_lock, UNLOCK) != 0)
			return (-1);
		print_philo(p, "died", true);
		return (1);
	}
	if (handle_mutex(&p->s->main_lock, UNLOCK) != 0)
		return (-1);
	return (0);
}

//v1
//int	dinner_is_done(t_philo *p)
//{
//	if (handle_mutex(&p->s->main_lock, LOCK) != 0)
//		return (-1);
//	if (p->meals_eaten == p->meals_toeat)
//		return (quit_dinner(p));
//	if (*p->s->philo_died == true)
//		return (quit_dinner(p));
//	//if ((get_time() - p->last_meal) / 1000 > p->tto_die)
//	if ((get_time() - p->last_meal) > p->tto_die)
//	{
//		fprintf(stderr, "dinner_is_done | TIMEOUT: %llu\n", (get_time() - p->last_meal));
//		if (handle_mutex(&p->s->main_lock, UNLOCK) != 0)
//			return (-1);
//		print_philo(p, "died", true);
//		return (1);
//	}
//	if (handle_mutex(&p->s->main_lock, UNLOCK) != 0)
//		return (-1);
//	return (0);
//}

static int	big_dinner(t_philo *p)
{
	int	ret;

	//p->last_meal = get_time();
	//fprintf(stderr, "big_dinner | p->last_meal: %llu\n", p->last_meal);
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
	}
	return (0);
}

static int	solo_dinner(t_philo *p)
{
	int	ret;

	//p->last_meal = get_time();
	//fprintf(stderr, "solo_dinner | p->last_meal: %llu\n", p->last_meal);
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
		s->philos[i].last_meal = get_time();
		fprintf(stderr, "dinner | p->last_meal: %llu\n", s->philos[i].last_meal);
		if (handle_thread(&s->philos[i].thread, CREATE,
				start_dinner, &s->philos[i]) != 0)
			return (1);
		ret = dinner_is_done(&s->philos[i]);
		i++;
		if (ret != 0)
			break ;
		//ft_usleep(s->philos[i].id * 100);
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
