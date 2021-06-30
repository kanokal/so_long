/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:05:51 by jpyo              #+#    #+#             */
/*   Updated: 2021/06/30 19:47:21 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	sl_clean_window(t_sl_data *data)
{
	int		x;
	int		y;
	char	*dst;

	y = 0;
	while (y < data->canvas.height)
	{
		x = 0;
		while (x < data->canvas.width)
		{
			dst = data->img.addr + (y * data->img.size + x * data->img.bpp / 8);
			*(unsigned int *)dst = 0x00FFFFFF;
			x++;
		}
		y++;
	}
}

static int	sl_loop(t_sl_data *data)
{
	if (data->render == 1)
	{
		sl_clean_window(data);
		sl_render(data);
	}
	return (0);
}

void	so_long(t_sl_data *data)
{
	sl_render(data);
	mlx_hook(data->win, KEYPRESS, KEYPRESS_MASK, sl_press_key, data);
	mlx_hook(data->win, KEYRELEASE, KEYRELEASE_MASK, sl_release_key, data);
	mlx_hook(data->win, DESTROYNOTIFY, 0, sl_close, data);
	mlx_loop_hook(data->mlx, sl_loop, data);
	mlx_loop(data->mlx);
}
