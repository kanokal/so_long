/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:05:38 by jpyo              #+#    #+#             */
/*   Updated: 2021/07/04 16:41:53 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char *argv[])
{
	t_sl_data	data;

	if (argc == 2)
	{
		sl_data_init(&data);
		sl_parse(argv[1], &data);
		if (data.map.collect < 1 || data.map.exit < 1 || data.map.player < 1)
			ft_error_handling("Error\n");
		data.win = mlx_new_window(data.mlx,
			data.canvas.width, data.canvas.height, "so_long");
		if (data.win == NULL)
			ft_error_handling("Error\n");
		data.img.ptr = mlx_new_image(data.mlx,
			data.canvas.width, data.canvas.height);
		if (data.img.ptr == NULL)
			ft_error_handling("Error\n");
		data.img.addr = (int *)mlx_get_data_addr(data.img.ptr,
			&data.img.bpp, &data.img.size_line, &data.img.endian);
		so_long(&data);
	}
	return (0);
}
