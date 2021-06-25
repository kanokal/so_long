/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:15:09 by jpyo              #+#    #+#             */
/*   Updated: 2021/06/25 17:43:19 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	sl_parse(char *fn)
{
	int		idx;
	int		fd;
	int		ret;
	char	*line;

	fd = open(fn, O_RDONLY);
	if (fd < 0)
		ft_perror_handling("open");
	idx = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (idx == 0 && sl_is_all_wall(line) != 1)
			ft_error_handling("Error\n");
		/*
		**	렌더링
		*/
		ft_free_ptr(&line);
		idx++;
	}
	if (ret < 0)
		ft_error_handling("Error\n");
	if (sl_is_all_wall(line) != 1)
		ft_error_handling("Error\n");
	ft_free_ptr(&line);
}
