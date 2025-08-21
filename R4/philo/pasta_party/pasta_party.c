/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pasta_party.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:50:17 by emonacho          #+#    #+#             */
/*   Updated: 2025/08/21 17:27:53 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*dinner(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
}

int	pasta_party(t_main *s)
{
	int	i;

	if (s->in[MUST_EAT] == 0)
		return (0);
	//else if (s->in[N_PHILO] == 1)
		// ...
	else
	{
		i = -1;
		while (++i < s->in[N_PHILO])
			handle_thread(&s->philos[i].thread, CREATE, dinner, &s->philos[i]);
	}
}