/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:25:13 by jpyo              #+#    #+#             */
/*   Updated: 2021/07/01 16:42:23 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	**sl_char_more_alloc(char **arr, int arr_size)
{
	int		idx;
	char	**tmp;

	if (arr_size < 0)
		arr_size = 0;
	tmp = (char **)malloc(sizeof(char *) * (arr_size + 2));
	if (tmp == NULL)
	{
		if (arr != NULL)
			free(arr);
		return (NULL);
	}
	tmp[arr_size + 1] = NULL;
	tmp[arr_size] = NULL;
	idx = 0;
	while (idx < arr_size)
	{
		tmp[idx] = arr[idx];
		idx++;
	}
	if (arr != NULL)
		free(arr);
	return (tmp);
}

int		sl_check_points(t_sl_map map)
{
	if (map.collectible < 1 || map.exit_point < 1 || map.starting_point < 1)
		return (-1);
	return (0);
}

void    sl_set_points(const char *line, t_sl_map *map, t_player_data *p)
{
	int	idx;

	idx = 0;
	while (line[idx] != 0)
	{
		if (line[idx] == 'E')
			map->exit_point++;
		else if (line[idx] == 'C')
			map->collectible++;
		else if (line[idx] == 'P' && map->starting_point == 0)
		{
			map->starting_point++;
			p->py = map->height;
			p->px = idx;
		}
		idx++;
	}
}

int		sl_is_ok_line(const char *line)
{
	int	idx;

	if (*line == 0)
		return (0);
	idx = 0;
	while (line[idx] != 0)
	{
		if (idx == 0 && line[idx] != '1')
			return (0);
		idx++;
	}
	if (line[idx - 1] != '1')
		return (0);
	return (1);
}

int		sl_is_all_wall(const char *line)
{
	if (*line == 0)
		return (0);
	while (*line != 0)
	{
		if (*line != '1')
			return (0);
		line++;
	}
	return (1);
}
