/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_assets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:31:05 by emonacho          #+#    #+#             */
/*   Updated: 2025/03/11 19:26:33 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	remove_assets(t_s *s)
{
	if (s->img_floor != NULL)
		destroy_img(s, s->img_floor);
	if (s->img_wall != NULL)
		destroy_img(s, s->img_wall);
	if (s->img_exit_open != NULL)
		destroy_img(s, s->img_exit_open);
	if (s->img_collectible != NULL)
		destroy_img(s, s->img_collectible);
	if (s->img_player_w != NULL)
		destroy_img(s, s->img_player_w);
	if (s->img_player_s != NULL)
		destroy_img(s, s->img_player_s);
	if (s->img_player_a != NULL)
		destroy_img(s, s->img_player_a);
	if (s->img_player_d != NULL)
		destroy_img(s, s->img_player_d);
}

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
			ptr = s->img_player_w;
		else if (keycode == A)
			ptr = s->img_player_a;
		else if (keycode == D)
			ptr = s->img_player_d;
		else
			ptr = s->img_player_s;
	}
	else if (c == 'E' && s->exit_status == 0)
		ptr = s->img_floor;
	else if (c == 'E' && s->exit_status == 1)
		ptr = s->img_exit_open;
	mlx_put_image_to_window(s->init, s->win, ptr, s->img_x, s->img_y);
	s->img_x += s->img_width;
}

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

void	path_to_assets(t_s *s)
{
	s->img_player_w = mlx_xpm_file_to_image(s->init,
			"assets/player_w.xpm", &s->img_width, &s->img_height);
	s->img_player_s = mlx_xpm_file_to_image(s->init,
			"assets/player_s.xpm", &s->img_width, &s->img_height);
	s->img_player_a = mlx_xpm_file_to_image(s->init,
			"assets/player_a.xpm", &s->img_width, &s->img_height);
	s->img_player_d = mlx_xpm_file_to_image(s->init,
			"assets/player_d.xpm", &s->img_width, &s->img_height);
	s->img_floor = mlx_xpm_file_to_image(s->init,
			"assets/floor.xpm", &s->img_width, &s->img_height);
	s->img_wall = mlx_xpm_file_to_image(s->init,
			"assets/wall.xpm", &s->img_width, &s->img_height);
	s->img_exit_open = mlx_xpm_file_to_image(s->init,
			"assets/exit_open.xpm", &s->img_width, &s->img_height);
	s->img_collectible = mlx_xpm_file_to_image(s->init,
			"assets/collectible.xpm", &s->img_width, &s->img_height);
	if (!(s->img_player_w || s->img_player_s || s->img_player_a
			|| s->img_player_d || s->img_floor || s->img_wall
			|| s->img_exit_open || s->img_collectible))
		s->close_signal = 1;
}

void	put_assets(t_s *s, int keycode)
{
	path_to_assets(s);
	put_image(s, keycode);
	display_moves_and_collectibles(s);
}
