/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 20:03:26 by emonacho          #+#    #+#             */
/*   Updated: 2025/03/04 17:04:15 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_map_start(t_s *s, int *x, int *y)
{
	int	i;
	int	j;

	j = 0;
	while (j < s->map_height)
	{
		i = 0;
		while (s->map_copy[j][i])
		{
			if (s->map_copy[j][i] == 'P')
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
int	exit_is_reachable(t_s *s, int x, int y)
{
	if (x < 0 || y < 0 || x >= s->map_width || y >= s->map_height)
		return (0);
	if (s->map_copy[y][x] != '0' && s->map_copy[y][x] != 'C'
		&& s->map_copy[y][x] != 'E' && s->map_copy[y][x] != 'P')
		return (0);
	if (s->map_copy[y][x] == 'V')
		return (0);
	if (s->map_copy[y][x] == 'E')
		return (1);
	s->map_copy[y][x] = 'V';
	if (exit_is_reachable(s, x + 1, y))
		return (1);
	if (exit_is_reachable(s, x - 1, y))
		return (1);
	if (exit_is_reachable(s, x, y + 1))
		return (1);
	if (exit_is_reachable(s, x, y - 1))
		return (1);
	else
		return (0);
}

void	map_backtracking(t_s *s)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	get_map_start(s, &x, &y);
	s->player_x = x;
	s->player_y = y;
	if (!exit_is_reachable(s, x, y))
	{
		ft_free_array(s->map, s->map_height, 'c');
		ft_free_array(s->map_copy, s->map_height, 'c');
		write(2, "Error\n", 6);
		ft_printf("Map exit is not reachable!\n");
		exit(1);
	}
}

void	get_map_info(t_s *s, char c, int row)
{
	if (c == 'C')
		(s->map_c_cnt)++;
	if (c == 'E')
		(s->map_e_cnt)++;
	if (c == 'P')
		(s->map_p_cnt)++;
	if ((row == s->map_height - 1 && s->i == s->map_width - 1)
		&& (s->map_c_cnt < 1 || s->map_e_cnt != 1 || s->map_p_cnt != 1))
	{
		s->map_error = 1;
		return ;
	}
	(s->exit_status) = 0;
}

void	map_parsing(t_s *s, int row)
{
	s->i = 0;
	while (s->i < s->map_width)
	{
		if ((row == 0 || row == s->map_height - 1) && s->map_line[s->i] != '1')
		{
			s->map_error = 1;
			break ;
		}
		if (s->map_line[s->i] != '0' && s->map_line[s->i] != '1'
			&& s->map_line[s->i] != 'C' && s->map_line[s->i] != 'E'
			&& s->map_line[s->i] != 'P')
		{
			s->map_error = 1;
			break ;
		}
		if ((row > 0 && row < s->map_height - 1) && (s->map_line[0] != '1'
				|| s->map_line[s->map_width - 1] != '1'))
		{
			s->map_error = 1;
			break ;
		}
		get_map_info(s, s->map_line[s->i], row);
		s->i++;
	}
}
