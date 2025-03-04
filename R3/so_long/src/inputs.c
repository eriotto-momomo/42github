/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:46:16 by emonacho          #+#    #+#             */
/*   Updated: 2025/03/03 00:07:46 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Passing a structure in 'param' needs casting to avoid multiples casts
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
