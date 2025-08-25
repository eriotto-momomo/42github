/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:19:15 by emonacho          #+#    #+#             */
/*   Updated: 2025/08/25 17:29:27 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

/*
*	TESTS
*	4 310 200 100 (one should die)
*	4 410 200 200 (no one should die)
*	5 800 200 200 (no one should die)
*	5 800 200 200 7 (no one should die and every philo eats 7 times)
*/

int	main(int ac, char **av)
{
	t_main	*s;

	s = malloc(sizeof(t_main));
	if (!s)
		return (ft_putstr_fd("Error: malloc failed", 2), 1);
	if (parse_input(ac, av, s) != 0)
	{
		free_structs(s);
		return (1);
	}
	if (init_data(s) != 0)
		return (1);
	helper_print_data(s); // 🖨️❗️
	if (dinner(s) != 0)
	{
		clean_free(s);
		return (1);
	}
	helper_print_data(s); // 🖨️❗️
	clean_free(s);
	return (0);
}
