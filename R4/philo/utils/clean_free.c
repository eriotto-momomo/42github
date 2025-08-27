/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:53:16 by emonacho          #+#    #+#             */
/*   Updated: 2025/08/27 01:32:10 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	destroy_mutex(t_main *s)
{
	int	i;

	i = -1;
	while (++i < s->philos_init)
		handle_mutex(&s->forks[i].fork, DESTROY);
	handle_mutex(&s->main_lock, DESTROY);
	handle_mutex(&s->strv_lock, DESTROY);
}

void	free_structs(t_main *s)
{
	if (*s->in)
		free(s->in);
	if (*s->philo_died)
		free(s->philo_died);
	if (s->forks)
		free(s->forks);
	if (s->philos)
		free(s->philos);
	free(s);
}

void	clean_free(t_main *s)
{
	destroy_mutex(s);
	free_structs(s);
}
