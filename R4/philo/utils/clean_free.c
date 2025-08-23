/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:53:16 by emonacho          #+#    #+#             */
/*   Updated: 2025/08/23 16:51:37 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	free_structs(t_main *s)
{
	free(s->philos);
	free(s->forks);
	free(s->philo_died);
	free(s->in);
}

void	destroy_mutex(t_main *s)
{
	int	i;

	i = -1;
	while (++i < s->in[N_PHILO])
		handle_mutex(&s->forks[i].fork, DESTROY);
	handle_mutex(&s->write_lock, DESTROY);
	handle_mutex(&s->dead_lock, DESTROY);
	handle_mutex(&s->meal_lock, DESTROY);
}

void	clean_free(t_main *s)
{
	destroy_mutex(s);
	free_structs(s);
}
