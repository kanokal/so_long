/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 17:08:30 by jpyo              #+#    #+#             */
/*   Updated: 2021/07/03 19:14:12 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	sl_set_enemy_north(t_sl_data *data, int *texture)
{
	t_img_data	img;
	int			x;
	int			y;

	//printf("north = %d / VIEW = %d\n", idx, data->enemies.group[idx].view_dir);
	img = data->sprite_enemy;
	y = 0;
	while (y < PIXEL_SIZE)
	{
		x = 0;
		while (x < PIXEL_SIZE)
		{
			texture[y * PIXEL_SIZE + x] = img.addr[data->enemies.animation / ANIMATION_SPEED * SPRITE_SIZE + (int)(y * data->ratio) * img.size_line / 4 + (int)(x * data->ratio)];
			x++;
		}
		y++;
	}
}

static void	sl_set_enemy_south(t_sl_data *data, int *texture)
{
	t_img_data	img;
	int			x;
	int			y;

	//printf("south = %d / VIEW = %d\n", idx, data->enemies.group[idx].view_dir);
	img = data->sprite_enemy;
	y = 0;
	while (y < PIXEL_SIZE)
	{
		x = 0;
		while (x < PIXEL_SIZE)
		{
			texture[y * PIXEL_SIZE + x] = img.addr[img.size_line / 4 * SPRITE_SIZE * 2 + data->enemies.animation / ANIMATION_SPEED * SPRITE_SIZE + (int)(y * data->ratio) * img.size_line / 4 + (int)(x * data->ratio)];
			x++;
		}
		y++;
	}
}

static void	sl_set_enemy_west(t_sl_data *data, int *texture)
{
	t_img_data	img;
	int			x;
	int			y;

	//printf("west = %d / VIEW = %d\n", idx, data->enemies.group[idx].view_dir);
	img = data->sprite_enemy;
	y = 0;
	while (y < PIXEL_SIZE)
	{
		x = 0;
		while (x < PIXEL_SIZE)
		{
			texture[y * PIXEL_SIZE + x] = img.addr[img.size_line / 4 * SPRITE_SIZE * 3 + data->enemies.animation / ANIMATION_SPEED * SPRITE_SIZE + (int)(y * data->ratio) * img.size_line / 4 + (int)(x * data->ratio)];
			x++;
		}
		y++;
	}
}

static void	sl_set_enemy_east(t_sl_data *data, int *texture)
{
	t_img_data	img;
	int			x;
	int			y;

	//printf("east = %d / VIEW = %d\n", idx, data->enemies.group[idx].view_dir);
	img = data->sprite_enemy;
	y = 0;
	while (y < PIXEL_SIZE)
	{
		x = 0;
		while (x < PIXEL_SIZE)
		{
			texture[y * PIXEL_SIZE + x] = img.addr[img.size_line / 4 * SPRITE_SIZE + data->enemies.animation / ANIMATION_SPEED * SPRITE_SIZE + (int)(y * data->ratio) * img.size_line / 4 + (int)(x * data->ratio)];
			x++;
		}
		y++;
	}
}

void		sl_set_enemy_sprite(t_sl_data *data)
{
	int	idx;

	idx = 0;
	while (idx < data->enemies.count)
	{
		if (data->enemies.group[idx].view_dir == VIEW_NORTH)
			sl_set_enemy_north(data, data->texture.enemy[idx]);
		else if (data->enemies.group[idx].view_dir == VIEW_SOUTH)
			sl_set_enemy_south(data, data->texture.enemy[idx]);
		else if (data->enemies.group[idx].view_dir == VIEW_EAST)
			sl_set_enemy_east(data, data->texture.enemy[idx]);
		else if (data->enemies.group[idx].view_dir == VIEW_WEST)
			sl_set_enemy_west(data, data->texture.enemy[idx]);
		idx++;
	}
}
