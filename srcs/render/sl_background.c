/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_background.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:11:01 by jpyo              #+#    #+#             */
/*   Updated: 2021/07/02 16:57:23 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	sl_set_background_do(t_sl_data *data, int x, int y, int *texture)
{
	int	i;
	int	j;

	j = 0;
	while (j < PIXEL_SIZE)
	{
		i = 0;
		while (i < PIXEL_SIZE)
		{
			data->background.addr[y * data->background.size_line / 4 * PIXEL_SIZE + x * PIXEL_SIZE + j * data->background.size_line / 4 + i] = texture[j * PIXEL_SIZE + i];
			i++;
		}
		j++;
	}
}

void		sl_set_background(t_sl_data *data)
{
	int		x;
	int		y;
	char	**tmp;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (data->map.grid[y][x] == '1')
				sl_set_background_do(data, x, y, data->texture.wall);
			else if (data->map.grid[y][x] == 'E')
				sl_set_background_do(data, x, y, data->texture.exit);
			else
				sl_set_background_do(data, x, y, data->texture.tile);
			x++;
		}
		y++;
	}
}
