/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <vywnstlr@naver.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 23:53:18 by jpyo              #+#    #+#             */
/*   Updated: 2021/01/17 02:59:18 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	idx;

	if (s == NULL || n == 0)
		return ;
	idx = 0;
	while (idx < n)
	{
		*(char *)(s + idx) = 0;
		idx++;
	}
}