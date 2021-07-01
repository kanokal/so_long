/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:05:38 by jpyo              #+#    #+#             */
/*   Updated: 2021/07/01 19:50:46 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(int argc, char *argv[])
{
	t_sl_data	data;

	printf("%d\n", SPRITE_SIZE);
	if (argc == 2)
	{
		sl_data_init(&data);
		sl_parse(argv[1], &data);
		if (sl_check_points(data.map) != 0)
			ft_error_handling("Error\n");
		data.canvas.width = data.map.width * SPRITE_SIZE;
		data.canvas.height = data.map.height * SPRITE_SIZE;
		data.win = mlx_new_window(data.mlx, data.canvas.width, data.canvas.height, "so_long");
		data.img.ptr = mlx_new_image(data.mlx, data.canvas.width, data.canvas.height);
		if (data.img.ptr == NULL)
			ft_error_handling("Error\n");
		data.img.addr = (int *)mlx_get_data_addr(data.img.ptr, &data.img.bpp, &data.img.size_line, &data.img.endian);
		data.background.ptr = mlx_new_image(data.mlx, data.canvas.width, data.canvas.height);
		if (data.background.ptr == NULL)
			ft_error_handling("Error\n");
		data.background.addr = (int *)mlx_get_data_addr(data.background.ptr, &data.background.bpp, &data.background.size_line, &data.background.endian);
		so_long(&data);
	}
	return (0);
}
