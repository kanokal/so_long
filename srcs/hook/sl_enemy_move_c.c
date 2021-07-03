/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_enemy_move_c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:03:42 by jpyo              #+#    #+#             */
/*   Updated: 2021/07/02 19:16:25 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	sl_enemy_move_south_c(t_sl_data *data, t_enemy_data *enemy);
static void	sl_enemy_move_west_c(t_sl_data *data, t_enemy_data *enemy);
static void	sl_enemy_move_east_c(t_sl_data *data, t_enemy_data *enemy);

static void	sl_enemy_move_north_c(t_sl_data *data, t_enemy_data *enemy)
{
	if (data->map.grid[enemy->pos_y - 1][enemy->pos_x] == '1')
	{
		enemy->view_dir = VIEW_EAST;
		enemy->mv_dir = VIEW_EAST;
		return (sl_enemy_move_east_c(data, enemy));
	}
	else if (data->map.grid[enemy->pos_y - 1][enemy->pos_x] == 'P' ||
				data->map.grid[enemy->pos_y - 1][enemy->pos_x] == 'p')
		exit(0);
	else if (data->map.grid[enemy->pos_y - 1][enemy->pos_x] == 'E')
		data->map.grid[enemy->pos_y][enemy->pos_x] = 'w';
	else
		data->map.grid[enemy->pos_y][enemy->pos_x] = 'W';
	data->map.grid[enemy->pos_y - 1][enemy->pos_x] = 'C';
	ft_swap_char(&data->map.grid[enemy->pos_y - 1][enemy->pos_x],
					&data->map.grid[enemy->pos_y][enemy->pos_x]);
	enemy->pos_y--;
}

static void	sl_enemy_move_south_c(t_sl_data *data, t_enemy_data *enemy)
{
	if (data->map.grid[enemy->pos_y + 1][enemy->pos_x] == '1')
	{
		enemy->view_dir = VIEW_WEST;
		enemy->mv_dir = VIEW_WEST;
		return (sl_enemy_move_west_c(data, enemy));
	}
	else if (data->map.grid[enemy->pos_y + 1][enemy->pos_x] == 'P' ||
				data->map.grid[enemy->pos_y + 1][enemy->pos_x] == 'p')
		exit(0);
	else if (data->map.grid[enemy->pos_y + 1][enemy->pos_x] == 'E')
		data->map.grid[enemy->pos_y][enemy->pos_x] = 'w';
	else
		data->map.grid[enemy->pos_y][enemy->pos_x] = 'W';
	data->map.grid[enemy->pos_y + 1][enemy->pos_x] = 'C';
	ft_swap_char(&data->map.grid[enemy->pos_y + 1][enemy->pos_x],
					&data->map.grid[enemy->pos_y][enemy->pos_x]);
	enemy->pos_y++;
}

static void	sl_enemy_move_west_c(t_sl_data *data, t_enemy_data *enemy)
{
	if (data->map.grid[enemy->pos_y][enemy->pos_x - 1] == '1')
	{
		enemy->view_dir = VIEW_NORTH;
		enemy->mv_dir = VIEW_NORTH;
		return (sl_enemy_move_north_c(data, enemy));
	}
	else if (data->map.grid[enemy->pos_y][enemy->pos_x - 1] == 'P' ||
				data->map.grid[enemy->pos_y][enemy->pos_x - 1] == 'p')
		exit(0);
	else if (data->map.grid[enemy->pos_y][enemy->pos_x - 1] == 'E')
		data->map.grid[enemy->pos_y][enemy->pos_x] = 'w';
	else
		data->map.grid[enemy->pos_y][enemy->pos_x] = 'W';
	data->map.grid[enemy->pos_y][enemy->pos_x - 1] = 'C';
	ft_swap_char(&data->map.grid[enemy->pos_y][enemy->pos_x - 1],
					&data->map.grid[enemy->pos_y][enemy->pos_x]);
	enemy->pos_x--;
}

static void	sl_enemy_move_east_c(t_sl_data *data, t_enemy_data *enemy)
{
	if (data->map.grid[enemy->pos_y][enemy->pos_x + 1] == '1')
	{
		enemy->view_dir = VIEW_SOUTH;
		enemy->mv_dir = VIEW_SOUTH;
		return (sl_enemy_move_south_c(data, enemy));
	}
	else if (data->map.grid[enemy->pos_y][enemy->pos_x + 1] == 'P' ||
				data->map.grid[enemy->pos_y][enemy->pos_x + 1] == 'p')
		exit(0);
	else if (data->map.grid[enemy->pos_y][enemy->pos_x + 1] == 'E')
		data->map.grid[enemy->pos_y][enemy->pos_x] = 'w';
	else
		data->map.grid[enemy->pos_y][enemy->pos_x] = 'W';
	data->map.grid[enemy->pos_y][enemy->pos_x + 1] = 'C';
	ft_swap_char(&data->map.grid[enemy->pos_y][enemy->pos_x + 1],
					&data->map.grid[enemy->pos_y][enemy->pos_x]);
	enemy->pos_x++;
}

void	sl_enemy_move_c(t_sl_data *data, t_enemy_data *enemy)
{
	if (enemy->mv_dir == VIEW_NORTH)
		sl_enemy_move_north_c(data, enemy);
	else if (enemy->mv_dir == VIEW_SOUTH)
		sl_enemy_move_south_c(data, enemy);
	else if (enemy->mv_dir == VIEW_WEST)
		sl_enemy_move_west_c(data, enemy);
	else if (enemy->mv_dir == VIEW_EAST)
		sl_enemy_move_east_c(data, enemy);
}
