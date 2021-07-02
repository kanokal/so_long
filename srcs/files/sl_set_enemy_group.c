/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_set_enemy_group.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:07:02 by jpyo              #+#    #+#             */
/*   Updated: 2021/07/02 19:08:38 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	sl_set_enemy_group(t_sl_data *data)
{
	int	x;
	int	y;
	int	idx;

	data->enemies.group = (t_enemy_data *)malloc(sizeof(t_enemy_data) * data->enemies.count);
	if (data->enemies.group == NULL)
		ft_error_handling("Error\n");
	data->texture.enemy = (int **)malloc(sizeof(int *) * data->enemies.count);
	if (data->texture.enemy == NULL)
		ft_error_handling("Error\n");
	idx = 0;
	while (idx < data->enemies.count)
	{
		data->texture.enemy[idx] = (int *)malloc(sizeof(int) * (PIXEL_SIZE * PIXEL_SIZE));
		if (data->texture.enemy[idx] == NULL)
			ft_error_handling("Error\n");
		idx++;
	}
	idx = 0;
	y = 0;
	while (y < data->map.height && idx < data->enemies.count)
	{
		x = 0;
		while (x < data->map.width && idx < data->enemies.count)
		{
			if (data->map.grid[y][x] == 'W')
			{
				data->enemies.group[idx].pos_x = x;
				data->enemies.group[idx].pos_y = y;
				data->enemies.group[idx].view_dir = idx % 4;
				data->enemies.group[idx].mv_dir = idx % 4;
				idx++;
			}
			x++;
		}
		y++;
	}
}