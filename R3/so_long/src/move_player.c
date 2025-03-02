/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:43:06 by emonacho          #+#    #+#             */
/*   Updated: 2025/03/02 17:18:55 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_walls(t_s *s, int keycode);
void	check_endgame_conditions(t_s *s);
void	refresh_matrix(t_s *s);

//if (keycode == A && s->map[s->player_y][s->player_x - 1] != '1'
//		&& s->map[s->player_y][s->player_x - 1] > s->map_width - s->map_width + 1)
void	check_walls(t_s *s, int keycode)
{
	if (keycode == W && s->map[s->player_y - 1][s->player_x] != '1')
	{
		s->map[s->player_y][s->player_x] = '0';
		s->map[s->player_y - 1][s->player_x] = 'P';
		s->player_y--;
	}
	else if (keycode == S && s->map[s->player_y + 1][s->player_x] != '1')
	{
		s->map[s->player_y][s->player_x] = '0';
		s->map[s->player_y + 1][s->player_x] = 'P';
		s->player_y++;
	}
	else if (keycode == D && s->map[s->player_y][s->player_x + 1] != '1')
	{
		s->map[s->player_y][s->player_x] = '0';
		s->map[s->player_y][s->player_x + 1] = 'P';
		s->player_x++;
	}
	else if (keycode == A && s->map[s->player_y][s->player_x - 1] != '1')
	{
		s->map[s->player_y][s->player_x] = '0';
		s->map[s->player_y][s->player_x - 1] = 'P';
		s->player_x--;
	}
}

void	move_player(t_s *s, int keycode)
{
	check_walls(s, keycode);
	//refresh_matrix(s);
	//check_endgame_conditions(s);
	put_assets(s);
}
