/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:51:21 by emonacho          #+#    #+#             */
/*   Updated: 2025/02/23 19:41:50 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


int	close_signal(t_sl *sl)
{
	if (sl->close_signal == 1)
	{
		close_and_quit(sl);
		return (-1);
	}
	return (0);
}

int	close_and_quit(t_sl *sl)
{
	//FREE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//FREE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//FREE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	mlx_destroy_image(sl->init, sl->img_floor);
	mlx_destroy_image(sl->init, sl->img_wall);
	mlx_destroy_image(sl->init, sl->img_start);
	mlx_destroy_image(sl->init, sl->img_end);
	//free(sl->img_floor); // INVALID FREE
	//free(sl->win); // INVALID FREE
	mlx_destroy_window(sl->init, sl->win);
	mlx_destroy_display(sl->init);
	free(sl->init);
	exit(1);
}

int	main(void)
{
	t_sl	sl;

	// MAP PARSING TO DEFINE MAP_WIDTH AND MAP_HEIGHT AND IF VALID,
	// DEFINE WIDTH AND HEIGHT OF THE WINDOW
	// ...
	sl.img_width = 128;
	sl.img_height = 128;
	sl.map_width = 10;
	sl.map_height = 3;

	// INITIALIZE AND CREATE WINDOW
	sl.init = mlx_init();
	sl.win = mlx_new_window(sl.init, (sl.img_width * sl.map_width), (sl.img_height * sl.map_height), "so_long");
	sl.close_signal = 0;

	// PUT XPM
	initialize_assets(&sl);

	// KEYS & MOUSE INPUTS
	sl.moves_cnt = 0;
	sl.mouse_cnt = 0; //probably useless
	key_and_mouse_inputs(&sl);

	// LOOP WINDOW
	mlx_loop(sl.init);

	// FINAL CLEAN --->>> USELESS ???
	//mlx_destroy_window(sl.init, sl.win);
	//mlx_destroy_display(sl.init);
	//free(sl.win);
	//free(sl.init);
}
