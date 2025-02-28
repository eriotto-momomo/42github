/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 20:03:26 by emonacho          #+#    #+#             */
/*   Updated: 2025/02/28 18:34:02 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// sl->map_height = axe Y
void	get_map_height(t_sl *sl, int *error)
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
		*error = 1;
		return ;
	}
	free(sl->map_line);
}

// sl->map_width = axe X
void	get_map_width(t_sl *sl, int *error)
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
		map_parsing(sl, row, error);
		if (last_len == -1)
			last_len = sl->map_width;
		if (sl->map_width < 5 || last_len != sl->map_width || *error == 1)
		{
			printf("ERROR = %d\n", *error);
			//sl->map_line = get_next_line(-1); // FREE GNL -> fonctionne seulement si GNL l'autorise
			free(sl->map_line);
			*error = 1;
			return ;
		}
		else
			last_len = sl->map_width;
		row++;
		free(sl->map_line);
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
		/*if (str_arr[i] == NULL) // USELESS ?
		{
			free(sl->map_line);
			return (0);
		}*/
		free(sl->map_line);
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

// FINAL
/*void	initialize_map(t_sl *sl, char *argv)
{
	int	error;

	error = 0;
	sl->map_fd = open(argv, O_RDONLY);
	get_map_height(sl, &error);
	close(sl->map_fd);
	sl->map_c_cnt = 0;
	sl->map_e_cnt = 0;
	sl->map_p_cnt = 0;
	sl->map_fd = open(argv, O_RDONLY);
	get_map_width(sl, &error);
	close(sl->map_fd);
	if (error == 1 || sl->map_width <= sl->map_height)
	{
		ft_printf("Error! Map is invalid.\n");
		exit(1);
	}
	get_next_line(-1); //FREE GNL (marche pas pour le moment)
	map_to_matrix(sl, argv);
}*/

//BACKUP WITH DEBUG
void	initialize_map(t_sl *sl, char *argv)
{
	int	i;
	int	error;

	error = 0;
	sl->map_fd = open(argv, O_RDONLY);
	get_map_height(sl, &error);
	close(sl->map_fd);
	sl->map_c_cnt = 0;
	sl->map_e_cnt = 0;
	sl->map_p_cnt = 0;
	sl->map_fd = open(argv, O_RDONLY);
	get_map_width(sl, &error);
	close(sl->map_fd);
	if (error == 1 || sl->map_width <= sl->map_height)
	{
		ft_printf("Error! Map is invalid.\n");
		exit(1);
	}
	get_next_line(-1); //FREE GNL (marche pas pour le moment)
	printf("MAP DIMENSIONS SET\nsl->map_height(axe Y): %d\nsl->map_width (axe X): %d\n-------------------------\n", sl->map_height, sl->map_width);

	map_to_matrix(sl, argv);
	//FLOOD FILL

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
