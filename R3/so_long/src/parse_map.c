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

void	get_map_start(t_sl *sl, int *x, int *y)
{
	int	i;
	int	j;

	j = 0;
	while (j < sl->map_height)
	{
		i = 0;
		while (sl->map_copy[j][i])
		{
			if (sl->map_copy[j][i] == 'P')
			{
				*x = i;
				*y = j;
				return ;
			}
			i++;
		}
		j++;
	}
}

// Flood Fill DFS (Depth-First Search)
// 'V' stands for "VISITED", as the algorithm go throuh the map,
// it'll mark locations of the matrix already visited.
int	exit_is_reachable(t_sl *sl, int x, int y)
{
	if (x < 0 || y < 0 || x >= sl->map_width || y >= sl->map_height)
		return (0);
	if (sl->map_copy[y][x] != '0' && sl->map_copy[y][x] != 'C'
		&& sl->map_copy[y][x] != 'E' && sl->map_copy[y][x] != 'P')
		return (0);
	if (sl->map_copy[y][x] == 'V')
		return (0);
	if (sl->map_copy[y][x] == 'E')
		return (1);
	sl->map_copy[y][x] = 'V';
	if (exit_is_reachable(sl, x + 1, y))
		return (1);
	if (exit_is_reachable(sl, x - 1, y))
		return (1);
	if (exit_is_reachable(sl, x, y + 1))
		return (1);
	if (exit_is_reachable(sl, x, y - 1))
		return (1);
	else
		return (0);
}

void	map_backtracking(t_sl *sl)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	get_map_start(sl, &x, &y);
	if (!exit_is_reachable(sl, x, y))
	{
		ft_free_array(sl->map, sl->map_height, 'c');
		ft_free_array(sl->map_copy, sl->map_height, 'c');
		ft_printf("Error! Map exit is not reachable.\n");
		exit(1);
	}
	else
		ft_printf("Map is valid! Enjoy your game! :D\n");
}

void	get_map_info(t_sl *sl, char c, int row)
{
	if (c == 'C')
		sl->map_c_cnt++;
	if (c == 'E')
		sl->map_e_cnt++;
	if (c == 'P')
		sl->map_p_cnt++;
	if ((row == sl->map_height - 1 && sl->i == sl->map_width - 1)
		&& (sl->map_c_cnt < 1 || sl->map_e_cnt != 1 || sl->map_p_cnt != 1))
	{
			sl->map_error = 1;
			return ;
	}
}

void	map_parsing(t_sl *sl, int row)
{
	sl->i = 0;
	while (sl->i < sl->map_width)
	{
		if ((row == 0 || row == sl->map_height - 1) && sl->map_line[sl->i] != '1')
		{
			sl->map_error = 1;
			break;
		}
		if (sl->map_line[sl->i] != '0' && sl->map_line[sl->i] != '1'
			&& sl->map_line[sl->i] != 'C' && sl->map_line[sl->i] != 'E'
				&& sl->map_line[sl->i] != 'P')
		{
			sl->map_error = 1;
			break;
		}
		if ((row > 0 && row < sl->map_height - 1) && (sl->map_line[0] != '1'
		|| sl->map_line[sl->map_width - 1] != '1'))
		{
			sl->map_error = 1;
			break;
		}
		get_map_info(sl, sl->map_line[sl->i], row);
		sl->i++;
	}
}
