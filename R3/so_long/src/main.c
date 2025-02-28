/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:51:21 by emonacho          #+#    #+#             */
/*   Updated: 2025/02/28 16:01:08 by emonacho         ###   ########.fr       */
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

	ft_free_array(sl->map, sl->map_height, 'c');
	ft_free_array(sl->map_copy, sl->map_height, 'c');
	sl->map = NULL;
	sl->map_copy = NULL;
	sl->map_line = NULL;
	//free(sl->map_line); // INVALID FREE

	mlx_destroy_image(sl->init, sl->img_floor);
	mlx_destroy_image(sl->init, sl->img_wall);
	mlx_destroy_image(sl->init, sl->img_start);
	mlx_destroy_image(sl->init, sl->img_end);
	sl->img_path = NULL;
	//free(sl->img_floor);	// INVALID FREE

	mlx_destroy_window(sl->init, sl->win);
	mlx_destroy_display(sl->init);
	free(sl->init);
	//free(sl->win);		// INVALID FREE
	//free(sl);				// INVALID FREE
	exit(1);
}

int	main(int argc, char *argv[])
{
	t_sl	sl;

	// INVALID NUMBER OF ARGUMENTS
	if (argc != 2)
	{
		printf("Error! Invalid arguments.\n");
		exit (1);
	}

	//MAP PARSING
	initialize_map(&sl, argv[1]);
	printf("-------------------------\n-----MAP INITIALIZED-----\n");

	// INITIALIZE AND CREATE WINDOW
	sl.img_width = 128;
	sl.img_height = 128;
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
	/*mlx_destroy_window(sl.init, sl.win);
	mlx_destroy_display(sl.init);
	free(sl.win);
	free(sl.init);
	free(sl.map);
	free(sl.map_copy);*/
}
