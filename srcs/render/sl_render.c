/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:28:28 by jpyo              #+#    #+#             */
/*   Updated: 2021/07/04 16:13:34 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	sl_search_enemy(t_sl_data *data, int map_x, int map_y)
{
	int	idx;

	idx = 0;
	while (idx < data->enemies.count)
	{
		if (data->enemies.group[idx].pos_x == map_x &&
			data->enemies.group[idx].pos_y == map_y)
			return (data->enemies.group[idx].number);
		idx++;
	}
	return (-1);
}

static void	sl_render_do(t_sl_data *data, int x, int y, int *texture)
{
	int		i;
	int		j;
	int		img_y;
	int		bg_y;

	j = 0;
	while (j < PIXEL_SIZE)
	{
		i = 0;
		img_y = y * data->img.size_line / 4 * PIXEL_SIZE +
			j * data->img.size_line / 4;
		bg_y = y * data->background.size_line / 4 * PIXEL_SIZE +
			j * data->background.size_line / 4;
		while (i < PIXEL_SIZE)
		{
			if ((unsigned int)texture[j * PIXEL_SIZE + i] != 0xff000000)
				data->img.addr[img_y + x * PIXEL_SIZE + i] =
					texture[j * PIXEL_SIZE + i];
			else
				data->img.addr[img_y + x * PIXEL_SIZE + i] =
					data->background.addr[bg_y + x * PIXEL_SIZE + i];
			i++;
		}
		j++;
	}
}

static void	sl_render_select(t_sl_data *data, int x, int y)
{
	if (data->map.grid[y][x] == '1')
		sl_render_do(data, x, y, data->texture.wall);
	else if (data->map.grid[y][x] == '0')
		sl_render_do(data, x, y, data->texture.tile);
	else if (data->map.grid[y][x] == 'p')
		sl_render_do(data, x, y, data->texture.player);
	else if (data->map.grid[y][x] == 'P')
		sl_render_do(data, x, y, data->texture.player);
	else if (data->map.grid[y][x] == 'C')
		sl_render_do(data, x, y, data->texture.collect);
	else if (data->map.grid[y][x] == 'E')
		sl_render_do(data, x, y, data->texture.exit);
	else if (data->map.grid[y][x] == 'w')
		sl_render_do(data, x, y,
			data->texture.enemy[sl_search_enemy(data, x, y)]);
	else if (data->map.grid[y][x] == 'c')
		sl_render_do(data, x, y,
			data->texture.enemy[sl_search_enemy(data, x, y)]);
	else if (data->map.grid[y][x] == 'W')
		sl_render_do(data, x, y,
			data->texture.enemy[sl_search_enemy(data, x, y)]);
	else
		ft_error_handling("Error\n");
}

void		sl_render(t_sl_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			sl_render_select(data, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, 0, 0);
}
