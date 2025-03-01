/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:25:42 by emonacho          #+#    #+#             */
/*   Updated: 2025/03/01 14:56:42 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_map(t_sl *sl)
{
	ft_printf("-------------------------\n");
	ft_printf("MAP DIMENSIONS SET\nsl->map_width (axe X): %d\n",sl->map_width);
	ft_printf("sl->map_height(axe Y): %d\n-------------------------\n",
	sl->map_height);

	sl->i = 0;
	while (sl->i < sl->map_height)
	{
		ft_printf("sl->map_copy: %s\n", sl->map_copy[sl->i]);
		sl->i++;
	}
	ft_printf("-------------------------\n");
	sl->i = 0;
	while (sl->i < sl->map_height)
	{
		ft_printf("sl->map: %s\n", sl->map[sl->i]);
		sl->i++;
	}
}
