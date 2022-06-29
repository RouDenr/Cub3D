/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 01:28:51 by decordel          #+#    #+#             */
/*   Updated: 2021/12/08 00:09:03 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*cdst;
	unsigned char		*csrc;
	size_t				i;
	size_t				diff;

	if (len == 0)
		return (dst);
	if (!dst && !src)
		return (NULL);
	cdst = (unsigned char *) dst;
	csrc = (unsigned char *) src;
	diff = dst - src;
	i = -1;
	if (dst > src)
		while (++i < len)
			cdst[len - i - 1] = csrc[len - i - 1];
	else
		while (++i < len)
			cdst[i] = cdst[i - diff];
	return (cdst);
}
