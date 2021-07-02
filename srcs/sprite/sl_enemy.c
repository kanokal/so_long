/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 17:08:30 by jpyo              #+#    #+#             */
/*   Updated: 2021/07/02 19:10:28 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	sl_enemy_north(t_sl_data *data, int *texture, char *file_name)
{
	t_img_data	img;
	int			x;
	int			y;

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
			texture[y * PIXEL_SIZE + x] = img.addr[data->player.animation / ANIMATION_SPEED * SPRITE_SIZE + (int)(y * data->ratio) * img.size_line / 4 + (int)(x * data->ratio)];
			x++;
		}
		y++;
	}
	mlx_destroy_image(data->mlx, img.ptr);
}

static void	sl_enemy_south(t_sl_data *data, int *texture, char *file_name)
{
	t_img_data	img;
	int			x;
	int			y;

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
			texture[y * PIXEL_SIZE + x] = img.addr[img.size_line / 4 * SPRITE_SIZE * 2 + data->player.animation / ANIMATION_SPEED * SPRITE_SIZE + (int)(y * data->ratio) * img.size_line / 4 + (int)(x * data->ratio)];
			x++;
		}
		y++;
	}
	mlx_destroy_image(data->mlx, img.ptr);
}

static void	sl_enemy_west(t_sl_data *data, int *texture, char *file_name)
{
	t_img_data	img;
	int			x;
	int			y;

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
			texture[y * PIXEL_SIZE + x] = img.addr[img.size_line / 4 * SPRITE_SIZE * 3 + data->player.animation / ANIMATION_SPEED * SPRITE_SIZE + (int)(y * data->ratio) * img.size_line / 4 + (int)(x * data->ratio)];
			x++;
		}
		y++;
	}
	mlx_destroy_image(data->mlx, img.ptr);
}

static void	sl_enemy_east(t_sl_data *data, int *texture, char *file_name)
{
	t_img_data	img;
	int			x;
	int			y;

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
			texture[y * PIXEL_SIZE + x] = img.addr[img.size_line / 4 * SPRITE_SIZE + data->player.animation / ANIMATION_SPEED * SPRITE_SIZE + (int)(y * data->ratio) * img.size_line / 4 + (int)(x * data->ratio)];
			x++;
		}
		y++;
	}
	mlx_destroy_image(data->mlx, img.ptr);
}

void		sl_set_enemy_sprite(t_sl_data *data)
{
	int	idx;
	
	idx = 0;
	while (idx < data->enemies.count)
	{
		if (data->enemies.group[idx].view_dir == VIEW_NORTH)
			sl_enemy_north(data, data->texture.enemy[idx], "textures/enemy.xpm");
		else if (data->enemies.group[idx].view_dir == VIEW_SOUTH)
			sl_enemy_south(data, data->texture.enemy[idx], "textures/enemy.xpm");
		else if (data->enemies.group[idx].view_dir == VIEW_EAST)
			sl_enemy_east(data, data->texture.enemy[idx], "textures/enemy.xpm");
		else if (data->enemies.group[idx].view_dir == VIEW_WEST)
			sl_enemy_west(data, data->texture.enemy[idx], "textures/enemy.xpm");
		idx++;
	}
}
