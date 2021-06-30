/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:28:28 by jpyo              #+#    #+#             */
/*   Updated: 2021/06/30 21:03:56 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// 몇번 움직였는지 표시

// void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->size + x * (data->bpp / 8));
// 	*(unsigned int *)dst = color;
// }

static void	sl_render_texture(t_sl_data *data, int x, int y, int *texture)
{
	int		i;
	int		j;
	char	*dst;

	// j = 0;
	// while (j < IMG_H_SIZE)
	// {
	// 	i = 0;
	// 	while (i < IMG_W_SIZE)
	// 	{
	// 		dst = data->img.addr + (((IMG_H_SIZE * y * data->img.size) + (j * data->img.size)) + ((IMG_W_SIZE * x * data->img.bpp / 8) + (i * data->img.bpp / 8)));
	// 		*(unsigned int *)dst = texture[IMG_W_SIZE * j + i];
	// 		i++;
	// 	}
	// 	j++;
	// }
	printf("%d %d\n", x, y);
	i = 0;
	while (i < IMG_H_SIZE * IMG_W_SIZE)
	{
		data->img.addr[IMG_H_SIZE * y + IMG_W_SIZE * x + i] = texture[i];
		i++;
	}
}

void	sl_render(t_sl_data *data)
{
	int	x;
	int	y;

	printf("%d %d\n", data->map.height, data->map.width);
	while(1);
	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (data->map.grid[y][x] == '1')
				sl_render_texture(data, x, y, data->texture.wall);
			else if (data->map.grid[y][x] == '0')
				sl_render_texture(data, x, y, data->texture.tile);
			else if (data->map.grid[y][x] == 'P')
				sl_render_texture(data, x, y, data->texture.player);
			else if (data->map.grid[y][x] == 'C')
				sl_render_texture(data, x, y, data->texture.collect);
			else if (data->map.grid[y][x] == 'E')
				sl_render_texture(data, x, y, data->texture.exit);
			else
				ft_error_handling("Error\n");
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, 0, 0);
}
