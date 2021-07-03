/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_background.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:11:01 by jpyo              #+#    #+#             */
/*   Updated: 2021/07/03 21:16:42 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	sl_set_background_do(t_sl_data *data, int x, int y, int *texture)
{
	int	i;
	int	j;
	int	bg_x;
	int	bg_y;

	j = 0;
	while (j < PIXEL_SIZE)
	{
		i = 0;
		bg_y = y * data->background.size_line / 4 * PIXEL_SIZE
			+ j * data->background.size_line / 4;
		while (i < PIXEL_SIZE)
		{
			bg_x = x * PIXEL_SIZE + i;
			if (texture[j * PIXEL_SIZE + i] != 0xff000000)
				data->background.addr[bg_y + bg_x] =
					texture[j * PIXEL_SIZE + i];
			else
				data->background.addr[bg_y + bg_x] =
					data->texture.tile[j * PIXEL_SIZE + i];
			i++;
		}
		j++;
	}
}

void		sl_set_background(t_sl_data *data)
{
	int		x;
	int		y;
	char	elem;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			elem = data->map.grid[y][x];
			if (elem == '1')
				sl_set_background_do(data, x, y, data->texture.wall);
			else if (elem == 'E' || elem == 'p' || elem == 'w')
				sl_set_background_do(data, x, y, data->texture.exit);
			else if (elem == 'C' || elem == 'c')
				sl_set_background_do(data, x, y, data->texture.collect);
			else
				sl_set_background_do(data, x, y, data->texture.tile);
			x++;
		}
		y++;
	}
}
