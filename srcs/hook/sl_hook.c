/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:23:01 by jpyo              #+#    #+#             */
/*   Updated: 2021/06/25 17:45:25 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	mouse_click(int button, int x, int y, t_data *data)
{
	printf("X and Y = (%d , %d)\n", x, y);
	return (0);
}

int	press_key(int key, t_data *data)
{
	printf("Key in digit : %d\n", key);
	if (key == KEY_ESC)
		exit(0);
	/*
	else if (key == KEY_PAGE_UP)
	{
	}
	else if (key == KEY_PAGE_DOWN)
	{
	}
	else if (key == KEY_UP)
	{
	}
	*/
	return (0);
}

int	release_key(int key, t_data *data)
{
	if (key == KEY_PAGE_UP)
	{
		data->cam_previous = 1;
	}
	else if (key == KEY_PAGE_DOWN)
	{
		data->cam_next = 1;
	}
	return (0);
}

int	ft_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}