/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 13:59:16 by jpyo              #+#    #+#             */
/*   Updated: 2021/07/03 20:59:13 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	sl_player_north(t_sl_data *data, int *texture)
{
	t_img_data	img;
	int			x;
	int			y;
	int			sprite_x;
	int			sprite_y;

	img = data->sprite_player;
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

static void	sl_player_south(t_sl_data *data, int *texture)
{
	t_img_data	img;
	int			x;
	int			y;
	int			sprite_x;
	int			sprite_y;

	img = data->sprite_player;
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

static void	sl_player_west(t_sl_data *data, int *texture)
{
	t_img_data	img;
	int			x;
	int			y;
	int			sprite_x;
	int			sprite_y;

	img = data->sprite_player;
	y = 0;
	while (y < PIXEL_SIZE)
	{
		x = 0;
		sprite_y = img.size_line / 4 * SPRITE_SIZE +
					(int)(y * data->ratio) * img.size_line / 4;
		while (x < PIXEL_SIZE)
		{
			sprite_x = img.size_line / 4 / 2 +
						data->animation / ANIMATION_SPEED
							* SPRITE_SIZE + (int)(x * data->ratio);
			texture[y * PIXEL_SIZE + x] = img.addr[sprite_y + sprite_x];
			x++;
		}
		y++;
	}
}

static void	sl_player_east(t_sl_data *data, int *texture)
{
	t_img_data	img;
	int			x;
	int			y;
	int			sprite_x;
	int			sprite_y;

	img = data->sprite_player;
	y = 0;
	while (y < PIXEL_SIZE)
	{
		x = 0;
		sprite_y = (int)(y * data->ratio) * img.size_line / 4;
		while (x < PIXEL_SIZE)
		{
			sprite_x = img.size_line / 4 / 2 +
						data->animation / ANIMATION_SPEED
							* SPRITE_SIZE + (int)(x * data->ratio);
			texture[y * PIXEL_SIZE + x] = img.addr[sprite_y + sprite_x];
			x++;
		}
		y++;
	}
}

void		sl_set_player_sprite(t_sl_data *data)
{
	if (data->player.view_dir == VIEW_NORTH)
		sl_player_north(data, data->texture.player);
	else if (data->player.view_dir == VIEW_SOUTH)
		sl_player_south(data, data->texture.player);
	else if (data->player.view_dir == VIEW_EAST)
		sl_player_east(data, data->texture.player);
	else if (data->player.view_dir == VIEW_WEST)
		sl_player_west(data, data->texture.player);
}
