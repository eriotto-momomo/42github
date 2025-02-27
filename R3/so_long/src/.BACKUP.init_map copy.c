/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .BACKUP.init_map copy.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 20:03:26 by emonacho          #+#    #+#             */
/*   Updated: 2025/02/27 19:25:03 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// NO MALLOC, CONNECTION OR WINDOW CREATED BEFORE, ONLY 'exit(1)' IS NEEDED
// sl->map_height	= axe Y
// sl->map_width	= axe X

// BACKUP v3 WORKING!
/*void	map_measurement(t_sl *sl, char *argv)
{
	int		cnt;
	int		tmp_len;
	char	*line;

	sl->map_fd = open(argv, O_RDONLY);
	sl->map_height = 0;
	while (line != NULL)
	{
		line = get_next_line(sl->map_fd);
		if (line == NULL)
		{
			free(line);
			break ;
		}
		sl->map_height++;
		free(line);
	}
	if (sl->map_height < 3)
	{
		free(line);
		exit(1);
	}
	close(sl->map_fd);

	sl->map_fd = open(argv, O_RDONLY);
	cnt = 0;
	tmp_len = 0;
	sl->map_width = 0;
	while (cnt < sl->map_height)
	{
		line = get_next_line(sl->map_fd);
		sl->map_width = ft_strlen(line) - 1;
		if (tmp_len == 0)
			tmp_len = sl->map_width;
		else if (sl->map_width < 5 || tmp_len != sl->map_width)
		{
			free(line);
			exit(1);
		}
		else
			tmp_len = sl->map_width;
		cnt++;
		free(line);
	}
	close(sl->map_fd);
}*/

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

void	map_get_width(t_sl *sl, int *error)
{
	int		cnt;
	int		last_len;
	char	*line;

	cnt = 0;
	last_len = -1;
	sl->map_width = 0;
	while (cnt < sl->map_height)
	{
		line = get_next_line(sl->map_fd);
		sl->map_width = ft_strlen(line) - 1;
		if (last_len == -1)
			last_len = sl->map_width;
		else if (sl->map_width < 5 || last_len != sl->map_width)
		{
			free(line);
			*error = 1;
			return ;
		}
		else
			last_len = sl->map_width;
		cnt++;
		free(line);
	}
}

// BACKUP v1 ATTENTION! COPIE LE '\n'
/*int	map_copying(t_sl *sl, char *argv, char **str_arr)
{
	int		i;

	i = 0;
	sl->map_fd = open(argv, O_RDONLY);
	while (i < sl->map_height)
	{
		str_arr[i] = ft_strdup(get_next_line(sl->map_fd));
		if (str_arr[i] == NULL)
			return (0);
		i++;
	}
	close(sl->map_fd);
	return (1);
}*/

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

// IS MISSING LINES -> RETURN INT AND HANDLE ERROR IN MAIN
void	initialize_map(t_sl *sl, char *argv)
{
	int	i;
	int	error;

	error = 0;
	sl->map_fd = open(argv, O_RDONLY);
	get_map_height(sl, &error);
	close(sl->map_fd);
	sl->map_fd = open(argv, O_RDONLY);
	map_get_width(sl, &error);
	close(sl->map_fd);
	if (error == 1)
	{
		ft_printf("Error! Map is invalid.\n");
		exit(1);
	}
	printf("MAP DIMENSIONS SET\nsl->map_height(axe Y): %d\nsl->map_width(axe X): %d\n-------------------------\n", sl->map_height, sl->map_width);
	map_to_matrix(sl, argv);


	// map parsing, check if:
	// - first and last string in arr contain only '1'
	// - first and last char in string is only '1'
	// - there's only one 'start' and 'end'
	// - there's at least one 'collectible'

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
