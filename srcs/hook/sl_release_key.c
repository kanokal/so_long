/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_release_key.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:05:22 by jpyo              #+#    #+#             */
/*   Updated: 2021/06/30 18:24:00 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	sl_release_key(const int key, t_sl_data *data)
{
	if (key == KEY_W && data->render == 1)
	{
		data->render = 0;
	}
	else if (key == KEY_S && data->render == 1)
	{
		data->render = 0;
	}
	else if (key == KEY_A && data->render == 1)
	{
		data->render = 0;
	}
	else if (key == KEY_D && data->render == 1)
	{
		data->render = 0;
	}
	return (0);
}