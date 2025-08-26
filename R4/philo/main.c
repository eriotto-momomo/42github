/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:19:15 by emonacho          #+#    #+#             */
/*   Updated: 2025/08/26 19:41:32 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	main(int ac, char **av)
{
	t_main	*s;

	if (!(ac == 5 || ac == 6))
		return (ft_putstr_fd("Error: invalid number of arguments\n", 2), 1);
	s = malloc(sizeof(t_main));
	if (!s)
		return (ft_putstr_fd("Error: malloc failed", 2), 1);
	if (parse_input(ac, av, s) != 0)
	{
		free(s);
		return (1);
	}
	if (init_data(s) != 0)
		return (1);
	if (dinner(s) != 0)
	{
		clean_free(s);
		return (1);
	}
	clean_free(s);
	return (0);
}
