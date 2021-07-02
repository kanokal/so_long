/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_structures.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:44:09 by jpyo              #+#    #+#             */
/*   Updated: 2021/07/02 16:50:31 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_STRUCTURES_H
# define SL_STRUCTURES_H

# define SPRITE_SIZE 64
# define PIXEL_SIZE 48
# define ANIMATION_SPEED 20

# define VIEW_NORTH 0
# define VIEW_SOUTH 1
# define VIEW_WEST 2
# define VIEW_EAST 3

typedef struct		s_img_data
{
	void			*ptr;
	int				*addr;
	int				bpp;
	int				size_line;
	int				endian;
	int				color;
	int				width;
	int				height;
}					t_img_data;

typedef struct		s_texture
{
	int				wall[PIXEL_SIZE * PIXEL_SIZE];
	int				tile[PIXEL_SIZE * PIXEL_SIZE];
	int				player[PIXEL_SIZE * PIXEL_SIZE];
	int				collect[PIXEL_SIZE * PIXEL_SIZE];
	int				exit[PIXEL_SIZE * PIXEL_SIZE];
	int				enemy[PIXEL_SIZE * PIXEL_SIZE];
}					t_texture;

typedef struct		s_canvas
	{
	int				width;
	int				height;
}					t_canvas;

typedef struct		s_sl_map
{
	char			**grid;
	int				width;
	int				height;
	short			exit_point;
	short			collectible;
	short			starting_point;
	short			enemy;
}					t_sl_map;

typedef struct		s_player_data
{
	int				px;
	int				py;
	char			view_dir;
	char			rev;
	int				animation;
	t_bigint		*mv_count;
}					t_player_data;

typedef struct		s_sl_data
{
	double			ratio;
	void			*mlx;
	void			*win;
	t_canvas		canvas;
	t_img_data		img;
	t_img_data		background;
	t_img_data		move;
	t_sl_map		map;
	t_texture		texture;
	t_player_data	player_data;
}					t_sl_data;

#endif
