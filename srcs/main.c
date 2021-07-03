/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:05:38 by jpyo              #+#    #+#             */
/*   Updated: 2021/07/03 19:05:02 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	sl_set_sprite_img(t_sl_data *data)
{
	data->sprite_enemy.ptr = mlx_xpm_file_to_image(data->mlx, "textures/enemy.xpm", &data->sprite_enemy.width, &data->sprite_enemy.height);
	if (data->sprite_enemy.ptr == NULL)
		ft_error_handling("Error\n");
	data->sprite_enemy.addr = (int *)mlx_get_data_addr(data->sprite_enemy.ptr, &data->sprite_enemy.bpp, &data->sprite_enemy.size_line, &data->sprite_enemy.endian);
	data->sprite_player.ptr = mlx_xpm_file_to_image(data->mlx, "textures/player.xpm", &data->sprite_player.width, &data->sprite_player.height);
	if (data->sprite_player.ptr == NULL)
		ft_error_handling("Error\n");
	data->sprite_player.addr = (int *)mlx_get_data_addr(data->sprite_player.ptr, &data->sprite_player.bpp, &data->sprite_player.size_line, &data->sprite_player.endian);
}

int main(int argc, char *argv[])
{
	t_sl_data	data;

	if (argc == 2)
	{
		sl_data_init(&data);
		sl_parse(argv[1], &data);
		if (data.map.collect < 1 || data.map.exit < 1 || data.map.player < 1)
			ft_error_handling("Error\n");
		data.canvas.width = data.map.width * PIXEL_SIZE;
		data.canvas.height = data.map.height * PIXEL_SIZE;
		data.win = mlx_new_window(data.mlx, data.canvas.width, data.canvas.height, "so_long");
		data.img.ptr = mlx_new_image(data.mlx, data.canvas.width, data.canvas.height);
		if (data.img.ptr == NULL)
			ft_error_handling("Error\n");
		data.img.addr = (int *)mlx_get_data_addr(data.img.ptr, &data.img.bpp, &data.img.size_line, &data.img.endian);
		data.background.ptr = mlx_new_image(data.mlx, data.canvas.width, data.canvas.height);
		if (data.background.ptr == NULL)
			ft_error_handling("Error\n");
		data.background.addr = (int *)mlx_get_data_addr(data.background.ptr, &data.background.bpp, &data.background.size_line, &data.background.endian);
		sl_set_enemy_group(&data);
		sl_set_sprite_img(&data);
		sl_set_enemy_sprite(&data);
		so_long(&data);
	}
	return (0);
}
