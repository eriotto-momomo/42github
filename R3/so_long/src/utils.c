/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:25:42 by emonacho          #+#    #+#             */
/*   Updated: 2025/03/03 00:05:52 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_args(int argc, char *argv[])
{
	int	i;

	if (argc != 2)
	{
		write(2, "Error\n", 6);
		ft_printf("Invalid number of arguments!\n");
		exit (1);
	}
	i = 0;
	while (argv[1][i] != '\0')
		i++;
	if (argv[1][i - 4] == '.' && argv[1][i - 3] != 'b'
		&& argv[1][i - 2] != 'e' && argv[1][i - 1] != 'r')
	{
		write(2, "Error\n", 6);
		ft_printf("Invalid map format!\n");
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

int	close_and_quit(t_s *s)
{
	ft_free_array(s->map, s->map_height, 'c');
	ft_free_array(s->map_copy, s->map_height, 'c');
	mlx_destroy_image(s->init, s->img_floor);
	mlx_destroy_image(s->init, s->img_wall);
	mlx_destroy_image(s->init, s->img_exit_open);
	mlx_destroy_image(s->init, s->img_exit_close);
	mlx_destroy_image(s->init, s->img_collectible);
	mlx_destroy_image(s->init, s->img_player_up);
	mlx_destroy_image(s->init, s->img_player_down);
	mlx_destroy_image(s->init, s->img_player_left);
	mlx_destroy_image(s->init, s->img_player_right);
	mlx_destroy_window(s->init, s->win);
	mlx_destroy_display(s->init);
	free(s->init);
	exit(1);
}

void	print_map(t_s *s)
{
	ft_printf("---CURRENT MAP---\n");
	s->i = 0;
	while (s->i < s->map_height)
	{
		ft_printf("| %s |\n", s->map[s->i]);
		s->i++;
	}
	ft_printf("-----------------\n");
}
