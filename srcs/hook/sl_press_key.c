/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_press_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:05:26 by jpyo              #+#    #+#             */
/*   Updated: 2021/07/04 17:17:22 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	sl_player_move_north(t_sl_data *data, int x, int y)
{
	char	*front;

	front = &data->map.grid[y - 1][x];
	data->player.view_dir = NORTH;
	if (*front == '1')
		return ;
	else if (*front == 'W' || *front == 'w' || *front == 'c')
		exit(0);
	else if (*front == 'C')
	{
		data->map.collect--;
		*front = '0';
	}
	else if (*front == 'E' && data->map.collect == 0)
		exit(0);
	else if (*front == 'E')
	{
		*front = '0';
		data->map.grid[y][x] = 'p';
	}
	ft_swap_char(front, &data->map.grid[y][x]);
	data->player.pos_y--;
	sl_enemy_move(data, 0, 0);
	sl_player_move(data);
}

static void	sl_player_move_south(t_sl_data *data, int x, int y)
{
	char	*front;

	front = &data->map.grid[y + 1][x];
	data->player.view_dir = SOUTH;
	if (*front == '1')
		return ;
	else if (*front == 'W' || *front == 'w' || *front == 'c')
		exit(0);
	else if (*front == 'C')
	{
		data->map.collect--;
		*front = '0';
	}
	else if (*front == 'E' && data->map.collect == 0)
		exit(0);
	else if (*front == 'E')
	{
		*front = '0';
		data->map.grid[y][x] = 'p';
	}
	ft_swap_char(front, &data->map.grid[y][x]);
	data->player.pos_y++;
	sl_enemy_move(data, 0, 0);
	sl_player_move(data);
}

static void	sl_player_move_west(t_sl_data *data, int x, int y)
{
	char	*front;

	front = &data->map.grid[y][x - 1];
	data->player.view_dir = WEST;
	if (*front == '1')
		return ;
	else if (*front == 'W' || *front == 'w' || *front == 'c')
		exit(0);
	else if (*front == 'C')
	{
		data->map.collect--;
		*front = '0';
	}
	else if (*front == 'E' && data->map.collect == 0)
		exit(0);
	else if (*front == 'E')
	{
		*front = '0';
		data->map.grid[y][x] = 'p';
	}
	ft_swap_char(front, &data->map.grid[y][x]);
	data->player.pos_x--;
	sl_enemy_move(data, 0, 0);
	sl_player_move(data);
}

static void	sl_player_move_east(t_sl_data *data, int x, int y)
{
	char	*front;

	front = &data->map.grid[y][x + 1];
	data->player.view_dir = EAST;
	if (*front == '1')
		return ;
	else if (*front == 'W' || *front == 'w' || *front == 'c')
		exit(0);
	else if (*front == 'C')
	{
		data->map.collect--;
		*front = '0';
	}
	else if (*front == 'E' && data->map.collect == 0)
		exit(0);
	else if (*front == 'E')
	{
		*front = '0';
		data->map.grid[y][x] = 'p';
	}
	ft_swap_char(front, &data->map.grid[y][x]);
	data->player.pos_x++;
	sl_enemy_move(data, 0, 0);
	sl_player_move(data);
}

int			sl_press_key(const int key, t_sl_data *data)
{
	int	x;
	int	y;

	x = data->player.pos_x;
	y = data->player.pos_y;
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
