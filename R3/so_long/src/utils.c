/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:25:42 by emonacho          #+#    #+#             */
/*   Updated: 2025/03/01 18:51:15 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_map(t_s *s)
{
	ft_printf("-------------------------\n");
	ft_printf("MAP DIMENSIONS SET\ns->map_width (axe X): %d\n",s->map_width);
	ft_printf("s->map_height(axe Y): %d\n-------------------------\n",
	s->map_height);

	s->i = 0;
	while (s->i < s->map_height)
	{
		ft_printf("s->map_copy: %s\n", s->map_copy[s->i]);
		s->i++;
	}
	ft_printf("-------------------------\n");
	s->i = 0;
	while (s->i < s->map_height)
	{
		ft_printf("s->map: %s\n", s->map[s->i]);
		s->i++;
	}
}
