/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:05:38 by jpyo              #+#    #+#             */
/*   Updated: 2021/06/30 21:16:50 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	write_color(t_img_data *img, int ir, int ig, int ib) 
{
	if (ir > 255)
		ir = 255;
	if (ir < 0)
		ir = 0;
	if (ig > 255)
		ig = 255;
	if (ig < 0)
		ig = 0;
	if (ib > 255)
		ib = 255;
	if (ib < 0)
		ib = 0;
	img->color = (ir << 16) + (ig << 8) + ib;
}

int main(int argc, char *argv[])
{
	t_sl_data	data;

	if (argc == 2)
	{
		sl_data_init(&data);
		sl_parse(argv[1], &data);
		if (sl_check_points(data.map) != 0)
			ft_error_handling("Error\n");
		data.canvas.width = data.map.width * IMG_W_SIZE;
		data.canvas.height = data.map.height * IMG_H_SIZE;
		data.win = mlx_new_window(data.mlx, data.canvas.width, data.canvas.height, "so_long");
		data.img.ptr = mlx_new_image(data.mlx, data.canvas.width, data.canvas.height);
		data.img.addr = (int *)mlx_get_data_addr(data.img.ptr, &data.img.bpp, &data.img.size, &data.img.endian);
		so_long(&data);
	}
	else
	{
		sl_data_init(&data);
		data.win = mlx_new_window(data.mlx, 512, 512, "so_long");
		data.img.ptr = mlx_new_image(data.mlx, 512, 512);
		data.img.addr = (int *)mlx_get_data_addr(data.img.ptr, &data.img.bpp, &data.img.size, &data.img.endian);
		//printf("%d %d\n", data.img.size, data.img.bpp);
		int		i;
		int		j;

		j = 0;
		while (j < IMG_H_SIZE)	
		{
			i = 0;
			while (i < IMG_W_SIZE)
			{
				data.img.addr[(j * data.img.size + 0 * (data.img.bpp / 8)) + i] = data.texture.player[j * 128 + i];
				i++;
			}
			j++;
		}
		// j = 0;
		// while (j < IMG_H_SIZE)	
		// {
		// 	i = 0;
		// 	while (i < IMG_W_SIZE)
		// 	{
		// 		data.img.addr[j * 512 + 4 * 96 + i] = data.texture.player[j * 128 + i];
		// 		i++;
		// 	}
		// 	j++;
		// }
		// j = 0;
		// while (j < IMG_H_SIZE)	
		// {
		// 	i = 0;
		// 	while (i < IMG_W_SIZE)
		// 	{
		// 		data.img.addr[j * 128 + i] = data.texture.player[j * 128 + i];
		// 		i++;
		// 	}
		// 	j++;
		// }
		// i = 0;
		// while (i < IMG_H_SIZE * IMG_W_SIZE)
		// {
		// 	data.img.addr[IMG_H_SIZE * IMG_W_SIZE + i] = data.texture.player[i];
		// 	i++;
		// }
		mlx_put_image_to_window(data.mlx, data.win, data.img.ptr, 0, 0);
		mlx_loop(data.mlx);
	}
	return (0);
}
