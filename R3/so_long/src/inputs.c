/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:46:16 by emonacho          #+#    #+#             */
/*   Updated: 2025/03/02 18:32:57 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	deal_key(int keycode, void *param)
{
	t_s	*s; //casting de param en structure afin d'eviter de multiples casting

	s = (t_s *)param;
	if (!(keycode == W || keycode == A || keycode == S || keycode == D))
		ft_printf("Keyboard input: %d\n", keycode);
	if (keycode == W || keycode == A || keycode == S || keycode == D)
		move_player(s, keycode);
	if (keycode == Q || keycode == ESC)
		s->close_signal = 1;
	return (0);
}

int	deal_mouse(int button, int x, int y, void *param)
{
	t_s	*s; //casting de param en structure afin d'eviter de multiples casting

	s = (t_s *)param;
	(s->mouse_cnt)++;

	ft_printf("mouse input: %d\nx = %d\ny = %d\n", button, x, y);

	return (0);
}

int	key_and_mouse_inputs(t_s *s)
{
	// KEYS & MOUSE INPUTS
	mlx_key_hook(s->win, deal_key, s); // handle WASD and Q
	mlx_mouse_hook(s->win, deal_mouse, s);

	// CLOSING WINDOW WITH CLOSING_SIGNAL OR [X]
	mlx_loop_hook(s->init, close_signal, s); // closure with ESC or Q
	mlx_hook(s->win, 17, 0L, close_and_quit, s); // closure with mouse
	return (0);
}
