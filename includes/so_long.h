/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:05:59 by jpyo              #+#    #+#             */
/*   Updated: 2021/07/04 16:44:09 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/includes/libft.h"
# include "../minilibx_mms_20200219/mlx.h"
# include "../minilibx_opengl_20191021/mlx.h"

# include "sl_structures.h"

# define KEYPRESS 02
# define KEYRELEASE 03
# define DESTROYNOTIFY 17

# define KEYPRESS_MASK 1
# define KEYRELEASE_MASK 2

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

# define NORTH 0
# define EAST 1
# define SOUTH 2
# define WEST 3

void	sl_parse(const char *file_name, t_sl_data *data);
void	so_long(t_sl_data *data);

void	sl_render(t_sl_data *data);
void	sl_set_background(t_sl_data *data);
void	sl_player_move(t_sl_data *data);
void	sl_display_move_count(t_sl_data *data);

int		sl_press_key(const int key, t_sl_data *data);
int		sl_press_key2(const int key, t_sl_data *data, int x, int y);
int		sl_release_key(const int key, t_sl_data *data);
int		sl_close(t_sl_data *data);

void	sl_enemy_move(t_sl_data *data, int x, int y);
int		sl_enemy_select(t_sl_data *data, t_enemy_data *enemy);
int		sl_enemy_move_w(t_sl_data *data, t_enemy_data *enemy);
int		sl_enemy_move_c(t_sl_data *data, t_enemy_data *enemy);
int		sl_enemy_turn(t_enemy_data *enemy);

int		sl_is_all_wall(const char *line);
int		sl_is_ok_line(const char *line);
void	sl_set_points(const char *line, t_sl_data *data);
char	**sl_char_more_alloc(char **arr, int arr_size);
void	sl_set_animation(t_sl_data *data);
void	sl_set_enemy_group(t_sl_data *data);

void	sl_data_init(t_sl_data *data);

void	sl_set_player_sprite(t_sl_data *data);
void	sl_set_enemy_sprite(t_sl_data *data);

#endif
