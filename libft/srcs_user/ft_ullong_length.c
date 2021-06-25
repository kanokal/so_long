/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullong_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <vywnstlr@naver.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 19:16:17 by jpyo              #+#    #+#             */
/*   Updated: 2021/01/30 19:16:17 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Calculate the number of digits in base.
*/

size_t	ft_ullong_length(unsigned long long n, int base_length)
{
	int	len;

	len = 0;
	while (n)
	{
		n = n / base_length;
		len++;
	}
	if (len == 0)
		return (1);
	return (len);
}
