/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:17:58 by vseel             #+#    #+#             */
/*   Updated: 2021/10/17 12:11:07 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	i;
	size_t	y;

	i = 0;
	if (!s1)
		return (0);
	while (*s1)
	{
		if (ft_strchr(set, *s1) == 0)
			break ;
		s1++;
	}
	y = ft_strlen((char *)s1);
	while (y--)
	{
		if (ft_strrchr(set, s1[y]) == 0)
			break ;
	}
	ptr = ft_substr((char *)s1, 0, y + 1);
	return (ptr);
}
