/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:25:13 by jpyo              #+#    #+#             */
/*   Updated: 2021/07/02 19:06:49 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	sl_set_animation(t_sl_data *data)
{
	if (data->player.rev == 0)
	{
		data->player.animation++;
		if (data->player.animation >= ANIMATION_SPEED * 2.5)
			data->player.rev = 1;
	}
	else if (data->player.rev == 1)
	{
		data->player.animation--;
		if (data->player.animation <= ANIMATION_SPEED * 0.5)
			data->player.rev = 0;
	}
	if (data->enemies.rev == 0)
	{
		data->enemies.animation++;
		if (data->enemies.animation >= ANIMATION_SPEED * 2.5)
			data->enemies.rev = 1;
	}
	else if (data->enemies.rev == 1)
	{
		data->enemies.animation--;
		if (data->enemies.animation <= ANIMATION_SPEED * 0.5)
			data->enemies.rev = 0;
	}
}

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

void    sl_set_points(const char *line, t_sl_data *data)
{
	int	idx;

	idx = 0;
	while (line[idx] != 0)
	{
		if (line[idx] == 'E')
			data->map.exit++;
		else if (line[idx] == 'C')
			data->map.collect++;
		else if (line[idx] == 'P' && data->map.player == 0)
		{
			data->map.player++;
			data->player.pos_y = data->map.height;
			data->player.pos_x = idx;
		}
		else if (line[idx] == 'W')
			data->enemies.count++;
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
