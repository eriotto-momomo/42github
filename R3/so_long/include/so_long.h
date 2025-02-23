/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:40:44 by emonacho          #+#    #+#             */
/*   Updated: 2025/02/23 19:07:45 by emonacho         ###   ########.fr       */
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

//check nombre de variable max dans une struct
typedef struct	s_solong
{
	void	*init; //initialize connection
	void	*win; //window
	int		close_signal;
	int		moves_cnt; //count WASD moves
	int		mouse_cnt; //count mouse inputs

	char	*img_path;
	void	*img_floor;
	void	*img_wall;
	void	*img_start;
	void	*img_end;
	int		img_width;
	int		img_height;

	int		map_width;
	int		map_height;

	int		bits_per_pixel; //img
	int		line_length; //img
	int		endian; // img

	int		x;
	int		y;
}			t_sl;

// sl_main.c
int		main(void);
int		close_and_quit(t_sl *sl);
int		close_signal(t_sl *sl);

// initialize.c
int		initialize_assets(t_sl *sl);

// inputs.c
int		key_and_mouse_inputs(t_sl *sl);

#endif
