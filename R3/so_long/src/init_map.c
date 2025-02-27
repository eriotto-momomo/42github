/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 20:03:26 by emonacho          #+#    #+#             */
/*   Updated: 2025/02/27 13:39:54 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// NO MALLOC, CONNECTION OR WINDOW CREATED BEFORE, ONLY 'exit(1)' IS NEEDED
// sl->map_height	= axe Y
// sl->map_width	= axe X
void	map_measurement(t_sl *sl, char *argv)
{
	int	cnt;
	int	tmp_len;

	sl->map_height = 0;
	while (get_next_line(sl->map_fd))
		sl->map_height++;
	if (sl->map_height < 3)
		exit(1);
	close(sl->map_fd);
	sl->map_fd = open(argv, O_RDONLY);
	cnt = 0;
	tmp_len = 0;
	sl->map_width = 0;
	while (cnt < sl->map_height)
	{
		sl->map_width = ft_strlen(get_next_line(sl->map_fd));
		if (tmp_len == 0)
			tmp_len = sl->map_width;
		else if (sl->map_width < 5 || tmp_len != sl->map_width)
			exit(1);
		else
			tmp_len = sl->map_width;
		cnt++;
	}
	close(sl->map_fd);
}

int	map_copying(t_sl *sl, char *argv, char **str_arr)
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
}

void	map_to_matrix(t_sl *sl, char *argv)
{
	sl->map = malloc(sizeof(char **) * sl->map_height);
	if (sl->map == NULL)
		exit(1);
	sl->map_copy = malloc(sizeof(char **) * sl->map_height);
	if (sl->map == NULL)
	{
		ft_free_array(sl->map, sl->map_height, 'c');
		exit(1);
	}
	if (!map_copying(sl, argv, sl->map))
	{
		ft_free_array(sl->map, sl->map_height, 'c');
		exit(1);
	}
	if (!map_copying(sl, argv, sl->map_copy))
	{
		ft_free_array(sl->map, sl->map_height, 'c');
		ft_free_array(sl->map_copy, sl->map_height, 'c');
		exit(1);
	}
}

void	initialize_map(t_sl *sl, char *argv)
{
	int	i;

	sl->map_fd = open(argv, O_RDONLY);
	map_measurement(sl, argv);
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
		printf("sl->map     : %s", sl->map[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (i < sl->map_height)
	{
		printf("sl->map_copy: %s", sl->map_copy[i]);
		i++;
	}
}
