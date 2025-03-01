/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:31:05 by emonacho          #+#    #+#             */
/*   Updated: 2025/03/01 18:36:19 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//&& (sl->map_x != sl->map_width && sl->map_y != sl->map_height)
/*int put_assets(t_sl *sl)
{
	while ((sl->img_x <= sl->img_width * sl->map_width
		&& sl->img_y <= sl->img_height * sl->map_height))
	{
		if (sl->map[sl->map_y][sl->map_x] == '1')
		{
			mlx_put_image_to_window(sl->init, sl->win, sl->img_wall, sl->img_x, sl->img_y);
			sl->img_x += sl->img_width;
		}
		if (sl->map[sl->map_y][sl->map_x] == '0')
		{
			mlx_put_image_to_window(sl->init, sl->win, sl->img_floor, sl->img_x, sl->img_y);
			sl->img_x += sl->img_width;
		}
		if (sl->img_x == sl->img_width * sl->map_width + 1)
		{
			sl->img_y += sl->img_height;
			sl->img_x = 1;
		}
		sl->map_x++;
		sl->map_y++;
	}
	return (0);
}*/

int put_assets(t_sl *sl)
{
	while ((sl->img_x <= sl->img_width * sl->map_width
		&& sl->img_y <= sl->img_height * sl->map_height))
	{
		mlx_put_image_to_window(sl->init, sl->win, sl->img_floor, sl->img_x, sl->img_y);
		sl->img_x += sl->img_width;
		if (sl->img_x == sl->img_width * sl->map_width + 1)
		{
			sl->img_y += sl->img_height;
			sl->img_x = 1;
		}
	}
	return (0);
}

void	path_to_assets(t_sl *sl)
{
	sl->img_path = "assets/floor.xpm";
	sl->img_floor = mlx_xpm_file_to_image(sl->init, sl->img_path,
		&sl->img_width, &sl->img_height);
	sl->img_path = "assets/wall.xpm";
	sl->img_wall = mlx_xpm_file_to_image(sl->init, sl->img_path,
		&sl->img_width, &sl->img_height);
	sl->img_path = "assets/exit.xpm";
	sl->img_exit = mlx_xpm_file_to_image(sl->init, sl->img_path,
		&sl->img_width, &sl->img_height);
	sl->img_path = "assets/collectible.xpm";
	sl->img_collectible = mlx_xpm_file_to_image(sl->init, sl->img_path,
		&sl->img_width, &sl->img_height);
	sl->img_path = "assets/player.xpm";
	sl->img_player = mlx_xpm_file_to_image(sl->init, sl->img_path,
		&sl->img_width, &sl->img_height);
	sl->img_path = NULL;
	if (!(sl->img_floor || sl->img_wall || sl->img_exit || sl->img_collectible
		|| sl->img_player))
		sl->close_signal = 1;
}

void	initialize_assets(t_sl *sl)
{
	sl->img_x = 1;
	sl->img_y = 1;
	sl->map_x = 0;
	sl->map_y = 0;
	path_to_assets(sl);
	put_assets(sl);
}
