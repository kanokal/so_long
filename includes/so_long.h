/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:05:59 by jpyo              #+#    #+#             */
/*   Updated: 2021/06/30 19:58:29 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/includes/libft.h"
# include "../minilibx_mms_20200219/mlx.h"
# include "../minilibx_opengl_20191021/mlx.h"

# include <stdio.h>
# include "sl_structures.h"

# define KEYPRESS 02
# define KEYRELEASE 03
# define DESTROYNOTIFY 17

# define KEYPRESS_MASK 1L << 0
# define KEYRELEASE_MASK 1L << 1

# define KEY_ESC 53
# define KEY_PAGE_UP 116
# define KEY_PAGE_DOWN 121
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

void	sl_parse(const char *file_name, t_sl_data *data);
void	so_long(t_sl_data *data);
void	sl_render(t_sl_data *data);

int		sl_press_key(const int key, t_sl_data *data);
int		sl_release_key(const int key, t_sl_data *data);
int		sl_close(t_sl_data *data);

int	    sl_is_all_wall(const char *line);
int		sl_is_ok_line(const char *line);
void    sl_set_points(const char *line, t_sl_map *map);
char	**sl_char_more_alloc(char **arr, int arr_size);
int		sl_check_points(t_sl_map map);

void	sl_data_init(t_sl_data *data);

#endif
