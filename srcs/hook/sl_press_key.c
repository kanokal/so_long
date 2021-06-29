
#include "../../includes/so_long.h"

static void	sl_player_move_up(t_data *data)
{
	if (data->sl.map.grid[data->sl.py - 1][data->sl.px] == 'C')
		data->sl.map.grid[data->sl.py - 1][data->sl.px] = '0';
	else if (data->sl.map.grid[data->sl.py - 1][data->sl.px] == 'E')
		exit(0);
	ft_swap_char(data->sl.map.grid[data->sl.py - 1][data->sl.px], data->sl.map.grid[data->sl.py][data->sl.px]);
	data->sl.py--;
	data->render = 1;
}

static void	sl_player_move_down(t_data *data)
{
	if (data->sl.map.grid[data->sl.py + 1][data->sl.px] == 'C')
		data->sl.map.grid[data->sl.py + 1][data->sl.px] = '0';
	else if (data->sl.map.grid[data->sl.py + 1][data->sl.px] == 'E')
		exit(0);
	ft_swap_char(data->sl.map.grid[data->sl.py + 1][data->sl.px], data->sl.map.grid[data->sl.py][data->sl.px]);
	data->sl.py++;
	data->render = 1;
}

static void	sl_player_move_left(t_data *data)
{
	if (data->sl.map.grid[data->sl.py][data->sl.px - 1] == 'C')
		data->sl.map.grid[data->sl.py][data->sl.px - 1] = '0';
	else if (data->sl.map.grid[data->sl.py][data->sl.px - 1] == 'E')
		exit(0);
	ft_swap_char(data->sl.map.grid[data->sl.py][data->sl.px - 1], data->sl.map.grid[data->sl.py][data->sl.px]);
	data->sl.px--;
	data->render = 1;
}

static void	sl_player_move_right(t_data *data)
{
	if (data->sl.map.grid[data->sl.py - 1][data->sl.px + 1] == 'C')
		data->sl.map.grid[data->sl.py - 1][data->sl.px + 1] = '0';
	else if (data->sl.map.grid[data->sl.py - 1][data->sl.px + 1] == 'E')
		exit(0);
	ft_swap_char(data->sl.map.grid[data->sl.py][data->sl.px + 1], data->sl.map.grid[data->sl.py][data->sl.px]);
	data->sl.px++;
	data->render = 1;
}

int			sl_press_key(const int key, t_data *data)
{
	printf("Key in digit : %d\n", key);
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_W && data->sl.map.grid[data->sl.py - 1][data->sl.px] != '1')
		sl_player_move_up(data);
	else if (key == KEY_S && data->sl.map.grid[data->sl.py + 1][data->sl.px] != '1')
		sl_player_move_down(data);
	else if (key == KEY_A && data->sl.map.grid[data->sl.py][data->sl.px - 1] != '1')
		sl_player_move_left(data);
	else if (key == KEY_D && data->sl.map.grid[data->sl.py][data->sl.px + 1] != '1')
		sl_player_move_right(data);
	return (0);
}