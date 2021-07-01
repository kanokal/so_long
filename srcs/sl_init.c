/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:05:47 by jpyo              #+#    #+#             */
/*   Updated: 2021/07/01 19:50:31 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	sl_texture_init(t_sl_data *data, int *texture, int size, char *file_name)
{
	t_img_data	img;
	int			x;
	int			y;

	img.ptr = mlx_xpm_file_to_image(data->mlx, file_name, &img.width, &img.height);
	if (img.ptr == NULL)
		ft_error_handling("Error\n");
	img.addr = (int *)mlx_get_data_addr(img.ptr, &img.bpp, &img.size_line, &img.endian);
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			texture[y * size + x] = img.addr[y * img.height * (img.height / size) + x * (img.width / size)];
			x++;
		}
		y++;
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
	map->enemy = 0;
}

static void	sl_img_init(t_img_data *img)
{
	img->addr = NULL;
	img->bpp = 0;
	img->color = 0;
	img->endian = 0;
	img->ptr = NULL;
	img->size_line = 0;
}

static void	sl_player_data_init(t_player_data *player_data)
{
	player_data->px = 0;
	player_data->py = 0;
	player_data->on_exit = 0;
	player_data->mv_count = ft_bigint_create(1);
}

void		sl_data_init(t_sl_data *data)
{
	data->mlx = mlx_init();
	data->win = NULL;
	sl_img_init(&data->img);
	sl_img_init(&data->background);
	sl_img_init(&data->move);
	sl_map_init(&data->map);
	sl_player_data_init(&data->player_data);
	data->render = 0;
	sl_texture_init(data, data->texture.wall, SPRITE_SIZE, "textures/wall.xpm");
	sl_texture_init(data, data->texture.tile, SPRITE_SIZE, "textures/tile.xpm");
	sl_texture_init(data, data->texture.player, SPRITE_SIZE, "textures/player.xpm");
	sl_texture_init(data, data->texture.collect, SPRITE_SIZE, "textures/collect.xpm");
	sl_texture_init(data, data->texture.exit, SPRITE_SIZE, "textures/exit.xpm");
	sl_texture_init(data, data->texture.enemy, SPRITE_SIZE, "textures/enemy.xpm");
}