/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:28:58 by jpyo              #+#    #+#             */
/*   Updated: 2021/07/04 17:48:00 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void		sl_player_move(t_sl_data *data)
{
	if (ft_bigint_add_val(data->player.mv_count, 1, 0) < 0)
		ft_error_handling("Error\nFailed malloc on bigint\n");
	sl_set_enemy_sprite(data);
	sl_set_player_sprite(data);
	sl_set_background(data);
	mlx_put_image_to_window(data->mlx, data->win, data->background.ptr, 0, 0);
	sl_render(data);
	sl_display_move_count(data);
	if (data->player.mv_count->bigint[0] % 20 == 0)
		data->enemies.turn = 1;
}
