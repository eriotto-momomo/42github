/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:43:05 by emonacho          #+#    #+#             */
/*   Updated: 2025/03/11 19:12:51 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	display_moves_and_collectibles(t_s *s)
{
	char	*str;

	str = ft_itoa(s->moves_cnt);
	mlx_string_put(s->init, s->win, 30, 55, 0x000000, "Moves: ");
	mlx_string_put(s->init, s->win, 120, 55, 0x000000, str);
	free(str);
	str = ft_itoa(s->map_c_cnt);
	mlx_string_put(s->init, s->win, 30, 75, 0x000000, "Waffles left: ");
	mlx_string_put(s->init, s->win, 120, 75, 0x000000, str);
	free(str);
}
