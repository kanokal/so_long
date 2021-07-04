/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 17:08:30 by jpyo              #+#    #+#             */
/*   Updated: 2021/07/04 15:14:30 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	sl_set_enemy_north(t_sl_data *data, int *texture)
{
	t_img_data	img;
	int			x;
	int			y;
	int			sprite_x;
	int			sprite_y;

	img = data->sprite_enemy;
	y = 0;
	while (y < PIXEL_SIZE)
	{
		x = 0;
		sprite_y = (int)(y * data->ratio) * img.size_line / 4;
		while (x < PIXEL_SIZE)
		{
			sprite_x = data->animation / ANIMATION_SPEED
						* SPRITE_SIZE + (int)(x * data->ratio);
			texture[y * PIXEL_SIZE + x] = img.addr[sprite_y + sprite_x];
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
	int			sprite_x;
	int			sprite_y;

	img = data->sprite_enemy;
	y = 0;
	while (y < PIXEL_SIZE)
	{
		x = 0;
		sprite_y = img.size_line / 4 * SPRITE_SIZE * 2 +
					(int)(y * data->ratio) * img.size_line / 4;
		while (x < PIXEL_SIZE)
		{
			sprite_x = data->animation / ANIMATION_SPEED
						* SPRITE_SIZE + (int)(x * data->ratio);
			texture[y * PIXEL_SIZE + x] = img.addr[sprite_y + sprite_x];
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
	int			sprite_x;
	int			sprite_y;

	img = data->sprite_enemy;
	y = 0;
	while (y < PIXEL_SIZE)
	{
		x = 0;
		sprite_y = img.size_line / 4 * SPRITE_SIZE * 3 +
					(int)(y * data->ratio) * img.size_line / 4;
		while (x < PIXEL_SIZE)
		{
			sprite_x = data->animation / ANIMATION_SPEED
						* SPRITE_SIZE + (int)(x * data->ratio);
			texture[y * PIXEL_SIZE + x] = img.addr[sprite_y + sprite_x];
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
	int			sprite_x;
	int			sprite_y;

	img = data->sprite_enemy;
	y = 0;
	while (y < PIXEL_SIZE)
	{
		x = 0;
		sprite_y = img.size_line / 4 * SPRITE_SIZE +
					(int)(y * data->ratio) * img.size_line / 4;
		while (x < PIXEL_SIZE)
		{
			sprite_x = data->animation / ANIMATION_SPEED
						* SPRITE_SIZE + (int)(x * data->ratio);
			texture[y * PIXEL_SIZE + x] = img.addr[sprite_y + sprite_x];
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
		if (data->enemies.group[idx].view_dir == NORTH)
			sl_set_enemy_north(data, data->texture.enemy[idx]);
		else if (data->enemies.group[idx].view_dir == SOUTH)
			sl_set_enemy_south(data, data->texture.enemy[idx]);
		else if (data->enemies.group[idx].view_dir == EAST)
			sl_set_enemy_east(data, data->texture.enemy[idx]);
		else if (data->enemies.group[idx].view_dir == WEST)
			sl_set_enemy_west(data, data->texture.enemy[idx]);
		idx++;
	}
}
