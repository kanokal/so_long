/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:05:47 by jpyo              #+#    #+#             */
/*   Updated: 2021/07/04 18:13:38 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	sl_texture_init(t_sl_data *data, int *texture, char *file_name)
{
	t_img_data	img;
	int			x;
	int			y;

	img.ptr = mlx_xpm_file_to_image(data->mlx, file_name,
		&img.width, &img.height);
	if (img.ptr == NULL)
		ft_error_handling("Error\nFailed xpm to image on init\n");
	img.addr = (int *)mlx_get_data_addr(img.ptr, &img.bpp,
		&img.size_line, &img.endian);
	y = 0;
	while (y < PIXEL_SIZE)
	{
		x = 0;
		while (x < PIXEL_SIZE)
		{
			texture[y * PIXEL_SIZE + x] = img.addr[(int)(y * data->ratio) *
				img.size_line / 4 + (int)(x * data->ratio)];
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
	map->collect = 0;
	map->exit = 0;
	map->player = 0;
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

static void	sl_player_data_init(t_player_data *player)
{
	player->pos_x = 0;
	player->pos_y = 0;
	player->mv_count = ft_bigint_create(1);
	player->view_dir = SOUTH;
}

void		sl_data_init(t_sl_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		ft_error_handling("Error\nFailed mlx init\n");
	data->ratio = (double)SPRITE_SIZE / PIXEL_SIZE;
	data->win = NULL;
	sl_img_init(&data->img);
	sl_img_init(&data->background);
	sl_img_init(&data->sprite_player);
	sl_img_init(&data->sprite_enemy);
	sl_map_init(&data->map);
	sl_player_data_init(&data->player);
	data->enemies.group = NULL;
	data->enemies.count = 0;
	data->enemies.turn = 0;
	sl_texture_init(data, data->texture.wall, "textures/wall.xpm");
	sl_texture_init(data, data->texture.tile, "textures/tile.xpm");
	sl_texture_init(data, data->texture.collect, "textures/collect.xpm");
	sl_texture_init(data, data->texture.exit, "textures/exit.xpm");
	sl_texture_init(data, data->texture.player, "textures/player.xpm");
	data->rev = 0;
	data->animation = ANIMATION_SPEED * 0.5;
}
