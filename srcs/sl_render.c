/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:28:28 by jpyo              #+#    #+#             */
/*   Updated: 2021/07/01 19:50:38 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// 몇번 움직였는지 표시

static void	sl_render_texture(t_sl_data *data, int x, int y, int *texture)
{
	int		i;
	int		j;

	j = 0;
	while (j < SPRITE_SIZE)
	{
		i = 0;
		while (i < SPRITE_SIZE)
		{
			data->img.addr[(y * SPRITE_SIZE * data->canvas.width + j * data->canvas.width) + (x * SPRITE_SIZE + i)] = texture[j * SPRITE_SIZE + i];
			i++;
		}
		j++;
	}
}

void	sl_render(t_sl_data *data)
{
	int	x;
	int	y;

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
			else if (data->map.grid[y][x] == 'W')
				sl_render_texture(data, x, y, data->texture.enemy);
			else
				ft_error_handling("Error\n");
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, 0, 0);
}
