/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:05:51 by jpyo              #+#    #+#             */
/*   Updated: 2021/07/02 19:12:07 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	sl_loop(t_sl_data *data)
{
	sl_set_animation(data);
	sl_set_enemy_sprite(data);
	sl_set_player_sprite(data);
	mlx_put_image_to_window(data->mlx, data->win, data->background.ptr, 0, 0);
	sl_render(data);
	sl_display_move_count(data);
	return (0);
}

void	so_long(t_sl_data *data)
{
	sl_set_background(data);
	mlx_put_image_to_window(data->mlx, data->win, data->background.ptr, 0, 0);
	sl_render(data);
	sl_display_move_count(data);
	mlx_hook(data->win, KEYPRESS, KEYPRESS_MASK, sl_press_key, data);
	mlx_hook(data->win, KEYRELEASE, KEYRELEASE_MASK, sl_release_key, data);
	mlx_hook(data->win, DESTROYNOTIFY, 0, sl_close, data);
	mlx_loop_hook(data->mlx, sl_loop, data);
	mlx_loop(data->mlx);
}
