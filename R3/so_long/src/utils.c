/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:25:42 by emonacho          #+#    #+#             */
/*   Updated: 2025/03/11 20:12:34 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_args(int argc, char *argv[])
{
	int	i;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nInvalid number of arguments!\n", 2);
		exit (1);
	}
	i = 0;
	while (argv[1][i] != '\0')
		i++;
	if (argv[1][i - 4] == '.' && argv[1][i - 3] != 'b'
		&& argv[1][i - 2] != 'e' && argv[1][i - 1] != 'r')
	{
		ft_putstr_fd("Error\nInvalid map format!\n", 2);
		exit (1);
	}
}

int	close_signal(t_s *s)
{
	if (s->close_signal == 1)
	{
		close_and_quit(s);
		return (-1);
	}
	return (0);
}

void	destroy_img(t_s *s, void *ptr)
{
	mlx_destroy_image(s->init, ptr);
	ptr = NULL;
}

int	close_and_quit(t_s *s)
{
	ft_free_array(s->map, s->map_height, 'c');
	ft_free_array(s->map_copy, s->map_height, 'c');
	remove_assets(s);
	mlx_destroy_window(s->init, s->win);
	mlx_destroy_display(s->init);
	free(s->init);
	exit(1);
}
