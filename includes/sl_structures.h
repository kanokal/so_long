/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_structures.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:44:09 by jpyo              #+#    #+#             */
/*   Updated: 2021/07/01 17:26:35 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_STRUCTURES_H
# define SL_STRUCTURES_H

# define IMG_W_SIZE 128
# define IMG_H_SIZE 128
# define PIXEL_SIZE 64

typedef struct	s_img_data
{
	void		*ptr;
	int			*addr;
	int			bpp;
	int			size_line;
	int			endian;
	int			color;
	int			width;
	int			height;
}				t_img_data;

typedef struct	s_texture
{
	int			wall[PIXEL_SIZE * PIXEL_SIZE];
	int			tile[PIXEL_SIZE * PIXEL_SIZE];
	int			player[PIXEL_SIZE * PIXEL_SIZE];
	int			collect[PIXEL_SIZE * PIXEL_SIZE];
	int			exit[PIXEL_SIZE * PIXEL_SIZE];
	int			enemy[PIXEL_SIZE * PIXEL_SIZE];
	int			zero[PIXEL_SIZE * PIXEL_SIZE];
	int			one[PIXEL_SIZE * PIXEL_SIZE];
	int			two[PIXEL_SIZE * PIXEL_SIZE];
	int			three[PIXEL_SIZE * PIXEL_SIZE];
	int			four[PIXEL_SIZE * PIXEL_SIZE];
	int			five[PIXEL_SIZE * PIXEL_SIZE];
	int			six[PIXEL_SIZE * PIXEL_SIZE];
	int			seven[PIXEL_SIZE * PIXEL_SIZE];
	int			eight[PIXEL_SIZE * PIXEL_SIZE];
	int			nine[PIXEL_SIZE * PIXEL_SIZE];
	int			ten[PIXEL_SIZE * PIXEL_SIZE];
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
	short		enemy;
}				t_sl_map;

typedef struct	s_player_data
{
	int			px;
	int			py;
	char		on_exit;
	t_bigint	*mv_count;
}				t_player_data;


typedef struct	s_sl_data
{
	void		*mlx;
	void		*win;
	t_canvas	canvas;
	t_img_data	img;
	t_img_data	background;
	t_sl_map	map;
	t_texture	texture;
	char		render;
	t_player_data	player_data;
}				t_sl_data;

#endif
