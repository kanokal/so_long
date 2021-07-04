/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_enemy_move_c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:03:42 by jpyo              #+#    #+#             */
/*   Updated: 2021/07/04 16:14:24 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	sl_enemy_move_north_c(t_sl_data *data, t_enemy_data *enemy)
{
	char	*front;

	front = &data->map.grid[enemy->pos_y - 1][enemy->pos_x];
	if (*front == '1' || *front == 'W' || *front == 'w' || *front == 'c')
		return (sl_enemy_turn(enemy));
	else if (*front == 'P' || *front == 'p')
		exit(0);
	else if (*front == 'E')
		data->map.grid[enemy->pos_y][enemy->pos_x] = 'w';
	else
		data->map.grid[enemy->pos_y][enemy->pos_x] = 'W';
	*front = 'C';
	ft_swap_char(front, &data->map.grid[enemy->pos_y][enemy->pos_x]);
	enemy->pos_y--;
	return (0);
}

static int	sl_enemy_move_south_c(t_sl_data *data, t_enemy_data *enemy)
{
	char	*front;

	front = &data->map.grid[enemy->pos_y + 1][enemy->pos_x];
	if (*front == '1' || *front == 'W' || *front == 'w' || *front == 'c')
		return (sl_enemy_turn(enemy));
	else if (*front == 'P' || *front == 'p')
		exit(0);
	else if (*front == 'E')
		data->map.grid[enemy->pos_y][enemy->pos_x] = 'w';
	else
		data->map.grid[enemy->pos_y][enemy->pos_x] = 'W';
	*front = 'C';
	ft_swap_char(front, &data->map.grid[enemy->pos_y][enemy->pos_x]);
	enemy->pos_y++;
	return (0);
}

static int	sl_enemy_move_west_c(t_sl_data *data, t_enemy_data *enemy)
{
	char	*front;

	front = &data->map.grid[enemy->pos_y][enemy->pos_x - 1];
	if (*front == '1' || *front == 'W' || *front == 'w' || *front == 'c')
		return (sl_enemy_turn(enemy));
	else if (*front == 'P' || *front == 'p')
		exit(0);
	else if (*front == 'E')
		data->map.grid[enemy->pos_y][enemy->pos_x] = 'w';
	else
		data->map.grid[enemy->pos_y][enemy->pos_x] = 'W';
	*front = 'C';
	ft_swap_char(front, &data->map.grid[enemy->pos_y][enemy->pos_x]);
	enemy->pos_x--;
	return (0);
}

static int	sl_enemy_move_east_c(t_sl_data *data, t_enemy_data *enemy)
{
	char	*front;

	front = &data->map.grid[enemy->pos_y][enemy->pos_x + 1];
	if (*front == '1' || *front == 'W' || *front == 'w' || *front == 'c')
		return (sl_enemy_turn(enemy));
	else if (*front == 'P' || *front == 'p')
		exit(0);
	else if (*front == 'E')
		data->map.grid[enemy->pos_y][enemy->pos_x] = 'w';
	else
		data->map.grid[enemy->pos_y][enemy->pos_x] = 'W';
	*front = 'C';
	ft_swap_char(front, &data->map.grid[enemy->pos_y][enemy->pos_x]);
	enemy->pos_x++;
	return (0);
}

int			sl_enemy_move_c(t_sl_data *data, t_enemy_data *enemy)
{
	if (enemy->view_dir == NORTH)
		sl_enemy_move_north_c(data, enemy);
	else if (enemy->view_dir == SOUTH)
		sl_enemy_move_south_c(data, enemy);
	else if (enemy->view_dir == WEST)
		sl_enemy_move_west_c(data, enemy);
	else if (enemy->view_dir == EAST)
		sl_enemy_move_east_c(data, enemy);
	return (1);
}
