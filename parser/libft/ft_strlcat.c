/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:17:21 by vseel             #+#    #+#             */
/*   Updated: 2021/10/16 14:14:39 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;
	size_t	realdstsize;
	size_t	i;

	realdstsize = ft_strlen(dst);
	srcsize = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (srcsize);
	if (dstsize <= realdstsize)
		return (srcsize + dstsize);
	while ((src[i]) != '\0' && !(i + realdstsize == dstsize - 1))
	{
		*(dst + i + realdstsize) = *(src + i);
		i++;
	}
	*(dst + i + realdstsize) = '\0';
	return (srcsize + realdstsize);
}
