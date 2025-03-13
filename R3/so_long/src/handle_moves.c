/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:43:06 by emonacho          #+#    #+#             */
/*   Updated: 2025/03/13 13:43:01 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	refresh_matrix(t_s *s, int	*ptr, char c, char sign)
{
	if (s->last_loc == 'E')
		s->map[s->player_y][s->player_x] = 'E';
	else
		s->map[s->player_y][s->player_x] = '0';
	if (c == 'y' && sign == '-')
		s->map[*ptr - 1][s->player_x] = 'P';
	else if (c == 'y' && sign == '+')
		s->map[*ptr + 1][s->player_x] = 'P';
	else if (c == 'x' && sign == '-')
		s->map[s->player_y][*ptr - 1] = 'P';
	else if (c == 'x' && sign == '+')
		s->map[s->player_y][*ptr + 1] = 'P';
	if (sign == '-')
		(*ptr)--;
	if (sign == '+')
		(*ptr)++;
}

int	check_exit(t_s *s, int keycode)
{
	if (keycode == W && s->map[s->player_y - 1][s->player_x] != '1'
		&& s->map[s->player_y - 1][s->player_x] == 'E')
		refresh_matrix(s, &s->player_y, 'y', '-');
	else if (keycode == S && s->map[s->player_y + 1][s->player_x] != '1'
		&& s->map[s->player_y + 1][s->player_x] == 'E')
		refresh_matrix(s, &s->player_y, 'y', '+');
	else if (keycode == A && s->map[s->player_y][s->player_x - 1] != '1'
		&& s->map[s->player_y][s->player_x - 1] == 'E')
		refresh_matrix(s, &s->player_x, 'x', '-');
	else if (keycode == D && s->map[s->player_y][s->player_x + 1] != '1'
		&& s->map[s->player_y][s->player_x + 1] == 'E')
		refresh_matrix(s, &s->player_x, 'x', '+');
	else
		return (0);
	s->last_loc = 'E';
	(s->moves_cnt)++;
	ft_printf("Moves: %d\n", s->moves_cnt);
	if (s->exit_status == 1)
	{
		ft_printf("LEVEL COMPLETED! King Star King ate all the waffles!\n");
		s->close_signal = 1;
		return (1);
	}
	return (1);
}

int	check_collectibles(t_s *s, int keycode)
{
	if (keycode == W && s->map[s->player_y - 1][s->player_x] != '1'
		&& s->map[s->player_y - 1][s->player_x] == 'C')
		refresh_matrix(s, &s->player_y, 'y', '-');
	else if (keycode == S && s->map[s->player_y + 1][s->player_x] != '1'
		&& s->map[s->player_y + 1][s->player_x] == 'C')
		refresh_matrix(s, &s->player_y, 'y', '+');
	else if (keycode == A && s->map[s->player_y][s->player_x - 1] != '1'
		&& s->map[s->player_y][s->player_x - 1] == 'C')
		refresh_matrix(s, &s->player_x, 'x', '-');
	else if (keycode == D && s->map[s->player_y][s->player_x + 1] != '1'
		&& s->map[s->player_y][s->player_x + 1] == 'C')
		refresh_matrix(s, &s->player_x, 'x', '+');
	else
		return (0);
	(s->moves_cnt)++;
	(s->map_c_cnt)--;
	if (s->map_c_cnt == 0)
		(s->exit_status) = 1;
	ft_printf("Moves: %d\n", s->moves_cnt);
	return (1);
}

void	move_player(t_s *s, int keycode)
{
	if (check_collectibles(s, keycode))
		return ;
	if (check_exit(s, keycode))
		return ;
	if (keycode == W && s->map[s->player_y - 1][s->player_x] != '1'
		&& s->map[s->player_y - 1][s->player_x] != 'E')
		refresh_matrix(s, &s->player_y, 'y', '-');
	else if (keycode == S && s->map[s->player_y + 1][s->player_x] != '1'
		&& s->map[s->player_y + 1][s->player_x] != 'E')
		refresh_matrix(s, &s->player_y, 'y', '+');
	else if (keycode == A && s->map[s->player_y][s->player_x - 1] != '1'
		&& s->map[s->player_y][s->player_x - 1] != 'E')
		refresh_matrix(s, &s->player_x, 'x', '-');
	else if (keycode == D && s->map[s->player_y][s->player_x + 1] != '1'
		&& s->map[s->player_y][s->player_x + 1] != 'E')
		refresh_matrix(s, &s->player_x, 'x', '+');
	else
		return ;
	s->last_loc = '0';
	(s->moves_cnt)++;
	ft_printf("Moves: %d\n", s->moves_cnt);
}

void	handle_moves(t_s *s, int keycode)
{
	move_player(s, keycode);
	remove_assets(s);
	put_assets(s, keycode);
}
