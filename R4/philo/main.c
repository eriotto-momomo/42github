/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:19:15 by emonacho          #+#    #+#             */
/*   Updated: 2025/08/21 17:44:01 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	main(int ac, char **av)
{
	t_main	s;

	if (parse_input(ac, av, &s) != 0)
		return (1);
	if (init_data(&s) != 0)
		return (1);
	if (pasta_party(&s) != 0)
	{
		clean_free(&s);
		return (1);
	}
	clean_free(&s);
	return (0);
}
