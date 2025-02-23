/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:31:05 by emonacho          #+#    #+#             */
/*   Updated: 2025/02/23 19:31:01 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int put_assets(t_sl *sl)
{
	sl->x = 1;
	sl->y = 1;
	while (sl->x <= sl->img_width * sl->map_width && sl->y <= sl->img_height * sl->map_height)
	{
		mlx_put_image_to_window(sl->init, sl->win, sl->img_floor, sl->x, sl->y);
		sl->x += sl->img_width;
		//printf("sl->x = %d\n", sl->x);
		if (sl->x == sl->img_width * sl->map_width + 1)
		{
			//printf("sl->x = %d\n", sl->x);
			sl->y += sl->img_height;
			sl->x = 1;
		}
	}
	return (0);
}

int	initialize_assets(t_sl *sl)
{
	sl->img_path = "assets/floor.xpm";
	sl->img_floor = mlx_xpm_file_to_image(sl->init, sl->img_path,
		&sl->img_width, &sl->img_height);
	sl->img_path = "assets/wall.xpm";
	sl->img_wall = mlx_xpm_file_to_image(sl->init, sl->img_path,
		&sl->img_width, &sl->img_height);
	sl->img_path = "assets/start.xpm";
	sl->img_start = mlx_xpm_file_to_image(sl->init, sl->img_path,
		&sl->img_width, &sl->img_height);
	sl->img_path = "assets/end.xpm";
	sl->img_end = mlx_xpm_file_to_image(sl->init, sl->img_path,
		&sl->img_width, &sl->img_height);

	//printf("texture ptr = %p\n", sl->floor);
	if (!(sl->img_floor || sl->img_wall || sl->img_start || sl->img_end))
	{
		// FONCTION QUI FREE TOUT TANT QUE LA CIBLE N'EST PAS NULL
		sl->close_signal = 1;
	}
	//mlx_put_image_to_window(sl->init, sl->win, sl->img_floor, 0, 0);
	put_assets(sl);
	return (0);
}
