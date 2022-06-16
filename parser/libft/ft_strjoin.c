/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:17:58 by vseel             #+#    #+#             */
/*   Updated: 2022/05/20 12:40:19 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** 
 * Join 's2' to 's1' | 
 * if s1 doesn't exist - return empty string | 
 * if s2 doesn't exist - return copy of s1 | 
 * return NULL if malloc() fail | 
 * Allocates memory!
 * @return s1 + s2 + '\0'
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	i;
	size_t	j;
	size_t	y;

	if (!s1)
		return (ft_strdup(""));
	if (!s2 || !*s2)
		return (ft_strdup(s1));
	ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	y = 0;
	while (s2[j] != '\0')
	{
		while (s1[i] != '\0')
			ptr[y++] = s1[i++];
		ptr[y++] = s2[j++];
	}
	ptr[y] = '\0';
	return (ptr);
}
