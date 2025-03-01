/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:31:05 by emonacho          #+#    #+#             */
/*   Updated: 2025/03/01 19:06:55 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int put_sprites(t_s *s)
{
	while ((s->img_x <= s->img_width * s->map_width
		&& s->img_y <= s->img_height * s->map_height))
	{
		if (s->map[s->map_y][s->map_x] == 'P')
		{
			mlx_put_image_to_window(s->init, s->win, s->img_player, s->img_x, s->img_y);
			s->img_x += s->img_width;
		}
		else if (s->map[s->map_y][s->map_x] == 'C')
		{
			mlx_put_image_to_window(s->init, s->win, s->img_collectible, s->img_x, s->img_y);
			s->img_x += s->img_width;
		}
		else
			s->img_x += s->img_width;
		s->map_x++;
		if (s->img_x == s->img_width * s->map_width + 1)
		{
			s->img_y += s->img_height;
			s->img_x = 1;
			s->map_y++;
			s->map_x = 0;
		}
	}
	return (0);
}

int put_environment(t_s *s)
{
	while ((s->img_x <= s->img_width * s->map_width
		&& s->img_y <= s->img_height * s->map_height))
	{
		if (s->map[s->map_y][s->map_x] == '1')
		{
			mlx_put_image_to_window(s->init, s->win, s->img_wall, s->img_x, s->img_y);
			s->img_x += s->img_width;
		}
		else if (s->map[s->map_y][s->map_x] == '0' || s->map[s->map_y][s->map_x] == 'C'
			|| s->map[s->map_y][s->map_x] == 'P')
		{
			mlx_put_image_to_window(s->init, s->win, s->img_floor, s->img_x, s->img_y);
			s->img_x += s->img_width;
		}
		else if (s->map[s->map_y][s->map_x] == 'E')
		{
			mlx_put_image_to_window(s->init, s->win, s->img_exit, s->img_x, s->img_y);
			s->img_x += s->img_width;
		}
		else
			s->img_x += s->img_width;
		s->map_x++;
		if (s->img_x == s->img_width * s->map_width + 1)
		{
			s->img_y += s->img_height;
			s->img_x = 1;
			s->map_y++;
			s->map_x = 0;
		}
	}
	return (0);
}

// WORKING BACKUP TO COVER WINDOW WITH WALLS
/*int put_assets(t_s *s)
{
	while ((s->img_x <= s->img_width * s->map_width
		&& s->img_y <= s->img_height * s->map_height))
	{
		mlx_put_image_to_window(s->init, s->win, s->img_floor, s->img_x, s->img_y);
		s->img_x += s->img_width;
		if (s->img_x == s->img_width * s->map_width + 1)
		{
			s->img_y += s->img_height;
			s->img_x = 1;
		}
	}
	return (0);
}*/

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

void	initialize_assets(t_s *s)
{
	path_to_assets(s);
	s->img_x = 1;
	s->img_y = 1;
	s->map_x = 0;
	s->map_y = 0;
	put_environment(s);
	s->img_x = 1;
	s->img_y = 1;
	s->map_x = 0;
	s->map_y = 0;
	put_sprites(s);
}
