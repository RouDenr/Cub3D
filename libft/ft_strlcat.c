/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 00:48:18 by decordel          #+#    #+#             */
/*   Updated: 2021/12/08 00:09:03 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	le1;
	size_t	le2;

	le1 = 0;
	le2 = 0;
	while (le1 < dstsize && dst[le1])
	{
		le1++;
	}
	while (src[le2])
	{
		if (le1 < dstsize - 1 && dstsize)
		{
			dst[le1] = src[le2];
			dst[le1 + 1] = '\0';
		}
		le1++;
		le2++;
	}
	return (le1);
}
