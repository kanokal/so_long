/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:28:28 by jpyo              #+#    #+#             */
/*   Updated: 2021/06/25 17:28:35 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void		my_mlx_pixel_put(t_img_data *img_data, int x, int y, int color)
{
	char	*dst;

	dst = img_data->addr + (y * img_data->size + x * (img_data->bpp / 8));
	*(unsigned int *)dst = color;
}

static void		my_mlx_string_put(t_img_data *img_data, int x, int y, int color)
{
	char	*dst;

	dst = img_data->addr + (y * img_data->size + x * (img_data->bpp / 8));
	*(unsigned int *)dst = color;
}

static void		write_color(t_img_data *img, t_vec3 c) 
{
	int	ir;
	int	ig;
	int	ib;

	ir = (int)ft_clamp((255.0 * c.x), 255.0, 0);
	ig = (int)ft_clamp((255.0 * c.y), 255.0, 0);
	ib = (int)ft_clamp((255.0 * c.z), 255.0, 0);
	img->color = (ir << 16) + (ig << 8) + ib;
}

int				sl_render(t_data *data, const char *line)
{
	while (*line != 0)
	{
		line++;
	}
	return (0);
}