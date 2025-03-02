/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 20:03:26 by emonacho          #+#    #+#             */
/*   Updated: 2025/03/02 16:40:06 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_map_height(t_s *s)
{
	s->map_height = 0;
	s->map_line = get_next_line(s->map_fd);
	while (s->map_line)
	{
		s->map_height++;
		free(s->map_line);
		s->map_line = get_next_line(s->map_fd);
	}
	if (s->map_height < 3)
	{
		free(s->map_line);
		s->map_error = 1;
		return ;
	}
	free(s->map_line);
}

void	get_map_width(t_s *s)
{
	int	row;
	int	last_len;

	row = 0;
	last_len = -1;
	s->map_width = 0;
	while (row < s->map_height)
	{
		s->map_line = get_next_line(s->map_fd);
		s->map_width = ft_strlen(s->map_line) - 1;
		map_parsing(s, row);
		free(s->map_line);
		if (last_len == -1)
			last_len = s->map_width;
		if (s->map_width < 5 || last_len != s->map_width || s->map_error == 1)
		{
			s->map_line = get_next_line(-1);
			free(s->map_line);
			s->map_error = 1;
			return ;
		}
		else
			last_len = s->map_width;
		row++;
	}
}

int	map_copying(t_s *s, char **str_arr)
{
	int	i;

	i = 0;
	while (i < s->map_height)
	{
		str_arr[i] = malloc(sizeof(char *) * s->map_width);
		if (str_arr[i] == NULL)
			return (0);
		i++;
	}
	i = 0;
	while (i < s->map_height)
	{
		s->map_line = get_next_line(s->map_fd);
		ft_strlcpy(str_arr[i], s->map_line, s->map_width + 1);
		free(s->map_line);
		s->map_line = NULL;
		i++;
	}
	return (1);
}

void	map_to_matrix(t_s *s, char *argv)
{
	s->map = malloc(sizeof(char **) * s->map_height);
	if (s->map == NULL)
		exit(1);
	s->map_copy = malloc(sizeof(char **) * s->map_height);
	if (s->map_copy == NULL)
	{
		free(s->map);
		exit(1);
	}
	s->map_fd = open(argv, O_RDONLY);
	if (!map_copying(s, s->map))
	{
		ft_free_array(s->map, s->map_height, 'c');
		exit(1);
	}
	close(s->map_fd);
	s->map_fd = open(argv, O_RDONLY);
	if (!map_copying(s, s->map_copy))
	{
		ft_free_array(s->map, s->map_height, 'c');
		ft_free_array(s->map_copy, s->map_height, 'c');
		exit(1);
	}
	close(s->map_fd);
}

void	initialize_map(t_s *s, char *argv)
{
	s->map_error = 0;
	s->map_fd = open(argv, O_RDONLY);
	get_map_height(s);
	close(s->map_fd);
	s->map_c_cnt = 0;
	s->map_e_cnt = 0;
	s->map_p_cnt = 0;
	s->map_fd = open(argv, O_RDONLY);
	get_map_width(s);
	close(s->map_fd);
	if (s->map_error == 1 || s->map_width <= s->map_height)
	{
		ft_printf("Error! Map is invalid.\n");
		exit(1);
	}
	map_to_matrix(s, argv);
	map_backtracking(s);
	print_map(s);
}
