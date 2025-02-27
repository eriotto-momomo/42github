/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:51:21 by emonacho          #+#    #+#             */
/*   Updated: 2025/02/27 13:34:08 by emonacho         ###   ########.fr       */
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

	//FREE sl->map_copy;
	ft_free_array(sl->map, sl->map_height, 'c');
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

int	main(int argc, char *argv[])
{
	t_sl	sl;

	if (argc != 2)
		exit (1);
	// INVALID NUMBER OF ARGUMENTS

	//MAP PARSING
	//printf("argv[1] = %s | sl.map_fd = %d\n", argv[1], sl.map_fd);
	initialize_map(&sl, argv[1]);
	printf("-------------------------\nMAP INITIALIZED\n");

	// MAP PARSING TO DEFINE MAP_WIDTH AND MAP_HEIGHT AND IF VALID,
	// DEFINE WIDTH AND HEIGHT OF THE WINDOW
	// ...
	sl.img_width = 128;
	sl.img_height = 128;

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
