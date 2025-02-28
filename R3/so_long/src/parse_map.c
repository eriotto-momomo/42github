/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 20:03:26 by emonacho          #+#    #+#             */
/*   Updated: 2025/02/27 20:10:57 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	map_count_characters(t_sl *sl, char c, int row, int *error)
{
	if (c == 'C')
		sl->map_c_cnt++;
	if (c == 'E')
		sl->map_e_cnt++;
	if (c == 'P')
		sl->map_p_cnt++;
	//printf("row = %d\nsl->map_height = %d\nsl->i = %d\nsl->map_width = %d\n", row, sl->map_height, sl->i, sl->map_width);
	if ((row == sl->map_height - 1 && sl->i == sl->map_width - 1)
		&& (sl->map_c_cnt < 1 || sl->map_e_cnt != 1 || sl->map_p_cnt != 1))
	{
			*error = 1;
			return ;
	}
}

void	map_parsing(t_sl *sl, int row, int *error)
{
	sl->i = 0;
	while (sl->i < sl->map_width)
	{
		if ((row == 0 || row == sl->map_height - 1) && sl->map_line[sl->i] != '1')
		{
			*error = 1;
			break;
		}
		if (sl->map_line[sl->i] != '0' && sl->map_line[sl->i] != '1'
			&& sl->map_line[sl->i] != 'C' && sl->map_line[sl->i] != 'E'
				&& sl->map_line[sl->i] != 'P')
		{
			*error = 1;
			break;
		}
		if ((row > 0 && row < sl->map_height - 1) && (sl->map_line[0] != '1'
		|| sl->map_line[sl->map_width - 1] != '1'))
		{
			*error = 1;
			break;
		}
		map_count_characters(sl, sl->map_line[sl->i], row, error);
		sl->i++;
	}
}
