/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 20:48:53 by vseel             #+#    #+#             */
/*   Updated: 2021/10/17 12:07:19 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_check(char *haystack, char *needle)
{
	if (*needle == '\0')
		return (haystack);
	if (ft_strlen(haystack) < ft_strlen(needle))
		return (NULL);
	return (NULL);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*ptr1;
	char	*ptr2;
	size_t	i;
	size_t	j;

	i = 0;
	ptr1 = (char *)haystack;
	ptr2 = (char *)needle;
	if (*needle == '\0' || ft_strlen(haystack) < ft_strlen(needle))
		return (ft_check(ptr1, ptr2));
	while (i < len && haystack[i])
	{
		j = 0;
		while (ptr1[i + j] == ptr2[j] && ptr1[i + j] != '\0')
		{
			if (i + j == len)
				return (0);
			j++;
		}
		if (ptr2[j] == '\0')
			return (ptr1 + i);
		i++;
	}
	return (0);
}
