/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 20:03:26 by emonacho          #+#    #+#             */
/*   Updated: 2025/02/27 21:58:11 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// sl->map_height	= axe Y
void	get_map_height(t_sl *sl, int *error)
{
	char	*line;

	sl->map_height = 0;
	line = get_next_line(sl->map_fd);
	while (line != NULL)
	{
		if (line == NULL)
		{
			free(line);
			break ;
		}
		sl->map_height++;
		free(line);
		line = get_next_line(sl->map_fd);
	}
	if (sl->map_height < 3)
	{
		free(line);
		*error = 1;
		return ;
	}
}

// sl->map_width	= axe X
void	get_map_width(t_sl *sl, int *error)
{
	int		row;
	int		last_len;
	char	*line;

	row = 0;
	last_len = -1;
	sl->map_width = 0;
	while (row < sl->map_height)
	{
		line = get_next_line(sl->map_fd);
		//////////////////////////////////////	Controle la validite de chaque ligne et compte le nombre de CEP
		map_parsing(sl, line, row, error);	//	ligne et compte le nombre de CEP.
		sl->map_width = ft_strlen(line) - 1;
		if (last_len == -1)
			last_len = sl->map_width;
		else if (sl->map_width < 5 || last_len != sl->map_width || *error == 1)
		{
			free(line);
			*error = 1;
			return ;
		}
		else
			last_len = sl->map_width;
		row++;
		free(line);
	}
}

int	map_copying(t_sl *sl, char **str_arr)
{
	int		i;
	char	*line;

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
		line = get_next_line(sl->map_fd);
		ft_strlcpy(str_arr[i], line, sl->map_width + 1);
		if (str_arr[i] == NULL)
		{
			free(line);
			return (0);
		}
		i++;
		free(line);
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

// IF MISSING LINES -> RETURN INT AND HANDLE ERROR IN MAIN
void	initialize_map(t_sl *sl, char *argv)
{
	int	i;
	int	error;

	error = 0;
	sl->map_fd = open(argv, O_RDONLY);
	get_map_height(sl, &error);
	close(sl->map_fd);
	sl->map_fd = open(argv, O_RDONLY);
	get_map_width(sl, &error);
	close(sl->map_fd);
	////////////////////////////////
	//map_parsing(sl, line, row, error); // A AJUSTER!!!!!!
	// check dans get_map_height
	if (error == 1 || sl->map_width <= sl->map_height)
	{
		ft_printf("Error! Map is invalid.\n");
		exit(1);
	}

	get_next_line(-1); //FREE GNL (marche pas pour le moment)
	printf("MAP DIMENSIONS SET\nsl->map_height(axe Y): %d\nsl->map_width (axe X): %d\n-------------------------\n", sl->map_height, sl->map_width);

	map_to_matrix(sl, argv);

	i = 0;
	while (i < sl->map_height)
	{
		printf("sl->map     : %s\n", sl->map[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (i < sl->map_height)
	{
		printf("sl->map_copy: %s\n", sl->map_copy[i]);
		i++;
	}
}
