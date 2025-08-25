/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:53:16 by emonacho          #+#    #+#             */
/*   Updated: 2025/08/25 11:31:45 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	free_structs(t_main *s)
{
	if (s->in)
		free(s->in);
	if (s->philo_died)
		free(s->philo_died);
	if (s->philos)
		free(s->philos);
	if (s->forks)
		free(s->forks);
	free(s);
}

void	destroy_mutex(t_main *s)
{
	int	i;

	i = -1;
	while (++i < s->in[N_PHILO])
		handle_mutex(&s->forks[i].fork, DESTROY);
	handle_mutex(&s->dead_lock, DESTROY);
}

void	clean_free(t_main *s)
{
	destroy_mutex(s);
	free_structs(s);
}
