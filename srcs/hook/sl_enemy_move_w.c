/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_enemy_move_w.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:03:44 by jpyo              #+#    #+#             */
/*   Updated: 2021/07/03 20:14:39 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	sl_enemy_move_north_w(t_sl_data *data, t_enemy_data *enemy)
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
	else if (*front == 'E')
		data->map.grid[enemy->pos_y][enemy->pos_x] = 'c';
	else
		data->map.grid[enemy->pos_y][enemy->pos_x] = 'W';
	*front = 'E';
	ft_swap_char(front, &data->map.grid[enemy->pos_y][enemy->pos_x]);
	enemy->pos_y--;
}

static void	sl_enemy_move_south_w(t_sl_data *data, t_enemy_data *enemy)
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
	else if (*front == 'E')
		data->map.grid[enemy->pos_y][enemy->pos_x] = 'c';
	else
		data->map.grid[enemy->pos_y][enemy->pos_x] = 'W';
	*front = 'E';
	ft_swap_char(front, &data->map.grid[enemy->pos_y][enemy->pos_x]);
	enemy->pos_y++;
}

static void	sl_enemy_move_west_w(t_sl_data *data, t_enemy_data *enemy)
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
	else if (*front == 'E')
		data->map.grid[enemy->pos_y][enemy->pos_x] = 'c';
	else
		data->map.grid[enemy->pos_y][enemy->pos_x] = 'W';
	*front = 'E';
	ft_swap_char(front, &data->map.grid[enemy->pos_y][enemy->pos_x]);
	enemy->pos_x--;
}

static void	sl_enemy_move_east_w(t_sl_data *data, t_enemy_data *enemy)
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
		data->map.grid[enemy->pos_y][enemy->pos_x] = 'c';
	else
		data->map.grid[enemy->pos_y][enemy->pos_x] = 'W';
	*front = 'E';
	ft_swap_char(front, &data->map.grid[enemy->pos_y][enemy->pos_x]);
	enemy->pos_x++;
}

void	sl_enemy_move_w(t_sl_data *data, t_enemy_data *enemy)
{
	if (enemy->view_dir == VIEW_NORTH)
		sl_enemy_move_north_w(data, enemy);
	else if (enemy->view_dir == VIEW_SOUTH)
		sl_enemy_move_south_w(data, enemy);
	else if (enemy->view_dir == VIEW_WEST)
		sl_enemy_move_west_w(data, enemy);
	else if (enemy->view_dir == VIEW_EAST)
		sl_enemy_move_east_w(data, enemy);
}
