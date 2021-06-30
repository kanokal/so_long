/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_structures.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:44:09 by jpyo              #+#    #+#             */
/*   Updated: 2021/06/30 20:57:52 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_STRUCTURES_H
# define SL_STRUCTURES_H

# define IMG_W_SIZE 128
# define IMG_H_SIZE 128

typedef struct	s_img_data
{
	void		*ptr;
	int			*addr;
	int			bpp;
	int			size;
	int			endian;
	int			color;
	int			width;
	int			height;
}				t_img_data;

typedef struct	s_texture
{
	int			wall[IMG_H_SIZE * IMG_W_SIZE];
	int			tile[IMG_H_SIZE * IMG_W_SIZE];
	int			player[IMG_H_SIZE * IMG_W_SIZE];
	int			collect[IMG_H_SIZE * IMG_W_SIZE];
	int			exit[IMG_H_SIZE * IMG_W_SIZE];
	//int			enemy[IMG_H_SIZE][IMG_W_SIZE];
}				t_texture;

typedef struct	s_canvas
{
	int			width;
	int			height;
}				t_canvas;

typedef struct	s_sl_map
{
	char		**grid;
	int			width;
	int			height;
	short		exit_point;
	short		collectible;
	short		starting_point;
	//short		enemy;
	int			px;
	int			py;
}				t_sl_map;

typedef struct	s_sl_data
{
	void		*mlx;
	void		*win;
	t_canvas	canvas;
	t_img_data	img;
	t_sl_map	map;
	t_texture	texture;
	char		render;
}				t_sl_data;

#endif
