/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:40:44 by emonacho          #+#    #+#             */
/*   Updated: 2025/03/02 18:24:45 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

//# define IMG_W 32
//# define IMG_H 32
# define ESC 65307
# define Q 113
# define W 119
# define A 97
# define S 115
# define D 100
# define UARROW 65362
# define LARROW 65361
# define DARROW 65364
# define RARROW 65363
# define UP -1
# define DOWN 1
# define LEFT -1
# define RIGHT 1

typedef struct	s_solong
{
	void	*init;
	void	*win;
	int		close_signal;
	int		moves_cnt; //count WASD moves
	int		mouse_cnt; //count mouse inputs

	char	*img_path;
	void	*img_floor;
	void	*img_wall;
	void	*img_start;
	void	*img_exit;
	void	*img_collectible;
	void	*img_player;
	int		img_width;
	int		img_height;
	int		img_x;
	int		img_y;
	int		bits_per_pixel; // img USELESS?
	int		line_length; // img USELESS?
	int		endian; // img USELESS?

	char	**map;
	char	**map_copy;
	char	*map_line;
	int		map_error;
	int		map_fd;
	int		map_width;
	int		map_height;
	int		map_x;
	int		map_y;
	int		map_c_cnt;
	int		map_e_cnt;
	int		map_p_cnt;
	char	map_last_location;

	int		player_x;
	int		player_y;

	int		i;
}			t_s;

// put_assets.c
void	put_assets(t_s *s);

// init_map.c
void	initialize_map(t_s *s, char *argv);

// inputs.c
int		key_and_mouse_inputs(t_s *s);

// main.c
int		main(int argc, char *argv[]);
int		close_and_quit(t_s *s);
int		close_signal(t_s *s);

// move_player.c
void	move_player(t_s *s, int keycode);

// parse_map.c
void	map_parsing(t_s *s, int row);
void	map_backtracking(t_s *s);

//utils.c
void	print_map(t_s *s);

#endif
