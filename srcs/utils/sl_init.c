
#include "../../includes/so_long.h"

static void	sl_map_init(t_sl_map *map)
{
	map->grid = NULL;
	map->height = 0;
	map->width = 0;
}

static void	sl_img_init(t_img_data *img)
{
	img->addr = NULL;
	img->bpp = 0;
	img->color = 0;
	img->endian = 0;
	img->ptr = NULL;
	img->size = 0;
}

void		sl_data_init(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	sl_img_init(&data->img);
	data->sl.collectible = 0;
	data->sl.exit_point = 0;
	data->sl.starting_point = 0;
	sl_map_init(&data->sl.map);
	data->sl.px = 0;
	data->sl.py = 0;
	data->render = 0;
	//data->sl.enemy = 0;
}