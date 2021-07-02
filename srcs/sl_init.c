/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:05:47 by jpyo              #+#    #+#             */
/*   Updated: 2021/07/02 16:44:33 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	sl_texture_init(t_sl_data *data, int *texture, char *file_name)
{
	t_img_data	img;
	int			x;
	int			y;
	int			pos_x;
	int			pos_y;

	img.ptr = mlx_xpm_file_to_image(data->mlx, file_name, &img.width, &img.height);
	if (img.ptr == NULL)
		ft_error_handling("Error\n");
	img.addr = (int *)mlx_get_data_addr(img.ptr, &img.bpp, &img.size_line, &img.endian);
	y = 0;
	while (y < PIXEL_SIZE)
	{
		x = 0;
		while (x < PIXEL_SIZE)
		{
			//printf("%d\n", (int)(y * data->ratio) * img.width + (int)(x * data->ratio));
			pos_y = y * data->ratio;
			pos_x = x * data->ratio;
			//printf("%d %d\n", pos_x, img.width);
			texture[y * PIXEL_SIZE + x] = img.addr[pos_y * img.width + pos_x];
			//texture[y * PIXEL_SIZE + x] = img.addr[y * img.width * (SPRITE_SIZE / PIXEL_SIZE) + x * (SPRITE_SIZE / PIXEL_SIZE)];
			//texture[y * PIXEL_SIZE + x] = img.addr[y * img.width + x];
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
	player_data->mv_count = ft_bigint_create(1);
	player_data->view_dir = VIEW_SOUTH;
	player_data->animation = ANIMATION_SPEED * 0.5;
	player_data->rev = 0;
}

void		sl_data_init(t_sl_data *data)
{
	data->ratio = (double)SPRITE_SIZE / PIXEL_SIZE;
	data->mlx = mlx_init();
	data->win = NULL;
	sl_img_init(&data->img);
	sl_img_init(&data->background);
	sl_img_init(&data->move);
	sl_map_init(&data->map);
	sl_player_data_init(&data->player_data);
	sl_texture_init(data, data->texture.wall, "textures/wall.xpm");
	sl_texture_init(data, data->texture.tile, "textures/tile.xpm");
	sl_texture_init(data, data->texture.collect, "textures/collect.xpm");
	sl_texture_init(data, data->texture.exit, "textures/exit.xpm");
	sl_texture_init(data, data->texture.enemy, "textures/enemy.xpm");
	sl_texture_init(data, data->texture.player, "textures/player.xpm");
}