/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:05:47 by jpyo              #+#    #+#             */
/*   Updated: 2021/06/30 20:58:30 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	sl_texture_init(t_sl_data *data, int *texture, char *file_name)
{
	t_img_data	img;
	int			x;
	int			y;

	img.ptr = mlx_xpm_file_to_image(data->mlx, file_name, &img.width, &img.height);
	if (img.ptr == NULL)
		ft_error_handling("Error\n");
	img.addr = (int *)mlx_get_data_addr(img.ptr, &img.bpp, &img.size, &img.endian);
	if (img.height != IMG_H_SIZE || img.width != IMG_W_SIZE)
		ft_error_handling("Error\n");
	// y = 0;
	// while (y < img.height)
	// {
	// 	x = 0;
	// 	while (x < img.width)
	// 	{
	// 		texture[img.width * y + x] = img.addr[img.width * y + x];
	// 		x++;
	// 	}
	// 	y++;
	// }
	x = 0;
	while (x < IMG_H_SIZE * IMG_W_SIZE)
	{
		texture[x] = img.addr[x];
		x++;
	}
	mlx_destroy_image(data->mlx, img.ptr);
}

static void	sl_map_init(t_sl_map *map)
{
	map->grid = NULL;
	map->height = 0;
	map->width = 0;
	map->collectible = 0;
	map->exit_point = 0;
	map->starting_point = 0;
	map->px = 0;
	map->py = 0;
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

void		sl_data_init(t_sl_data *data)
{
	data->mlx = mlx_init();
	data->win = NULL;
	sl_img_init(&data->img);
	sl_map_init(&data->map);
	data->render = 0;
	//data->sl.enemy = 0;
	if (IMG_W_SIZE == 64 && IMG_H_SIZE == 64)
	{
		sl_texture_init(data, data->texture.wall, "textures/64_wall.xpm");
		sl_texture_init(data, data->texture.tile, "textures/64_tile.xpm");
		sl_texture_init(data, data->texture.player, "textures/64_player.xpm");
		sl_texture_init(data, data->texture.collect, "textures/64_collect.xpm");
		sl_texture_init(data, data->texture.exit, "textures/64_exit.xpm");
	}
	else if (IMG_W_SIZE == 128 && IMG_H_SIZE == 128)
	{
		sl_texture_init(data, data->texture.wall, "textures/128_wall.xpm");
		sl_texture_init(data, data->texture.tile, "textures/128_tile.xpm");
		sl_texture_init(data, data->texture.player, "textures/128_player.xpm");
		sl_texture_init(data, data->texture.collect, "textures/128_collect.xpm");
		sl_texture_init(data, data->texture.exit, "textures/128_exit.xpm");
	}
	//sl_texture_init(data, data->sl.texture.enemy, "./textures/enemy.xpm");
}