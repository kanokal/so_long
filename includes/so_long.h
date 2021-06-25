/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:05:59 by jpyo              #+#    #+#             */
/*   Updated: 2021/06/25 17:45:46 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/includes/libft.h"
# include "../minilibx_mms_20200219/mlx.h"

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

int	sl_is_all_wall(const char *s);

#endif
