/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_structures.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:44:09 by jpyo              #+#    #+#             */
/*   Updated: 2021/07/04 16:42:30 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_STRUCTURES_H
# define SL_STRUCTURES_H

# define SPRITE_SIZE 64
# define PIXEL_SIZE 48
# define ANIMATION_SPEED 3500

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
	int				**enemy;
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
	short			exit;
	short			collect;
	short			player;
}					t_sl_map;

typedef struct		s_player_data
{
	int				pos_x;
	int				pos_y;
	char			view_dir;
	t_bigint		*mv_count;
}					t_player_data;

typedef struct		s_enemy_data
{
	int				number;
	int				pos_x;
	int				pos_y;
	char			view_dir;
}					t_enemy_data;

typedef struct		s_enemy_group
{
	int				count;
	char			turn;
	t_enemy_data	*group;
}					t_enemy_group;

typedef struct		s_sl_data
{
	double			ratio;
	void			*mlx;
	void			*win;
	t_canvas		canvas;
	t_img_data		img;
	t_img_data		background;
	t_img_data		sprite_player;
	t_img_data		sprite_enemy;
	t_sl_map		map;
	t_texture		texture;
	t_player_data	player;
	t_enemy_group	enemies;
	int				animation;
	char			rev;
}					t_sl_data;

#endif
