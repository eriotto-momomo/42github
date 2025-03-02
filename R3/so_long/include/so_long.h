/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:40:44 by emonacho          #+#    #+#             */
/*   Updated: 2025/03/02 20:17:20 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define ESC 65307
# define Q 113
# define W 119
# define A 97
# define S 115
# define D 100

typedef struct s_solong
{
	void	*init;
	void	*win;
	int		close_signal;
	int		moves_cnt;

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

	int		player_x;
	int		player_y;

	int		i;
}			t_s;

// handle_moves.c
void	handle_moves(t_s *s, int keycode);
void	move_player(t_s *s, int keycode);
int		check_collectibles(t_s *s, int keycode);
int		check_exit(t_s *s, int keycode);
void	refresh_matrix(t_s *s, int	*ptr, char c, char sign);

// init_map.c
void	initialize_map(t_s *s, char *argv);
void	map_to_matrix(t_s *s, char *argv);
int		map_copying(t_s *s, char **str_arr);
void	get_map_width(t_s *s);
void	get_map_height(t_s *s);

// inputs.c
int		deal_key(int keycode, void *param);
int		key_and_mouse_inputs(t_s *s);

// main.c
int		main(int argc, char *argv[]);

// parse_map.c
void	get_map_start(t_s *s, int *x, int *y);
int		exit_is_reachable(t_s *s, int x, int y);
void	map_backtracking(t_s *s);
void	get_map_info(t_s *s, char c, int row);
void	map_parsing(t_s *s, int row);

// put_assets.c
void	choose_asset(t_s *s, char c);
void	put_image(t_s *s);
void	path_to_assets(t_s *s);
void	put_assets(t_s *s);

//utils.c
void	check_args(int argc, char *argv[]);
int		close_signal(t_s *s);
int		close_and_quit(t_s *s);
void	print_map(t_s *s);

#endif
