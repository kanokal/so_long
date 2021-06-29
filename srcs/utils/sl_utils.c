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

char	**sl_char_more_alloc(char **arr, int arr_size)
{
	int		idx;
	int		tmp_size;
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
		tmp[idx] = arr[idx];
	if (arr != NULL)
		free(arr);
	return (tmp);
}

int		sl_check_points(t_so_long sl)
{
	if (sl.collectible < 1 || sl.exit_point < 1 || sl.starting_point < 1)
		return (-1);
	return (0);
}

void    sl_set_points(const char *line, t_so_long *sl)
{
	int	idx;

	idx = 0;
	while (line[idx] != 0)
	{
		if (line[idx] == 'E' && sl->exit_point == 0)
			sl->exit_point = 1;
		else if (line[idx] == 'C' && sl->collectible == 0)
			sl->collectible = 1;
		else if (line[idx] == 'P' && sl->starting_point == 0)
		{
			sl->starting_point = 1;
			sl->py = sl->map.height;
			sl->px = idx;
		}
		//else if (line[idx] == 'E' && sl->sl_starting_position == 0)
		//	sl->enemy = 1;
		if (sl->exit_point == 1 && sl->collectible == 1 && sl->starting_point == 1)
			return ;
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
