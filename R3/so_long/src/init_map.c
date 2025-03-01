/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 20:03:26 by emonacho          #+#    #+#             */
/*   Updated: 2025/03/01 14:56:48 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_map_height(t_sl *sl)
{
	sl->map_height = 0;
	sl->map_line = get_next_line(sl->map_fd);
	while (sl->map_line)
	{
		sl->map_height++;
		free(sl->map_line);
		sl->map_line = get_next_line(sl->map_fd);
	}
	if (sl->map_height < 3)
	{
		free(sl->map_line);
		sl->map_error = 1;
		return ;
	}
	free(sl->map_line);
}

void	get_map_width(t_sl *sl)
{
	int	row;
	int	last_len;

	row = 0;
	last_len = -1;
	sl->map_width = 0;
	while (row < sl->map_height)
	{
		sl->map_line = get_next_line(sl->map_fd);
		sl->map_width = ft_strlen(sl->map_line) - 1;
		map_parsing(sl, row);
		free(sl->map_line);
		if (last_len == -1)
			last_len = sl->map_width;
		if (sl->map_width < 5 || last_len != sl->map_width || sl->map_error == 1)
		{
			sl->map_line = get_next_line(-1);
			free(sl->map_line);
			sl->map_error = 1;
			return ;
		}
		else
			last_len = sl->map_width;
		row++;
	}
}

int	map_copying(t_sl *sl, char **str_arr)
{
	int	i;

	i = 0;
	while (i < sl->map_height)
	{
		str_arr[i] = malloc(sizeof(char *) * sl->map_width);
		if (str_arr[i] == NULL)
			return (0);
		i++;
	}
	i = 0;
	while (i < sl->map_height)
	{
		sl->map_line = get_next_line(sl->map_fd);
		ft_strlcpy(str_arr[i], sl->map_line, sl->map_width + 1);
		free(sl->map_line);
		sl->map_line = NULL;
		i++;
	}
	return (1);
}

void	map_to_matrix(t_sl *sl, char *argv)
{
	sl->map = malloc(sizeof(char **) * sl->map_height);
	if (sl->map == NULL)
		exit(1);
	sl->map_copy = malloc(sizeof(char **) * sl->map_height);
	if (sl->map_copy == NULL)
	{
		free(sl->map);
		exit(1);
	}
	sl->map_fd = open(argv, O_RDONLY);
	if (!map_copying(sl, sl->map))
	{
		ft_free_array(sl->map, sl->map_height, 'c');
		exit(1);
	}
	close(sl->map_fd);
	sl->map_fd = open(argv, O_RDONLY);
	if (!map_copying(sl, sl->map_copy))
	{
		ft_free_array(sl->map, sl->map_height, 'c');
		ft_free_array(sl->map_copy, sl->map_height, 'c');
		exit(1);
	}
	close(sl->map_fd);
}

void	initialize_map(t_sl *sl, char *argv)
{
	sl->map_error = 0;
	sl->map_fd = open(argv, O_RDONLY);
	get_map_height(sl);
	close(sl->map_fd);
	sl->map_c_cnt = 0;
	sl->map_e_cnt = 0;
	sl->map_p_cnt = 0;
	sl->map_fd = open(argv, O_RDONLY);
	get_map_width(sl);
	close(sl->map_fd);
	if (sl->map_error == 1 || sl->map_width <= sl->map_height)
	{
		ft_printf("Error! Map is invalid.\n");
		exit(1);
	}
	map_to_matrix(sl, argv);
	map_backtracking(sl);
	print_map(sl);
}
