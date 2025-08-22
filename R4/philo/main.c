/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:19:15 by emonacho          #+#    #+#             */
/*   Updated: 2025/08/22 11:01:19 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	main(int ac, char **av)
{
	t_main	s;

	if (parse_input(ac, av, &s) != 0)
		return (1);
	printf("%smain | input parsed!%s\n", G, RST);
	if (init_data(&s) != 0)
		return (1);
	printf("%s-data_init-%s\n🧙🏻‍♂️ N_PHILO: %d\n☠️ TTO_DIE: %d\n⏰ TTO_EAT: %d\n💤 TTO_SLP: %d\n🍴 MST_EAT: %d\n%s-----------%s\n", Y, RST, s.in[N_PHILO], s.in[TTO_DIE], s.in[TTO_EAT], s.in[TTO_SLEEP], s.in[MUST_EAT], Y, RST);
	if (pasta_party(&s) != 0)
	{
		clean_free(&s);
		return (1);
	}
	clean_free(&s);
	return (0);
}
