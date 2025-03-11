/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:46:16 by emonacho          #+#    #+#             */
/*   Updated: 2025/03/11 19:32:46 by emonacho         ###   ########.fr       */
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

int	deal_key(int keycode, void *param)
{
	t_s	*s;

	s = (t_s *)param;
	if (keycode == W || keycode == A || keycode == S || keycode == D)
		handle_moves(s, keycode);
	if (keycode == Q || keycode == ESC)
		s->close_signal = 1;
	return (0);
}

int	key_and_mouse_inputs(t_s *s)
{
	mlx_key_hook(s->win, deal_key, s);
	mlx_loop_hook(s->init, close_signal, s);
	mlx_hook(s->win, 17, 0L, close_and_quit, s);
	return (0);
}
