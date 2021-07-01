/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:05:51 by jpyo              #+#    #+#             */
/*   Updated: 2021/07/01 19:50:41 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	sl_display_move_count(t_sl_data *data)
{
	char	*mv;

	mv = ft_bigint_to_a(data->player_data.mv_count);
	if (mv == NULL)
		ft_error_handling("Error\n");
	mlx_string_put(data->mlx, data->win, 5, data->canvas.height - SPRITE_SIZE / 2, 0x00800000, mv);
	ft_free_ptr(&mv);
}

static void	sl_set_background(t_sl_data *data)
{
	int		x;
	int		y;

	y = 0;
	while (y < data->canvas.height)
	{
		x = 0;
		while (x < data->canvas.width)
		{
			data->background.addr[y * data->canvas.width + x] = 0x0093DAFF;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->background.ptr, 0, 0);
}

static int	sl_loop(t_sl_data *data)
{
	if (data->render == 1)
	{
		sl_set_background(data);
		sl_render(data);
		sl_display_move_count(data);
	}
	return (0);
}

void	so_long(t_sl_data *data)
{
	sl_set_background(data);
	sl_render(data);
	sl_display_move_count(data);
	mlx_hook(data->win, KEYPRESS, KEYPRESS_MASK, sl_press_key, data);
	mlx_hook(data->win, KEYRELEASE, KEYRELEASE_MASK, sl_release_key, data);
	mlx_hook(data->win, DESTROYNOTIFY, 0, sl_close, data);
	mlx_loop_hook(data->mlx, sl_loop, data);
	mlx_loop(data->mlx);
}
