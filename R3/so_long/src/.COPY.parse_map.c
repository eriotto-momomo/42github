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
	static int	c_count; // STATIC POUR PARCOURIR TOUTE LA CARTE
	static int	e_count;
	static int	p_count;

	c_count = 0;
	e_count = 0;
	p_count = 0;
	if (c == 'C')
		c_count++;
	if (c == 'E')
		e_count++;
	if (c == 'P')
		p_count++;
	if ((row == sl->map_height) && (c_count < 1 || e_count != 1 || p_count != 1))
	//if ((row == sl->map_height + 1) && (c_count < 1 || e_count != 1 || p_count != 1)) ????
	{
			*error = 1;
			return ;
	}
}

void	map_check_characters(t_sl *sl, char *line, int row, int *error)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '0' || line[i] != '1' || line[i] != 'C' || line[i] != 'E' || line[i] != 'P')
		{
			*error = 1;
			break;
		}
		//if (((row == 0 || row == sl->map_height) && line[i] != '1') || (line[i] != '0'
		//|| line[i] != '1' || line[i] != 'C' || line[i] != 'E' || line[i] != 'P'))
		//if ((row == 0 || row == sl->map_height) && line[i] != '1') ????
		if ((row == 0 || row == sl->map_height) && line[i] != '1')
		{
			*error = 1;
			break;
		}
		if ((row > 0 || row < sl->map_height) && (line[0] != '1'
		&& line[sl->map_width] != '1'))
		{
			*error = 1;
			break;
		}
		i++;
	}
}

// map parsing, check if:
// - first and last string in arr contain only '1'
// - first and last char in string is only '1'
// - there's only one 'start' and 'end'
// - there's at least one 'collectible'
void	map_parsing(t_sl *sl, char *line, int row, int *error)
{
	map_check_characters(sl, line, row, error);
	map_count_characters(sl, line, row, error); // MAKE IT STATIC BABYYYYY
}

/*void	map_count_characters(t_sl *sl, char *line, int row, int *error)
{
	int	i;
	static int	c_count; // STATIC POUR PARCOURIR TOUTE LA CARTE
	static int	e_count;
	static int	p_count;

	c_count = 0;
	e_count = 0;
	p_count = 0;
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == 'C')
			c_count++;
		if (line[i] == 'E')
			e_count++;
		if (line[i] == 'P')
			p_count++;
		i++;
	}
	if ((row == sl->map_height) && (c_count < 1 || e_count != 1 || p_count != 1))
	{
			*error = 1;
			return ;
	}
}

void	map_check_characters(t_sl *sl, char *line, int row, int *error)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '0' || line[i] != '1' || line[i] != 'C' || line[i] != 'E' || line[i] != 'P')
		{
			*error = 1;
			break;
		}
		if (((row == 0 || row == sl->map_height) && line[i] != '1') || (line[i] != '0'
		|| line[i] != '1' || line[i] != 'C' || line[i] != 'E' || line[i] != 'P'))
		{
			*error = 1;
			break;
		}
		if ((row > 0 || row < sl->map_height) && (line[0] != '1'
		&& line[sl->map_width] != '1'))
		{
			*error = 1;
			break;
		}
		i++;
	}
}

// map parsing, check if:
// - first and last string in arr contain only '1'
// - first and last char in string is only '1'
// - there's only one 'start' and 'end'
// - there's at least one 'collectible'
void	map_parsing(t_sl *sl, char *line, int row, int *error)
{
	map_check_characters(sl, line, row, error);
	map_count_characters(sl, line, row, error); // MAKE IT STATIC BABYYYYY
}*/