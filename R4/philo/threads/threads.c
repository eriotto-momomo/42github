/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:50:17 by emonacho          #+#    #+#             */
/*   Updated: 2025/08/23 16:56:52 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	dinner_is_done(t_philo *p)
{
	if (p->meals_eaten == p->meals_toeat)
		return (1);
	if (handle_mutex(p->dead_lock, LOCK) != 0)
		return (-1);
	if (*p->philo_died == true)
	{
		if (handle_mutex(p->dead_lock, UNLOCK) != 0)
			return (-1);
		return (1);
	}
	if (handle_mutex(p->dead_lock, UNLOCK) != 0)
			return (-1);
	if (get_time() - p->last_meal > p->tto_die)
	{
		print_philo(p, "died", 1); //🚧TO DO🚧
		return (1);
	}
	return (0);
}

void	*start_dinner(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	print_philo(philo);
	return (NULL);
}

int	dinner(t_main *s)
{
	int	i;

	//if (s->in[MUST_EAT] == 0)		//selon Oceano	//	return (0);
	//else if (s->in[N_PHILO] == 1)	//selon Oceano
		// ...
	//else
	//{								//selon Oceano
	i = -1;
	while (++i < s->in[N_PHILO])
	{
		if (handle_thread(&s->philos[i].thread, CREATE, start_dinner, &s->philos[i]) != 0)
			return (1);
		ft_usleep(100);
	}
	if (dinner_is_done(&s->philos[0]))
		return (0);
	else if (dinner_is_done(&s->philos[0] == -1))
		return (1);
	i = -1;
	while (++i < s->in[N_PHILO])
	{
		if (handle_thread(&s->philos[i].thread, JOIN, NULL, NULL) != 0)
			return (1);
	}
}
