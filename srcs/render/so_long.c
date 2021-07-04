/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:05:51 by jpyo              #+#    #+#             */
/*   Updated: 2021/07/04 16:40:43 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	sl_set_sprite_img(t_sl_data *data)
{
	data->sprite_enemy.ptr = mlx_xpm_file_to_image(data->mlx,
		"textures/enemy.xpm", &data->sprite_enemy.width,
			&data->sprite_enemy.height);
	if (data->sprite_enemy.ptr == NULL)
		ft_error_handling("Error\n");
	data->sprite_enemy.addr =
		(int *)mlx_get_data_addr(data->sprite_enemy.ptr,
			&data->sprite_enemy.bpp, &data->sprite_enemy.size_line,
				&data->sprite_enemy.endian);
	data->sprite_player.ptr = mlx_xpm_file_to_image(data->mlx,
		"textures/player.xpm", &data->sprite_player.width,
			&data->sprite_player.height);
	if (data->sprite_player.ptr == NULL)
		ft_error_handling("Error\n");
	data->sprite_player.addr =
		(int *)mlx_get_data_addr(data->sprite_player.ptr,
			&data->sprite_player.bpp, &data->sprite_player.size_line,
				&data->sprite_player.endian);
}

static int	sl_loop(t_sl_data *data)
{
	sl_set_animation(data);
	if ((data->rev == 0 &&
		(data->animation == ANIMATION_SPEED ||
		data->animation == ANIMATION_SPEED * 2)) ||
		(data->rev == 1 &&
		(data->animation == ANIMATION_SPEED * 2 - 1 ||
		data->animation == ANIMATION_SPEED - 1)))
	{
		sl_set_enemy_sprite(data);
		sl_set_player_sprite(data);
		sl_set_background(data);
		mlx_put_image_to_window(data->mlx, data->win,
			data->background.ptr, 0, 0);
		sl_render(data);
		sl_display_move_count(data);
	}
	return (0);
}

void		so_long(t_sl_data *data)
{
	data->background.ptr = mlx_new_image(data->mlx,
		data->canvas.width, data->canvas.height);
	if (data->background.ptr == NULL)
		ft_error_handling("Error\n");
	data->background.addr =
		(int *)mlx_get_data_addr(data->background.ptr, &data->background.bpp,
			&data->background.size_line, &data->background.endian);
	sl_set_enemy_group(data);
	sl_set_sprite_img(data);
	sl_set_enemy_sprite(data);
	sl_set_background(data);
	mlx_put_image_to_window(data->mlx, data->win, data->background.ptr, 0, 0);
	sl_render(data);
	sl_display_move_count(data);
	mlx_hook(data->win, KEYPRESS, KEYPRESS_MASK, sl_press_key, data);
	mlx_hook(data->win, DESTROYNOTIFY, 0, sl_close, data);
	mlx_loop_hook(data->mlx, sl_loop, data);
	mlx_loop(data->mlx);
}
