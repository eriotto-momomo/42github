#include "../minilibx/mlx.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel; //bpp
	int		line_length;
	int		endian;

	int		x; //img
	int		y; //img
	int		size_x; //img
	int		size_y; //img
}			t_img;

typedef struct	s_data
{
	void	*connection;
	void	*win;
	int		moves_cnt; //count WASD moves
	int		mouse_cnt; //count mouse inputs

}			t_data;

int	close(t_data *data)
{
	mlx_destroy_window(data->connection, data->win);
	//fonction qui free tout avant de fermer
	exit(1);
}

int	deal_key(int keycode, void *param)
{
	t_data	*data; //casting de param en structure afin d'eviter de multiples casting

	data = (t_data *)param;
	if (!(keycode == 119 || keycode == 97 || keycode == 115 || keycode == 100))
		printf("keyboard input: %d\n", keycode);
	if (keycode == 119 || keycode == 97 || keycode == 115 || keycode == 100)
	{
		(data->moves_cnt)++;
		printf("WASD moves = %d\n", data->moves_cnt);
	}
	if (keycode == 113)
		close(data);
	return (0);
}

int	deal_mouse(int button, int x, int y, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	(data->mouse_cnt)++;
	printf("mouse input: %d\nx = %d\ny = %d\n", button, x, y);
	return (0);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	t_img	img;
	t_data	data;

	data.moves_cnt = 0;
	data.mouse_cnt = 0; //probably useless
	data.connection = mlx_init();
	data.win = mlx_new_window(data.connection, 1920, 1080, "Hello World!");
	img.img = mlx_new_image(data.connection, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	img.y = 0;
	img.x = 0;
	img.size_y = 200;
	img.size_x = 200;
	while (img.y < img.size_y && img.y < 960)
	{
		while (img.x < img.size_x && img.x < 540)
		{
			my_mlx_pixel_put(&img, img.x, img.y, 0x00FFFFFF);
			img.x++;
		}
		img.x = 0;
		img.y++;
	}
	mlx_put_image_to_window(data.connection, data.win, img.img, 960, 540);
	mlx_key_hook(data.win, deal_key, &data); // handle WASD and Q
	mlx_mouse_hook(data.win, deal_mouse, &data);
	mlx_hook(data.win, 17, 0L, close, &data);
	mlx_loop(data.connection);
}
