/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:05:51 by jpyo              #+#    #+#             */
/*   Updated: 2021/06/25 17:06:33 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(void)
{
	
}

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