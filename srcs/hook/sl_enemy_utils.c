/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_enemy_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 15:10:21 by jpyo              #+#    #+#             */
/*   Updated: 2021/07/04 16:13:15 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	sl_enemy_surrounded_wall(t_sl_data *data, t_enemy_data *enemy)
{
	int		x;
	int		y;
	char	**map;

	x = enemy->pos_x;
	y = enemy->pos_y;
	map = data->map.grid;
	if (map[y - 1][x] == '1' && map[y + 1][x] == '1' &&
		map[y][x - 1] == '1' && map[y][x + 1] == '1')
		return (1);
	return (0);
}

int			sl_enemy_turn(t_enemy_data *enemy)
{
	enemy->view_dir = (enemy->view_dir + 1) % 4;
	return (1);
}

int			sl_enemy_select(t_sl_data *data, t_enemy_data *enemy)
{
	int		x;
	int		y;
	char	**map;

	x = enemy->pos_x;
	y = enemy->pos_y;
	map = data->map.grid;
	if (data->enemies.turn == 1)
		return (sl_enemy_turn(enemy));
	else if (sl_enemy_surrounded_wall(data, enemy) == 1)
		return (1);
	else if (map[y][x] == 'w')
		return (sl_enemy_move_w(data, enemy));
	else if (map[y][x] == 'c')
		return (sl_enemy_move_c(data, enemy));
	return (0);
}
