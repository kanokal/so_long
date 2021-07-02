/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 13:59:16 by jpyo              #+#    #+#             */
/*   Updated: 2021/07/02 16:19:20 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	sl_player_north(t_sl_data *data, int *texture, char *file_name)
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
			texture[y * PIXEL_SIZE + x] = img.addr[img.width * SPRITE_SIZE + data->player_data.animation / ANIMATION_SPEED * SPRITE_SIZE + (int)(y * data->ratio) * img.width + (int)(x * data->ratio)];
			x++;
		}
		y++;
	}
	mlx_destroy_image(data->mlx, img.ptr);
}

static void	sl_player_south(t_sl_data *data, int *texture, char *file_name)
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
			texture[y * PIXEL_SIZE + x] = img.addr[data->player_data.animation / ANIMATION_SPEED * SPRITE_SIZE + (int)(y * data->ratio) * img.width + (int)(x * data->ratio)];
			x++;
		}
		y++;
	}
	mlx_destroy_image(data->mlx, img.ptr);
}

static void	sl_player_west(t_sl_data *data, int *texture, char *file_name)
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
			texture[y * PIXEL_SIZE + x] = img.addr[img.width * SPRITE_SIZE + img.width / 2 + data->player_data.animation / ANIMATION_SPEED * SPRITE_SIZE + (int)(y * data->ratio) * img.width + (int)(x * data->ratio)];
			x++;
		}
		y++;
	}
	mlx_destroy_image(data->mlx, img.ptr);
}

static void	sl_player_east(t_sl_data *data, int *texture, char *file_name)
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
			texture[y * PIXEL_SIZE + x] = img.addr[img.width / 2 + data->player_data.animation / ANIMATION_SPEED * SPRITE_SIZE + (int)(y * data->ratio) * img.width + (int)(x * data->ratio)];
			x++;
		}
		y++;
	}
	mlx_destroy_image(data->mlx, img.ptr);
}

void		sl_set_player(t_sl_data *data)
{
	if (data->player_data.view_dir == VIEW_NORTH)
		sl_player_north(data, data->texture.player, "textures/player.xpm");
	else if (data->player_data.view_dir == VIEW_SOUTH)
		sl_player_south(data, data->texture.player, "textures/player.xpm");
	else if (data->player_data.view_dir == VIEW_EAST)
		sl_player_east(data, data->texture.player, "textures/player.xpm");
	else if (data->player_data.view_dir == VIEW_WEST)
		sl_player_west(data, data->texture.player, "textures/player.xpm");
}
