/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:51:21 by emonacho          #+#    #+#             */
/*   Updated: 2025/03/02 18:32:23 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_args(int argc, char *argv[])
{
	int	i;

	if (argc != 2)
	{
		ft_printf("Error! Invalid arguments.\n");
		exit (1);
	}
	i = 0;
	while (argv[1][i] != '\0')
		i++;
	if (argv[1][i - 4] == '.' && argv[1][i - 3] != 'b'
		&& argv[1][i - 2] != 'e' && argv[1][i - 1] != 'r')
	{
		ft_printf("Error! Invalid map format.\n");
		exit (1);
	}
}

int	close_signal(t_s *s)
{
	if (s->close_signal == 1)
	{
		close_and_quit(s);
		return (-1);
	}
	return (0);
}

int	close_and_quit(t_s *s)
{
	//FREE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	ft_free_array(s->map, s->map_height, 'c');
	ft_free_array(s->map_copy, s->map_height, 'c');
	s->map = NULL;
	s->map_copy = NULL;
	s->map_line = NULL;
	//free(s->map_line); // INVALID FREE

	mlx_destroy_image(s->init, s->img_floor);
	mlx_destroy_image(s->init, s->img_wall);
	mlx_destroy_image(s->init, s->img_exit);
	mlx_destroy_image(s->init, s->img_collectible);
	mlx_destroy_image(s->init, s->img_player);
	s->img_path = NULL;
	//free(s->img_floor);	// INVALID FREE

	mlx_destroy_window(s->init, s->win);
	mlx_destroy_display(s->init);
	free(s->init);
	//free(s->win);		// INVALID FREE
	//free(s);				// INVALID FREE
	exit(1);
}

int	main(int argc, char *argv[])
{
	t_s	s;

	// CHECK ARGUMENTS VALIDITY
	check_args(argc, argv);

	//MAP PARSING
	initialize_map(&s, argv[1]);
	ft_printf("-------------------------\n     MAP INITIALIZED     \n");

	// INITIALIZE AND CREATE WINDOW
	s.img_width = 128;
	s.img_height = 128;
	s.init = mlx_init();
	s.win = mlx_new_window(s.init, (s.img_width * s.map_width),
	(s.img_height * s.map_height), "so_long");
	s.close_signal = 0;

	// PUT XPM
	put_assets(&s);

	// KEYS & MOUSE INPUTS
	s.moves_cnt = 0;
	s.mouse_cnt = 0; //probably useless
	key_and_mouse_inputs(&s);

	// LOOP WINDOW
	mlx_loop(s.init);

	// FINAL CLEAN --->>> USELESS ???
	/*mlx_destroy_window(s.init, s.win);
	mlx_destroy_display(s.init);
	free(s.win);
	free(s.init);
	free(s.map);
	free(s.map_copy);*/
}
