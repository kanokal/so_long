/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:25:13 by jpyo              #+#    #+#             */
/*   Updated: 2021/06/25 17:41:24 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void    sl_get_point(const char *s, t_so_long *sl)
{
	if (*s == 0)
		return ;
	while (*s != 0)
	{
		if (*s == 'E' && sl->sl_exit == 0)
			sl->sl_exit = 1;
		else if (*s == 'C' && sl->sl_collectible == 0)
			sl->sl_collectible = 1;
		else if (*s == 'P' && sl->sl_starting_position == 0)
			sl->sl_starting_position = 1;
		if (sl->sl_exit == 1 && sl->sl_collectible == 1 && sl->sl_starting_position == 1)
			return ;
		s++;
	}
}

int		sl_is_all_wall(const char *s)
{
	if (*s == 0)
		return (0);
	while (*s != 0)
	{
		if (*s != '1')
			return (0);
		s++;
	}
	return (1);
}
