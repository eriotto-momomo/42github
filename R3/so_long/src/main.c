/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:51:21 by emonacho          #+#    #+#             */
/*   Updated: 2025/03/02 20:17:26 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char *argv[])
{
	t_s	s;

	check_args(argc, argv);
	initialize_map(&s, argv[1]);
	s.img_width = 128;
	s.img_height = 128;
	s.init = mlx_init();
	s.win = mlx_new_window(s.init, (s.img_width * s.map_width),
			(s.img_height * s.map_height), "so_long");
	s.close_signal = 0;
	put_assets(&s);
	s.moves_cnt = 0;
	key_and_mouse_inputs(&s);
	mlx_loop(s.init);
}
