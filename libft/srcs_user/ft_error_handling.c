/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:05:42 by jpyo              #+#    #+#             */
/*   Updated: 2021/06/25 17:19:44 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_error_handling(char *msg)
{
	if (msg != NULL)
		write(2, msg, ft_strlen(msg));
	exit(1);
}

void	ft_perror_handling(char *msg)
{
	if (msg != NULL)
		perror(msg);
	else
		ft_error_handling("please write perror message\n");
	exit(1);
}