/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_enemy_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 17:49:45 by jpyo              #+#    #+#             */
/*   Updated: 2021/07/03 20:22:56 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	sl_enemy_move_north(t_sl_data *data, t_enemy_data *enemy)
{
	char	*front;

	front = &data->map.grid[enemy->pos_y - 1][enemy->pos_x];
	if (*front == '1' || *front == 'W' || *front == 'w' || *front == 'c')
	{
		enemy->view_dir = VIEW_EAST;
		return ;
	}
	else if (*front == 'P' || *front == 'p')
		exit(0);
	else if (*front == 'C')
	{
		*front = '0';
		data->map.grid[enemy->pos_y][enemy->pos_x] = 'c';
	}
	else if (*front == 'E')
	{
		*front = '0';
		data->map.grid[enemy->pos_y][enemy->pos_x] = 'w';
	}
	ft_swap_char(front, &data->map.grid[enemy->pos_y][enemy->pos_x]);
	enemy->pos_y--;
}

static void	sl_enemy_move_south(t_sl_data *data, t_enemy_data *enemy)
{
	char	*front;

	front = &data->map.grid[enemy->pos_y + 1][enemy->pos_x];
	if (*front == '1' || *front == 'W' || *front == 'w' || *front == 'c')
	{
		enemy->view_dir = VIEW_WEST;
		return ;
	}
	else if (*front == 'P' || *front == 'p')
		exit(0);
	else if (*front == 'C')
	{
		*front = '0';
		data->map.grid[enemy->pos_y][enemy->pos_x] = 'c';
	}
	else if (*front == 'E')
	{
		*front = '0';
		data->map.grid[enemy->pos_y][enemy->pos_x] = 'w';
	}
	ft_swap_char(front, &data->map.grid[enemy->pos_y][enemy->pos_x]);
	enemy->pos_y++;
}

static void	sl_enemy_move_west(t_sl_data *data, t_enemy_data *enemy)
{
	char	*front;

	front = &data->map.grid[enemy->pos_y][enemy->pos_x - 1];
	if (*front == '1' || *front == 'W' || *front == 'w' || *front == 'c')
	{
		enemy->view_dir = VIEW_NORTH;
		return ;
	}
	else if (*front == 'P' || *front == 'p')
		exit(0);
	else if (*front == 'C')
	{
		*front = '0';
		data->map.grid[enemy->pos_y][enemy->pos_x] = 'c';
	}
	else if (*front == 'E')
	{
		*front = '0';
		data->map.grid[enemy->pos_y][enemy->pos_x] = 'w';
	}
	ft_swap_char(front, &data->map.grid[enemy->pos_y][enemy->pos_x]);
	enemy->pos_x--;
}

static void	sl_enemy_move_east(t_sl_data *data, t_enemy_data *enemy)
{
	char	*front;

	front = &data->map.grid[enemy->pos_y][enemy->pos_x + 1];
	if (*front == '1' || *front == 'W' || *front == 'w' || *front == 'c')
	{
		enemy->view_dir = VIEW_SOUTH;
		return ;
	}
	else if (*front == 'P' || *front == 'p')
		exit(0);
	else if (*front == 'C')
	{
		*front = '0';
		data->map.grid[enemy->pos_y][enemy->pos_x] = 'c';
	}
	else if (*front == 'E')
	{
		*front = '0';
		data->map.grid[enemy->pos_y][enemy->pos_x] = 'w';
	}
	ft_swap_char(front, &data->map.grid[enemy->pos_y][enemy->pos_x]);
	enemy->pos_x++;
}

void	sl_enemy_move(t_sl_data *data, int x, int y, char **map)
{
	int		idx;

	idx = 0;
	while (idx < data->enemies.count)
	{
		x = data->enemies.group[idx].pos_x;
		y = data->enemies.group[idx].pos_y;
		if (map[y - 1][x] == '1' && map[y + 1][x] == '1' &&
				map[y][x - 1] == '1' && map[y][x + 1] == '1')
			;
		else if (map[y][x] == 'w')
			sl_enemy_move_w(data, &data->enemies.group[idx]);
		else if (map[y][x] == 'c')
			sl_enemy_move_c(data, &data->enemies.group[idx]);
		else if (data->enemies.group[idx].view_dir == VIEW_NORTH)
			sl_enemy_move_north(data, &data->enemies.group[idx]);
		else if (data->enemies.group[idx].view_dir == VIEW_SOUTH)
			sl_enemy_move_south(data, &data->enemies.group[idx]);
		else if (data->enemies.group[idx].view_dir == VIEW_WEST)
			sl_enemy_move_west(data, &data->enemies.group[idx]);
		else if (data->enemies.group[idx].view_dir == VIEW_EAST)
			sl_enemy_move_east(data, &data->enemies.group[idx]);
		idx++;
	}
}
