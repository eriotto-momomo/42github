/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_assets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:31:05 by emonacho          #+#    #+#             */
/*   Updated: 2025/03/04 14:56:56 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// 	TRY TO IMPLEMENT PLAYER SPRITES
void	choose_asset(t_s *s, char c, int keycode)
{
	char	*ptr;

	if (c == '1')
		ptr = s->img_wall;
	else if (c == '0')
		ptr = s->img_floor;
	else if (c == 'C')
		ptr = s->img_collectible;
	else if (c == 'P')
	{
		if (keycode == W)
			ptr = s->img_player_up;
		else if (keycode == A)
			ptr = s->img_player_left;
		else if (keycode == D)
			ptr = s->img_player_right;
		else
			ptr = s->img_player_down; // FRONT
	}
	else if (c == 'E')
		ptr = s->img_exit;
	mlx_put_image_to_window(s->init, s->win, ptr, s->img_x, s->img_y);
	s->img_x += s->img_width;
}

// WORKING BACKUP
/*void	choose_asset(t_s *s, char c)
{
	char	*ptr;

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
}*/

void	put_image(t_s *s, int keycode)
{
	s->img_x = 1;
	s->img_y = 1;
	s->map_x = 0;
	s->map_y = 0;
	while ((s->img_x <= s->img_width * s->map_width
			&& s->img_y <= s->img_height * s->map_height))
	{
		choose_asset(s, s->map[s->map_y][s->map_x], keycode);
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

// TRY POUR ECONOMISER DES LIGNES
void	path_to_player_assets(t_s *s)
{
	s->img_player_up = mlx_xpm_file_to_image(s->init,
			"assets/player_up.xpm", &s->img_width, &s->img_height);
	s->img_player_down = mlx_xpm_file_to_image(s->init,
			"assets/player_down.xpm", &s->img_width, &s->img_height);
	s->img_player_left = mlx_xpm_file_to_image(s->init,
			"assets/player_left.xpm", &s->img_width, &s->img_height);
	s->img_player_right = mlx_xpm_file_to_image(s->init,
			"assets/player_right.xpm", &s->img_width, &s->img_height);
	if (!(s->img_player_up || s->img_player_down || s->img_player_left
			|| s->img_player_right))
		s->close_signal = 1;
}

// BACKUP
/*void	path_to_player_assets(t_s *s)
{
	s->img_path = "assets/player_up.xpm";
	s->img_player_up = mlx_xpm_file_to_image(s->init, s->img_path,
			&s->img_width, &s->img_height);
	s->img_path = "assets/player_down.xpm";
	s->img_player_down = mlx_xpm_file_to_image(s->init, s->img_path,
			&s->img_width, &s->img_height);
	s->img_path = "assets/player_left.xpm";
	s->img_player_left = mlx_xpm_file_to_image(s->init, s->img_path,
			&s->img_width, &s->img_height);
	s->img_path = "assets/player_right.xpm";
	s->img_player_right = mlx_xpm_file_to_image(s->init, s->img_path,
			&s->img_width, &s->img_height);
}*/

void	path_to_assets(t_s *s)
{
	s->img_path = "assets/floor.xpm";
	s->img_floor = mlx_xpm_file_to_image(s->init, s->img_path,
			&s->img_width, &s->img_height);
	s->img_path = "assets/wall.xpm";
	s->img_wall = mlx_xpm_file_to_image(s->init, s->img_path,
			&s->img_width, &s->img_height);
	s->img_path = "assets/exit_open.xpm";
	s->img_exit_open = mlx_xpm_file_to_image(s->init, s->img_path,
			&s->img_width, &s->img_height);
	s->img_path = "assets/exit_close.xpm";
	s->img_exit_close = mlx_xpm_file_to_image(s->init, s->img_path,
			&s->img_width, &s->img_height);
	s->img_path = "assets/collectible.xpm";
	s->img_collectible = mlx_xpm_file_to_image(s->init, s->img_path,
			&s->img_width, &s->img_height);
	s->img_path = NULL;
	if (!(s->img_floor || s->img_wall || s->img_exit_open || s->img_exit_close
			|| s->img_collectible))
		s->close_signal = 1;
}

void	put_assets(t_s *s, int keycode)
{
	path_to_assets(s);
	path_to_player_assets(s);
	put_image(s, keycode);
}
