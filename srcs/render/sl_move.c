/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:28:58 by jpyo              #+#    #+#             */
/*   Updated: 2021/07/02 15:02:44 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void		sl_player_move(t_sl_data *data)
{
	sl_set_player(data);
	mlx_put_image_to_window(data->mlx, data->win, data->background.ptr, 0, 0);
	sl_render(data);
	sl_display_move_count(data);
}
