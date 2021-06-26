/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:05:51 by jpyo              #+#    #+#             */
/*   Updated: 2021/06/26 16:26:32 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}

int	press_key(int key, t_data *data)
{
	printf("Key in digit : %d\n", key);
	if (key == KEY_ESC)
		exit(0);
	/*
	else if (key == KEY_PAGE_UP)
	{
	}
	else if (key == KEY_PAGE_DOWN)
	{
	}
	else if (key == KEY_UP)
	{
	}
	*/
	return (0);
}

int	sl_loop(t_data *data)
{
	return (0);
}

int main(void)
{
	t_data		data;
	t_img_data	img;
	void		*img_ptr;
	int			width = FONT_WIDTH * 14;
	int			height = 20 * 5;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 500, 500, "so_long");

	//img.ptr = mlx_new_image(data.mlx, width, height);
	img_ptr = mlx_xpm_file_to_image(data.mlx, "./images/wall.xpm", &width, &height);
	//img.addr = mlx_get_data_addr(img.ptr, &img.bpp, &img.size, &img.endian);
	//img.color = (255 << 16) + (255 << 8) + 255;
	mlx_put_image_to_window(data.mlx, data.win, img_ptr, 10, 10);
	data.img.ptr = mlx_xpm_file_to_image(data.mlx, "./images/dolphin.xpm", &width, &height);
	mlx_put_image_to_window(data.mlx, data.win, data.img.ptr, 10, 10);
	mlx_destroy_image(data.mlx, img_ptr);
	//mlx_string_put(data.mlx, data.win, 0, 12, img.color, "1111111111111");
	//mlx_string_put(data.mlx, data.win, 0, 32, img.color, "10010000000C1");
	//mlx_string_put(data.mlx, data.win, 0, 52, img.color, "1000011111001");
	//mlx_string_put(data.mlx, data.win, 0, 72, img.color, "1P0011E000001");
	//mlx_string_put(data.mlx, data.win, 0, 92, img.color, "1111111111111");
	//mlx_string_put(mlx, win, 0, 719, img.color, "double");
	mlx_hook(data.win, DESTROYNOTIFY, 0, ft_close, &data);
	mlx_hook(data.win, KEYPRESS, KEYPRESS_MASK, press_key, &data);
	//mlx_loop_hook(data.mlx, sl_loop, &data);
	mlx_loop(data.mlx);
	return (0);
}

/*
int	my_mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string)
{
	static void *font = (void *)0;
	static unsigned char *data = (void *)0;
	static int size_line = 0;
	int bpp;
	int endian;
	int pos;
	int val;
	int dest_w;
	int dest_h;

	if (font == (void *)0)
	{
		font = mlx_new_image(mlx_ptr, font_atlas.width, font_atlas.height);
		data = (unsigned char *)mlx_get_data_addr(font, &bpp, &size_line, &endian);
		mlx_int_fill(data, size_line);
	}

	color = (color & 0xFFFFFF) | 0xFF000000;

	//  dest_w = (FONT_WIDTH*5)/7;   /// ratio with X11 standard mlx_string_put
	//  dest_h = (font_atlas.height*5)/7;
	dest_w = FONT_WIDTH;
	dest_h = font_atlas.height;
	y = y - (dest_h*3)/4;

	pos = 0;
	while (*string)
	{
		if (*string >= 32 && *string <= 127)
			val = *string - 32;
		else
			val = 31;
		mlx_put_image_to_window_scale(mlx_ptr, win_ptr, font, val * (FONT_WIDTH + 2), 0, FONT_WIDTH, font_atlas.height, x + pos * dest_w, y, dest_w, dest_h, color);
		pos ++;
		string ++;
	}
	return (0);
}
*/