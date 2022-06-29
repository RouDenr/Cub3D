/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 01:17:36 by decordel          #+#    #+#             */
/*   Updated: 2021/12/14 17:15:52 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	le1;

	le1 = 0;
	while (src[le1])
	{
		if (le1 < dstsize - 1 && dstsize)
		{
			dst[le1] = src[le1];
			dst[le1 + 1] = '\0';
		}
		le1++;
	}
	if (le1 == 0 && dstsize > 1)
		dst[le1] = src[le1];
	if (dstsize == 1)
		dst[0] = '\0';
	return (le1);
}
