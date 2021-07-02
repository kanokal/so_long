/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_enemy_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 17:49:45 by jpyo              #+#    #+#             */
/*   Updated: 2021/07/02 19:16:49 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	sl_enemy_move_south(t_sl_data *data, t_enemy_data *enemy);
static void	sl_enemy_move_west(t_sl_data *data, t_enemy_data *enemy);
static void	sl_enemy_move_east(t_sl_data *data, t_enemy_data *enemy);

static void	sl_enemy_move_north(t_sl_data *data, t_enemy_data *enemy)
{
	if (data->map.grid[enemy->pos_y - 1][enemy->pos_x] == '1')
	{
		enemy->mv_dir = VIEW_EAST;
		return (sl_enemy_move_east(data, enemy));
	}
	else if (data->map.grid[enemy->pos_y - 1][enemy->pos_x] == 'P' || data->map.grid[enemy->pos_y - 1][enemy->pos_x] == 'p')
		exit(0);
	else if (data->map.grid[enemy->pos_y - 1][enemy->pos_x] == 'C')
	{
		data->map.grid[enemy->pos_y - 1][enemy->pos_x] = '0';
		data->map.grid[enemy->pos_y][enemy->pos_x] = 'c';
	}
	else if (data->map.grid[enemy->pos_y - 1][enemy->pos_x] == 'E')
	{
		data->map.grid[enemy->pos_y - 1][enemy->pos_x] = '0';
		data->map.grid[enemy->pos_y][enemy->pos_x] = 'w';
	}
	ft_swap_char(&data->map.grid[enemy->pos_y - 1][enemy->pos_x], &data->map.grid[enemy->pos_y][enemy->pos_x]);
	enemy->pos_y--;
	enemy->view_dir = VIEW_NORTH;
}

static void	sl_enemy_move_south(t_sl_data *data, t_enemy_data *enemy)
{
	if (data->map.grid[enemy->pos_y + 1][enemy->pos_x] == '1')
	{
		enemy->mv_dir = VIEW_WEST;
		return (sl_enemy_move_west(data, enemy));
	}
	else if (data->map.grid[enemy->pos_y + 1][enemy->pos_x] == 'P' || data->map.grid[enemy->pos_y + 1][enemy->pos_x] == 'p')
		exit(0);
	else if (data->map.grid[enemy->pos_y + 1][enemy->pos_x] == 'C')
	{
		data->map.grid[enemy->pos_y + 1][enemy->pos_x] = '0';
		data->map.grid[enemy->pos_y][enemy->pos_x] = 'c';
	}
	else if (data->map.grid[enemy->pos_y + 1][enemy->pos_x] == 'E')
	{
		data->map.grid[enemy->pos_y + 1][enemy->pos_x] = '0';
		data->map.grid[enemy->pos_y][enemy->pos_x] = 'w';
	}
	ft_swap_char(&data->map.grid[enemy->pos_y + 1][enemy->pos_x], &data->map.grid[enemy->pos_y][enemy->pos_x]);
	enemy->pos_y++;
	enemy->view_dir = VIEW_SOUTH;
}

static void	sl_enemy_move_west(t_sl_data *data, t_enemy_data *enemy)
{
	if (data->map.grid[enemy->pos_y][enemy->pos_x - 1] == '1')
	{
		enemy->mv_dir = VIEW_NORTH;
		return (sl_enemy_move_north(data, enemy));
	}
	else if (data->map.grid[enemy->pos_y][enemy->pos_x - 1] == 'P' || data->map.grid[enemy->pos_y][enemy->pos_x - 1] == 'p')
		exit(0);
	else if (data->map.grid[enemy->pos_y][enemy->pos_x - 1] == 'C')
	{
		data->map.grid[enemy->pos_y][enemy->pos_x - 1] = '0';
		data->map.grid[enemy->pos_y][enemy->pos_x] = 'c';
	}
	else if (data->map.grid[enemy->pos_y][enemy->pos_x - 1] == 'E')
	{
		data->map.grid[enemy->pos_y][enemy->pos_x - 1] = '0';
		data->map.grid[enemy->pos_y][enemy->pos_x] = 'w';
	}
	ft_swap_char(&data->map.grid[enemy->pos_y][enemy->pos_x - 1], &data->map.grid[enemy->pos_y][enemy->pos_x]);
	enemy->pos_x--;
	enemy->view_dir = VIEW_WEST;
}

static void	sl_enemy_move_east(t_sl_data *data, t_enemy_data *enemy)
{
	if (data->map.grid[enemy->pos_y][enemy->pos_x + 1] == '1')
	{
		enemy->mv_dir = VIEW_SOUTH;
		return (sl_enemy_move_south(data, enemy));
	}
	else if (data->map.grid[enemy->pos_y][enemy->pos_x + 1] == 'P' || data->map.grid[enemy->pos_y][enemy->pos_x + 1] == 'p')
		exit(0);
	else if (data->map.grid[enemy->pos_y][enemy->pos_x + 1] == 'C')
	{
		data->map.grid[enemy->pos_y][enemy->pos_x + 1] = '0';
		data->map.grid[enemy->pos_y][enemy->pos_x] = 'c';
	}
	else if (data->map.grid[enemy->pos_y][enemy->pos_x + 1] == 'E')
	{
		data->map.grid[enemy->pos_y][enemy->pos_x + 1] = '0';
		data->map.grid[enemy->pos_y][enemy->pos_x] = 'w';
	}
	ft_swap_char(&data->map.grid[enemy->pos_y][enemy->pos_x + 1], &data->map.grid[enemy->pos_y][enemy->pos_x]);
	enemy->pos_x++;
	enemy->view_dir = VIEW_EAST;
}

void	sl_enemy_move(t_sl_data *data)
{
	int	idx;

	idx = 0;
	while (idx < data->enemies.count)
	{
		printf("%c\n", data->map.grid[data->enemies.group[idx].pos_y][data->enemies.group[idx].pos_x]);
		if (data->map.grid[data->enemies.group[idx].pos_y - 1][data->enemies.group[idx].pos_x] == '1' && 
			data->map.grid[data->enemies.group[idx].pos_y + 1][data->enemies.group[idx].pos_x] == '1' &&
			data->map.grid[data->enemies.group[idx].pos_y][data->enemies.group[idx].pos_x - 1] == '1' &&
			data->map.grid[data->enemies.group[idx].pos_y][data->enemies.group[idx].pos_x + 1] == '1')
			;
		else if (data->map.grid[data->enemies.group[idx].pos_y][data->enemies.group[idx].pos_x] == 'w')
			sl_enemy_move_w(data);
		else if (data->map.grid[data->enemies.group[idx].pos_y][data->enemies.group[idx].pos_x] == 'c')
			sl_enemy_move_c(data);
		else if (data->enemies.group[idx].mv_dir == VIEW_NORTH)
			sl_enemy_move_north(data, &data->enemies.group[idx]);
		else if (data->enemies.group[idx].mv_dir == VIEW_SOUTH)
			sl_enemy_move_south(data, &data->enemies.group[idx]);
		else if (data->enemies.group[idx].mv_dir == VIEW_WEST)
			sl_enemy_move_west(data, &data->enemies.group[idx]);
		else if (data->enemies.group[idx].mv_dir == VIEW_EAST)
			sl_enemy_move_east(data, &data->enemies.group[idx]);
		idx++;
	}
}
