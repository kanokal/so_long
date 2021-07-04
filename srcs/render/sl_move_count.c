/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_move_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:34:41 by jpyo              #+#    #+#             */
/*   Updated: 2021/07/04 17:47:52 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	sl_display_move_count(t_sl_data *data)
{
	char	*mv;

	mv = ft_bigint_to_a(data->player.mv_count);
	if (mv == NULL)
		ft_error_handling("Error\nFailed malloc on bigint\n");
	mlx_string_put(data->mlx, data->win, 5,
		data->canvas.height - SPRITE_SIZE / 2, 0x00800000, mv);
	ft_free_ptr(&mv);
}
