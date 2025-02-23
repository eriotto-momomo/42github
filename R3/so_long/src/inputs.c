/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:46:16 by emonacho          #+#    #+#             */
/*   Updated: 2025/02/23 19:42:30 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	deal_key(int keycode, void *param)
{
	t_sl	*sl; //casting de param en structure afin d'eviter de multiples casting

	sl = (t_sl *)param;
	if (!(keycode == W || keycode == A || keycode == S || keycode == D))
		printf("keyboard input: %d\n", keycode);
	if (keycode == W || keycode == A || keycode == S || keycode == D)
	{
		(sl->moves_cnt)++;
		printf("WASD moves = %d\n", sl->moves_cnt);
	}
	if (keycode == Q || keycode == ESC)
	{
		sl->close_signal = 1;
		//printf("close_signal = %d\n", sl->close_signal);
	}
	return (0);
}

int	deal_mouse(int button, int x, int y, void *param)
{
	t_sl	*sl;

	sl = (t_sl *)param;
	(sl->mouse_cnt)++;

	printf("mouse input: %d\nx = %d\ny = %d\n", button, x, y);

	return (0);
}

int	key_and_mouse_inputs(t_sl *sl)
{
	// KEYS & MOUSE INPUTS
	mlx_key_hook(sl->win, deal_key, sl); // handle WASD and Q
	mlx_mouse_hook(sl->win, deal_mouse, sl);

	// CLOSING WINDOW WITH CLOSING_SIGNAL OR [X]
	mlx_loop_hook(sl->init, close_signal, sl); // closure with ESC or Q
	mlx_hook(sl->win, 17, 0L, close_and_quit, sl); // closure with mouse
	return (0);
}
