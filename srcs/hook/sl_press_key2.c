/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_press_key2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:46:54 by jpyo              #+#    #+#             */
/*   Updated: 2021/07/02 19:15:03 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	sl_player_move_north_2(t_sl_data *data)
{
	if (data->map.grid[data->player.pos_y - 1][data->player.pos_x] == 'W' || data->map.grid[data->player.pos_y - 1][data->player.pos_x] == 'w' || data->map.grid[data->player.pos_y - 1][data->player.pos_x] == 'c')
		exit(0);
	if (data->map.grid[data->player.pos_y - 1][data->player.pos_x] == 'C')
		data->map.collectible--;
	data->map.grid[data->player.pos_y - 1][data->player.pos_x] = 'E';
	data->map.grid[data->player.pos_y][data->player.pos_x] = 'P';
	ft_swap_char(&data->map.grid[data->player.pos_y - 1][data->player.pos_x], &data->map.grid[data->player.pos_y][data->player.pos_x]);
	data->player.pos_y--;
	if (ft_bigint_add_val(data->player.mv_count, 1, 0) < 0)
		ft_error_handling("Error\n");
	data->player.view_dir = VIEW_NORTH;
	sl_enemy_move(data);
	sl_player_move(data);
}

static void	sl_player_move_south_2(t_sl_data *data)
{
	if (data->map.grid[data->player.pos_y + 1][data->player.pos_x] == 'W' || data->map.grid[data->player.pos_y + 1][data->player.pos_x] == 'w' || data->map.grid[data->player.pos_y + 1][data->player.pos_x] == 'c')
		exit(0);
	else if (data->map.grid[data->player.pos_y + 1][data->player.pos_x] == 'C')
		data->map.collectible--;
	data->map.grid[data->player.pos_y + 1][data->player.pos_x] = 'E';
	data->map.grid[data->player.pos_y][data->player.pos_x] = 'P';
	ft_swap_char(&data->map.grid[data->player.pos_y + 1][data->player.pos_x], &data->map.grid[data->player.pos_y][data->player.pos_x]);
	data->player.pos_y++;
	if (ft_bigint_add_val(data->player.mv_count, 1, 0) < 0)
		ft_error_handling("Error\n");
	data->player.view_dir = VIEW_SOUTH;
	sl_enemy_move(data);
	sl_player_move(data);
}

static void	sl_player_move_west_2(t_sl_data *data)
{
	if (data->map.grid[data->player.pos_y][data->player.pos_x - 1] == 'W' || data->map.grid[data->player.pos_y][data->player.pos_x - 1] == 'w' || data->map.grid[data->player.pos_y][data->player.pos_x - 1] == 'c')
		exit(0);
	else if (data->map.grid[data->player.pos_y][data->player.pos_x - 1] == 'C')
		data->map.collectible--;
	data->map.grid[data->player.pos_y][data->player.pos_x - 1] = 'E';
	data->map.grid[data->player.pos_y][data->player.pos_x] = 'P';
	ft_swap_char(&data->map.grid[data->player.pos_y][data->player.pos_x - 1], &data->map.grid[data->player.pos_y][data->player.pos_x]);
	data->player.pos_x--;
	if (ft_bigint_add_val(data->player.mv_count, 1, 0) < 0)
		ft_error_handling("Error\n");
	data->player.view_dir = VIEW_WEST;
	sl_enemy_move(data);
	sl_player_move(data);
}

static void	sl_player_move_east_2(t_sl_data *data)
{
	if (data->map.grid[data->player.pos_y][data->player.pos_x + 1] == 'W' || data->map.grid[data->player.pos_y][data->player.pos_x + 1] == 'w' || data->map.grid[data->player.pos_y][data->player.pos_x + 1] == 'c')
		exit(0);
	else if (data->map.grid[data->player.pos_y][data->player.pos_x + 1] == 'C')
		data->map.collectible--;
	data->map.grid[data->player.pos_y][data->player.pos_x + 1] = 'E';
	data->map.grid[data->player.pos_y][data->player.pos_x] = 'P';
	ft_swap_char(&data->map.grid[data->player.pos_y][data->player.pos_x + 1], &data->map.grid[data->player.pos_y][data->player.pos_x]);
	data->player.pos_x++;
	if (ft_bigint_add_val(data->player.mv_count, 1, 0) < 0)
		ft_error_handling("Error\n");
	data->player.view_dir = VIEW_EAST;
	sl_enemy_move(data);
	sl_player_move(data);
}

int			sl_press_key2(const int key, t_sl_data *data)
{
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_W)
	{
		data->player.view_dir = VIEW_NORTH;
		if (data->map.grid[data->player.pos_y - 1][data->player.pos_x] != '1')
			sl_player_move_north_2(data);
	}
	else if (key == KEY_S)
	{
		data->player.view_dir = VIEW_SOUTH;
		if (data->map.grid[data->player.pos_y + 1][data->player.pos_x] != '1')
			sl_player_move_south_2(data);
	}
	else if (key == KEY_A)
	{
		data->player.view_dir = VIEW_WEST;
		if (data->map.grid[data->player.pos_y][data->player.pos_x - 1] != '1')
			sl_player_move_west_2(data);
	}
	else if (key == KEY_D)
	{
		data->player.view_dir = VIEW_EAST;
		if (data->map.grid[data->player.pos_y][data->player.pos_x + 1] != '1')
			sl_player_move_east_2(data);
	}
	return (0);
}