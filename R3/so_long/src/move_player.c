/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:43:06 by emonacho          #+#    #+#             */
/*   Updated: 2025/03/02 18:33:32 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_walls(t_s *s, int keycode);
/*void	check_endgame_conditions(t_s *s);

void	check_endgame_conditions(t_s *s)
{

}*/

void	refresh_matrix(t_s *s, int	*ptr, char c, char sign)
{
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

void	check_walls(t_s *s, int keycode)
{
	if (keycode == W && s->map[s->player_y - 1][s->player_x] != '1')
		refresh_matrix(s, &s->player_y, 'y', '-');
	else if (keycode == S && s->map[s->player_y + 1][s->player_x] != '1')
		refresh_matrix(s, &s->player_y, 'y', '+');
	else if (keycode == A && s->map[s->player_y][s->player_x - 1] != '1')
		refresh_matrix(s, &s->player_x, 'x', '-');
	else if (keycode == D && s->map[s->player_y][s->player_x + 1] != '1')
		refresh_matrix(s, &s->player_x, 'x', '+');
	else
		return ;
	(s->moves_cnt)++;
	ft_printf("Moves count: %d\n", s->moves_cnt);
}

void	move_player(t_s *s, int keycode)
{
	check_walls(s, keycode);
	//check_endgame_conditions(s);
	put_assets(s);
}
