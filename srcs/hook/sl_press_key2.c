
#include "../../includes/so_long.h"

static void	sl_player_move_up(t_sl_data *data)
{
	if (data->map.grid[data->player_data.py - 1][data->player_data.px] == 'W')
		exit(0);
	if (data->map.grid[data->player_data.py - 1][data->player_data.px] == 'C')
		data->map.collectible--;
	data->map.grid[data->player_data.py - 1][data->player_data.px] = 'E';
	ft_swap_char(&data->map.grid[data->player_data.py - 1][data->player_data.px], &data->map.grid[data->player_data.py][data->player_data.px]);
	data->player_data.on_exit = 0;
	data->player_data.py--;
	if (ft_bigint_add_val(data->player_data.mv_count, 1, 0) < 0)
		ft_error_handling("Error\n");
	data->render = 1;
}

static void	sl_player_move_down(t_sl_data *data)
{
	if (data->map.grid[data->player_data.py + 1][data->player_data.px] == 'W')
		exit(0);
	else if (data->map.grid[data->player_data.py + 1][data->player_data.px] == 'C')
		data->map.collectible--;
	data->map.grid[data->player_data.py + 1][data->player_data.px] = 'E';
	ft_swap_char(&data->map.grid[data->player_data.py + 1][data->player_data.px], &data->map.grid[data->player_data.py][data->player_data.px]);
	data->player_data.on_exit = 0;
	data->player_data.py++;
	if (ft_bigint_add_val(data->player_data.mv_count, 1, 0) < 0)
		ft_error_handling("Error\n");
	data->render = 1;
}

static void	sl_player_move_left(t_sl_data *data)
{
	if (data->map.grid[data->player_data.py][data->player_data.px - 1] == 'W')
		exit(0);
	else if (data->map.grid[data->player_data.py][data->player_data.px - 1] == 'C')
		data->map.collectible--;
	data->map.grid[data->player_data.py][data->player_data.px - 1] = 'E';
	ft_swap_char(&data->map.grid[data->player_data.py][data->player_data.px - 1], &data->map.grid[data->player_data.py][data->player_data.px]);
	data->player_data.on_exit = 0;
	data->player_data.px--;
	if (ft_bigint_add_val(data->player_data.mv_count, 1, 0) < 0)
		ft_error_handling("Error\n");
	data->render = 1;
}

static void	sl_player_move_right(t_sl_data *data)
{
	if (data->map.grid[data->player_data.py][data->player_data.px + 1] == 'W')
		exit(0);
	else if (data->map.grid[data->player_data.py][data->player_data.px + 1] == 'C')
		data->map.collectible--;
	data->map.grid[data->player_data.py][data->player_data.px + 1] = 'E';
	ft_swap_char(&data->map.grid[data->player_data.py][data->player_data.px + 1], &data->map.grid[data->player_data.py][data->player_data.px]);
	data->player_data.on_exit = 0;
	data->player_data.px++;
	if (ft_bigint_add_val(data->player_data.mv_count, 1, 0) < 0)
		ft_error_handling("Error\n");
	data->render = 1;
}

int			sl_press_key2(const int key, t_sl_data *data)
{
	printf("Key in digit : %d\n", key);
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_W && data->map.grid[data->player_data.py - 1][data->player_data.px] != '1')
		sl_player_move_up(data);
	else if (key == KEY_S && data->map.grid[data->player_data.py + 1][data->player_data.px] != '1')
		sl_player_move_down(data);
	else if (key == KEY_A && data->map.grid[data->player_data.py][data->player_data.px - 1] != '1')
		sl_player_move_left(data);
	else if (key == KEY_D && data->map.grid[data->player_data.py][data->player_data.px + 1] != '1')
		sl_player_move_right(data);
	return (0);
}