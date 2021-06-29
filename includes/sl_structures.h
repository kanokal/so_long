/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_structures.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:44:09 by jpyo              #+#    #+#             */
/*   Updated: 2021/06/25 17:45:12 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_STRUCTURES_H
# define SL_STRUCTURES_H

typedef struct	s_img_data
{
	void		*ptr;
	char		*addr;
	int			bpp;
	int			size;
	int			endian;
	int			color;
}				t_img_data;

typedef struct	s_sl_map
{
	char		**grid;
	int			width;
	int			height;
}				t_sl_map;

typedef struct	s_so_long
{
	short		exit_point;
	short		collectible;
	short		starting_point;
	//short		enemy;
	short		px;
	short		py;
	t_sl_map	map;
}				t_so_long;


typedef struct	s_data
{
	void		*mlx;
	void		*win;
	t_img_data	img;
	t_so_long	sl;
	char		render;
}				t_data;

#endif
