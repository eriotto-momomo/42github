/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_assets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:31:05 by emonacho          #+#    #+#             */
/*   Updated: 2025/03/02 16:39:34 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	choose_asset(t_s *s, char c)
{
	char *ptr;

	if (c == '1')
		ptr = s->img_wall;
	else if (c == '0')
		ptr = s->img_floor;
	else if (c == 'C')
		ptr = s->img_collectible;
	else if (c == 'P')
		ptr = s->img_player;
	else if (c == 'E')
		ptr = s->img_exit;
	mlx_put_image_to_window(s->init, s->win, ptr, s->img_x, s->img_y);
	s->img_x += s->img_width;
}

void	put_image(t_s *s)
{
	s->img_x = 1;
	s->img_y = 1;
	s->map_x = 0;
	s->map_y = 0;
	while ((s->img_x <= s->img_width * s->map_width
		&& s->img_y <= s->img_height * s->map_height))
	{
		choose_asset(s, s->map[s->map_y][s->map_x]);
		s->map_x++;
		if (s->img_x == s->img_width * s->map_width + 1)
		{
			s->img_y += s->img_height;
			s->img_x = 1;
			s->map_y++;
			s->map_x = 0;
		}
	}
}

void	path_to_assets(t_s *s)
{
	s->img_path = "assets/floor.xpm";
	s->img_floor = mlx_xpm_file_to_image(s->init, s->img_path,
		&s->img_width, &s->img_height);
	s->img_path = "assets/wall.xpm";
	s->img_wall = mlx_xpm_file_to_image(s->init, s->img_path,
		&s->img_width, &s->img_height);
	s->img_path = "assets/exit.xpm";
	s->img_exit = mlx_xpm_file_to_image(s->init, s->img_path,
		&s->img_width, &s->img_height);
	s->img_path = "assets/collectible.xpm";
	s->img_collectible = mlx_xpm_file_to_image(s->init, s->img_path,
		&s->img_width, &s->img_height);
	s->img_path = "assets/player.xpm";
	s->img_player = mlx_xpm_file_to_image(s->init, s->img_path,
		&s->img_width, &s->img_height);
	s->img_path = NULL;
	if (!(s->img_floor || s->img_wall || s->img_exit || s->img_collectible
		|| s->img_player))
		s->close_signal = 1;
}

void	put_assets(t_s *s)
{
	path_to_assets(s);
	put_image(s);
}
