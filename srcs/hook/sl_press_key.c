/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_press_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:05:26 by jpyo              #+#    #+#             */
/*   Updated: 2021/06/30 18:23:52 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	sl_player_move_up(t_sl_data *data)
{
	if (data->map.grid[data->map.py - 1][data->map.px] == 'C')
		data->map.grid[data->map.py - 1][data->map.px] = '0';
	else if (data->map.grid[data->map.py - 1][data->map.px] == 'E')
		exit(0);
	ft_swap_char(&data->map.grid[data->map.py - 1][data->map.px], &data->map.grid[data->map.py][data->map.px]);
	data->map.py--;
	data->render = 1;
}

static void	sl_player_move_down(t_sl_data *data)
{
	if (data->map.grid[data->map.py + 1][data->map.px] == 'C')
		data->map.grid[data->map.py + 1][data->map.px] = '0';
	else if (data->map.grid[data->map.py + 1][data->map.px] == 'E')
		exit(0);
	ft_swap_char(&data->map.grid[data->map.py + 1][data->map.px], &data->map.grid[data->map.py][data->map.px]);
	data->map.py++;
	data->render = 1;
}

static void	sl_player_move_left(t_sl_data *data)
{
	if (data->map.grid[data->map.py][data->map.px - 1] == 'C')
		data->map.grid[data->map.py][data->map.px - 1] = '0';
	else if (data->map.grid[data->map.py][data->map.px - 1] == 'E')
		exit(0);
	ft_swap_char(&data->map.grid[data->map.py][data->map.px - 1], &data->map.grid[data->map.py][data->map.px]);
	data->map.px--;
	data->render = 1;
}

static void	sl_player_move_right(t_sl_data *data)
{
	if (data->map.grid[data->map.py - 1][data->map.px + 1] == 'C')
		data->map.grid[data->map.py - 1][data->map.px + 1] = '0';
	else if (data->map.grid[data->map.py - 1][data->map.px + 1] == 'E')
		exit(0);
	ft_swap_char(&data->map.grid[data->map.py][data->map.px + 1], &data->map.grid[data->map.py][data->map.px]);
	data->map.px++;
	data->render = 1;
}

int			sl_press_key(const int key, t_sl_data *data)
{
	printf("Key in digit : %d\n", key);
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_W && data->map.grid[data->map.py - 1][data->map.px] != '1')
		sl_player_move_up(data);
	else if (key == KEY_S && data->map.grid[data->map.py + 1][data->map.px] != '1')
		sl_player_move_down(data);
	else if (key == KEY_A && data->map.grid[data->map.py][data->map.px - 1] != '1')
		sl_player_move_left(data);
	else if (key == KEY_D && data->map.grid[data->map.py][data->map.px + 1] != '1')
	{
		printf("in right\n");
		sl_player_move_right(data);
	}
	return (0);
}