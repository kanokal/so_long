
#include "../../includes/so_long.h"

int	sl_release_key(const int key, t_data *data)
{
	if (key == KEY_W && data->render == 1)
	{
		data->render = 0;
	}
	else if (key == KEY_S && data->render == 1)
	{
		data->render = 0;
	}
	else if (key == KEY_A && data->render == 1)
	{
		data->render = 0;
	}
	else if (key == KEY_D && data->render == 1)
	{
		data->render = 0;
	}
	return (0);
}