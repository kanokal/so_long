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

static t_camera	*minirt_get_cur_cam(t_object *cam_list, int cam_nbr)
{
	int			idx;
	t_object	*tmp;

	idx = 0;
	tmp = cam_list;
	while (idx < cam_nbr)
	{
		tmp = tmp->next;
		idx++;
	}
	return ((t_camera *)tmp->element);
}

int				minirt_render(t_data *data, int bmp)
{
	int			i;
	int			j;
	double		u;
	double		v;
	t_camera	*cur_cam;
	t_pixel		**pixel;
	t_color		pixel_color;

	cur_cam = minirt_get_cur_cam(data->scene.cam_list, data->cam);
//	if (bmp == 1)
//		pixel = minirt_create_pixel(data->scene.canvas.width, data->scene.canvas.height);
	j = 0;
	while (j < data->scene.canvas.height)
	{
		i = 0;
		while (i < data->scene.canvas.width)
		{
			u = (double)i / (data->scene.canvas.width - 1);
			v = (data->scene.canvas.height - (double)j - 1) / (data->scene.canvas.height - 1);
			data->scene.ray = ray_primary(cur_cam, u, v);
			pixel_color = ray_color(data->scene);
			write_color(&data->img, pixel_color);
			my_mlx_pixel_put(&data->img, i, j, data->img.color);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, 0, 0);
	return (0);
}