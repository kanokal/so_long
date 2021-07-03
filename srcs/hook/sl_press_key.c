/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_press_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:05:26 by jpyo              #+#    #+#             */
/*   Updated: 2021/07/03 17:46:13 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	sl_player_move_north(t_sl_data *data, int x, int y)
{
	data->player.view_dir = VIEW_NORTH;
	if (data->map.grid[y - 1][x] == '1')
		return ;
	else if (data->map.grid[y - 1][x] == 'W' ||
				data->map.grid[y - 1][x] == 'w' ||
					data->map.grid[y - 1][x] == 'c')
		exit(0);
	else if (data->map.grid[y - 1][x] == 'C')
	{
		data->map.collect--;
		data->map.grid[y - 1][x] = '0';
	}
	else if (data->map.grid[y - 1][x] == 'E' && data->map.collect == 0)
		exit(0);
	else if (data->map.grid[y - 1][x] == 'E')
	{
		data->map.grid[y - 1][x] = '0';
		data->map.grid[y][x] = 'p';
	}
	ft_swap_char(&data->map.grid[y - 1][x], &data->map.grid[y][x]);
	data->player.pos_y--;
	sl_enemy_move(data, 0, 0, data->map.grid);
	sl_player_move(data);
}

static void	sl_player_move_south(t_sl_data *data, int x, int y)
{
	data->player.view_dir = VIEW_SOUTH;
	if (data->map.grid[y + 1][x] == '1')
		return ;
	else if (data->map.grid[y + 1][x] == 'W' ||
				data->map.grid[y + 1][x] == 'w' ||
					data->map.grid[y + 1][x] == 'c')
		exit(0);
	else if (data->map.grid[y + 1][x] == 'C')
	{
		data->map.collect--;
		data->map.grid[y + 1][x] = '0';
	}
	else if (data->map.grid[y + 1][x] == 'E' && data->map.collect == 0)
		exit(0);
	else if (data->map.grid[y + 1][x] == 'E')
	{
		data->map.grid[y + 1][x] = '0';
		data->map.grid[y][x] = 'p';
	}
	ft_swap_char(&data->map.grid[y + 1][x], &data->map.grid[y][x]);
	data->player.pos_y++;
	sl_enemy_move(data, 0, 0, data->map.grid);
	sl_player_move(data);
}

static void	sl_player_move_west(t_sl_data *data, int x, int y)
{
	data->player.view_dir = VIEW_WEST;
	if (data->map.grid[y][x - 1] == '1')
		return ;
	else if (data->map.grid[y][x - 1] == 'W' ||
				data->map.grid[y][x - 1] == 'w' ||
					data->map.grid[y][x - 1] == 'c')
		exit(0);
	else if (data->map.grid[y][x - 1] == 'C')
	{
		data->map.collect--;
		data->map.grid[y][x - 1] = '0';
	}
	else if (data->map.grid[y][x - 1] == 'E' && data->map.collect == 0)
		exit(0);
	else if (data->map.grid[y][x - 1] == 'E')
	{
		data->map.grid[y][x - 1] = '0';
		data->map.grid[y][x] = 'p';
	}
	ft_swap_char(&data->map.grid[y][x - 1], &data->map.grid[y][x]);
	data->player.pos_x--;
	sl_enemy_move(data, 0, 0, data->map.grid);
	sl_player_move(data);
}

static void	sl_player_move_east(t_sl_data *data, int x, int y)
{
	data->player.view_dir = VIEW_EAST;
	if (data->map.grid[y][x + 1] == '1')
		return ;
	else if (data->map.grid[y][x + 1] == 'W' ||
				data->map.grid[y][x + 1] == 'w' ||
					data->map.grid[y][x + 1] == 'c')
		exit(0);
	else if (data->map.grid[y][x + 1] == 'C')
	{
		data->map.collect--;
		data->map.grid[y][x + 1] = '0';
	}
	else if (data->map.grid[y][x + 1] == 'E' && data->map.collect == 0)
		exit(0);
	else if (data->map.grid[y][x + 1] == 'E')
	{
		data->map.grid[y][x + 1] = '0';
		data->map.grid[y][x] = 'p';
	}
	ft_swap_char(&data->map.grid[y][x + 1], &data->map.grid[y][x]);
	data->player.pos_x++;
	sl_enemy_move(data, 0, 0, data->map.grid);
	sl_player_move(data);
}

int			sl_press_key(const int key, t_sl_data *data)
{
	int	x;
	int	y;

	x = data->player.pos_x;
	y = data->player.pos_y;
	printf("Key in digit : %d\n", key);
	if (data->map.grid[y][x] == 'p')
		return (sl_press_key2(key, data, x, y));
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_W)
		sl_player_move_north(data, x, y);
	else if (key == KEY_S)
		sl_player_move_south(data, x, y);
	else if (key == KEY_A)
		sl_player_move_west(data, x, y);
	else if (key == KEY_D)
		sl_player_move_east(data, x, y);
	return (0);
}