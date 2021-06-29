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

static void	sl_loop(t_data *data)
{
	if (data->render == 1)
		sl_render_all(data);
}

void	so_long(t_data *data)
{
	data->mlx = mlx_init();
	// 화면 크기보다 클 경우 에러?
	data->win = mlx_new_window(data->mlx, data->sl.map.width * FONT_WIDTH, data->sl.map.height * FONT_HEIGHT, "so_long");
	sl_render_all(data);
	mlx_hook(data->win, KEYPRESS, KEYPRESS_MASK, sl_press_key, data);
	mlx_hook(data->win, KEYRELEASE, KEYRELEASE_MASK, sl_release_key, data);
	mlx_hook(data->win, DESTROYNOTIFY, 0, sl_close, data);
	mlx_loop_hook(data->mlx, sl_loop, data);
}
