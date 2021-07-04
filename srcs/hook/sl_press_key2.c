/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_press_key2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:46:54 by jpyo              #+#    #+#             */
/*   Updated: 2021/07/04 16:14:43 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	sl_player_move_north_2(t_sl_data *data, int x, int y)
{
	char	*front;

	front = &data->map.grid[y - 1][x];
	data->player.view_dir = NORTH;
	if (*front == '1')
		return ;
	else if (*front == 'W' || *front == 'w' || *front == 'c')
		exit(0);
	else if (*front == 'C')
		data->map.collect--;
	*front = 'E';
	data->map.grid[y][x] = 'P';
	ft_swap_char(front, &data->map.grid[y][x]);
	data->player.pos_y--;
	sl_enemy_move(data, 0, 0);
	sl_player_move(data);
}

static void	sl_player_move_south_2(t_sl_data *data, int x, int y)
{
	char	*front;

	front = &data->map.grid[y + 1][x];
	data->player.view_dir = SOUTH;
	if (*front == '1')
		return ;
	else if (*front == 'W' || *front == 'w' || *front == 'c')
		exit(0);
	else if (*front == 'C')
		data->map.collect--;
	*front = 'E';
	data->map.grid[y][x] = 'P';
	ft_swap_char(front, &data->map.grid[y][x]);
	data->player.pos_y++;
	sl_enemy_move(data, 0, 0);
	sl_player_move(data);
}

static void	sl_player_move_west_2(t_sl_data *data, int x, int y)
{
	char	*front;

	front = &data->map.grid[y][x - 1];
	data->player.view_dir = WEST;
	if (*front == '1')
		return ;
	else if (*front == 'W' || *front == 'w' || *front == 'c')
		exit(0);
	else if (*front == 'C')
		data->map.collect--;
	*front = 'E';
	data->map.grid[y][x] = 'P';
	ft_swap_char(front, &data->map.grid[y][x]);
	data->player.pos_x--;
	sl_enemy_move(data, 0, 0);
	sl_player_move(data);
}

static void	sl_player_move_east_2(t_sl_data *data, int x, int y)
{
	char	*front;

	front = &data->map.grid[y][x + 1];
	data->player.view_dir = EAST;
	if (*front == '1')
		return ;
	else if (*front == 'W' || *front == 'w' || *front == 'c')
		exit(0);
	else if (*front == 'C')
		data->map.collect--;
	*front = 'E';
	data->map.grid[y][x] = 'P';
	ft_swap_char(front, &data->map.grid[y][x]);
	data->player.pos_x++;
	sl_enemy_move(data, 0, 0);
	sl_player_move(data);
}

int			sl_press_key2(const int key, t_sl_data *data, int x, int y)
{
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_W)
		sl_player_move_north_2(data, x, y);
	else if (key == KEY_S)
		sl_player_move_south_2(data, x, y);
	else if (key == KEY_A)
		sl_player_move_west_2(data, x, y);
	else if (key == KEY_D)
		sl_player_move_east_2(data, x, y);
	return (0);
}
