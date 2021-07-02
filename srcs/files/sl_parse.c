/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:15:09 by jpyo              #+#    #+#             */
/*   Updated: 2021/07/02 17:23:32 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	sl_check_line(const int idx, char *line, t_sl_map *map)
{
	if (idx == 0)
	{
		if (sl_is_all_wall(line) != 1)
			ft_error_handling("Error\n");
		map->width = (int)ft_strlen(line);
	}
	else
	{
		if (sl_is_ok_line(line) != 1)
			ft_error_handling("Error\n");
		if ((int)ft_strlen(line) != map->width)
			ft_error_handling("Error\n");
	}
}

static void	sl_set_map_grid(t_sl_map *map, char *line)
{
	map->grid = sl_char_more_alloc(map->grid, map->height);
	if (map->grid == NULL)
		ft_error_handling("Error\n");
	map->grid[map->height] = line;
}

static void	sl_set_map(const int fd, t_sl_data *data)
{
	int		ret;
	char	*line;

	while ((ret = get_next_line(fd, &line)) > 0)
	{
		sl_check_line(data->map.height, line, &data->map);
		sl_set_map_grid(&data->map, line);
		if (data->map.height != 0)
			sl_set_points(line, data);
		data->map.height++;
	}
	if (ret < 0)
		ft_error_handling("Error\n");
	if (sl_is_all_wall(line) != 1)
		ft_error_handling("Error\n");
	if ((int)ft_strlen(line) != data->map.width)
		ft_error_handling("Error\n");
	sl_set_map_grid(&data->map, line);
	data->map.height++;
}

void		sl_parse(const char *file_name, t_sl_data *data)
{
	int			fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		ft_perror_handling("open");
	sl_set_map(fd, data);
	close(fd);
}
