/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 22:10:03 by decordel          #+#    #+#             */
/*   Updated: 2021/12/08 00:09:03 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	nlen;

	if (!haystack[0] && needle[0])
		return (NULL);
	i = 0;
	while (needle[i])
		i++;
	if (i == 0)
		return ((char *)(haystack));
	i--;
	nlen = i;
	j = 0;
	while (j + nlen < len || !haystack)
	{
		if (haystack[j + nlen] == needle[nlen])
			while (haystack[j + i] == needle[i])
				if (i-- == 0)
					return ((char *)(haystack + j));
		i = nlen;
		j++;
	}
	return (NULL);
}
