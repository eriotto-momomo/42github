/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 21:17:19 by emonacho          #+#    #+#             */
/*   Updated: 2025/08/28 22:04:56 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../philo.h"


/*
* Fonction give_priority et qui check et qui du coup fais wait les philos qui ont mange il y'a moins de 2 / tto_die*/



//bool	is_prior(t_main *s, t_time time_to_check, int id)
//{
//	int		i;
//	t_time	time;
//	int		equal_times;
//	bool	is_prior;

//	time = time_to_check;
//	equal_times = 0;
//	is_prior = false;
//	i = 0;
//	fprintf(stderr, "❗️is_prior | time to check...: %llu | philo with id: %d check others\n", time_to_check, id);
//	while (i < s->in[N_PHILO])
//	{
//		fprintf(stderr, "⏰is_prior | p[%d]p->last_meal: %llu\n", s->philos[i].id, s->philos[i].last_meal);
//		if (s->philos[i].last_meal == time_to_check)
//			equal_times++;
//		if (time < s->philos[i].last_meal)
//			is_prior = true;
//		else
//			is_prior = false;
//		time = s->philos[i].last_meal;
//		i++;
//	}
//	if ((equal_times) == s->in[N_PHILO])
//		is_prior = true;
//	fprintf(stderr, "is_prior | equal_times: %d | is_prior: %d\n", equal_times, is_prior);
//	if (is_prior == true)
//		return (true);
//	return (false);
//}

void	*waiter_routine(void *data)
{
	t_main	*s;
	int		i;

	s = (t_main *)data;
	handle_mutex(&s->main_lock, LOCK);
	usleep(500);
	while (!*s->philo_died)
	{
		handle_mutex(&s->main_lock, UNLOCK);
		i = 0;
		while (i < s->in[N_PHILO])
		{
			//if (get_time() - s->philos[i].last_meal >= s->philos[i].tto_die)
			if (get_time() >= s->philos[i].starving_time)
			{
				print_philo(&s->philos[i], "died", true);
				handle_mutex(&s->main_lock, LOCK);
				*s->philo_died = true;
				handle_mutex(&s->main_lock, UNLOCK);
				return (NULL);
			}
			i++;
		}
		usleep(500);
		handle_mutex(&s->main_lock, LOCK);
	}
	return (NULL);
}
