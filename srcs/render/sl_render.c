/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:28:28 by jpyo              #+#    #+#             */
/*   Updated: 2021/07/02 19:13:12 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	sl_render_do(t_sl_data *data, int x, int y, int *texture)
{
	int		i;
	int		j;

	j = 0;
	while (j < PIXEL_SIZE)
	{
		i = 0;
		while (i < PIXEL_SIZE)
		{
			if (texture[j * PIXEL_SIZE + i] != 0xff000000)
				data->img.addr[y * data->img.size_line / 4 * PIXEL_SIZE + x * PIXEL_SIZE + j * data->img.size_line / 4 + i] = texture[j * PIXEL_SIZE + i];
			else
				data->img.addr[y * data->img.size_line / 4 * PIXEL_SIZE + x * PIXEL_SIZE + j * data->img.size_line / 4 + i] = data->background.addr[y * data->background.size_line / 4 * PIXEL_SIZE + x * PIXEL_SIZE + j * data->background.size_line / 4 + i];
			i++;
		}
		j++;
	}
}

void	sl_render(t_sl_data *data)
{
	int	x;
	int	y;
	int	idx;

	idx = 0;
	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (data->map.grid[y][x] == '1')
				sl_render_do(data, x, y, data->texture.wall);
			else if (data->map.grid[y][x] == '0')
				sl_render_do(data, x, y, data->texture.tile);
			else if (data->map.grid[y][x] == 'p')
			{
				//sl_render_do(data, x, y, data->texture.exit);
				sl_render_do(data, x, y, data->texture.player);
			}
			else if (data->map.grid[y][x] == 'w')
			{
				//sl_render_do(data, x, y, data->texture.exit);
				sl_render_do(data, x, y, data->texture.enemy[idx++]);
			}
			else if (data->map.grid[y][x] == 'c')
			{
				//sl_render_do(data, x, y, data->texture.collect);
				sl_render_do(data, x, y, data->texture.enemy[idx++]);
			}
			else if (data->map.grid[y][x] == 'P')
				sl_render_do(data, x, y, data->texture.player);
			else if (data->map.grid[y][x] == 'C')
				sl_render_do(data, x, y, data->texture.collect);
			else if (data->map.grid[y][x] == 'E')
				sl_render_do(data, x, y, data->texture.exit);
			else if (data->map.grid[y][x] == 'W')
			{
				sl_render_do(data, x, y, data->texture.enemy[idx++]);
			}
			else
				ft_error_handling("Error\n");
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, 0, 0);
}
