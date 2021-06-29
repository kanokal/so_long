/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:28:28 by jpyo              #+#    #+#             */
/*   Updated: 2021/06/26 14:07:43 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// 몇번 움직였는지 표시

void	sl_render_line(t_data *data, const int h1, const int h2)
{
	if (h1 > 0)
		mlx_string_put(data->mlx, data->win, 0, h1 * FONT_HEIGHT, 255, data->sl.map.grid[h1]);
	if (h2 > 0)
		mlx_string_put(data->mlx, data->win, 0, h2 * FONT_HEIGHT, 255, data->sl.map.grid[h2]);
}


void	sl_render_all(t_data *data)
{
	int	idx;

	idx = 0;
	while (data->sl.map.grid[idx] != NULL)
	{
		mlx_string_put(data->mlx, data->win, 0, idx * FONT_HEIGHT, 255, data->sl.map.grid[idx]);
		idx++;
	}
	data->render = 0;
}
