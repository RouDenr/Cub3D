/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:57:31 by vseel             #+#    #+#             */
/*   Updated: 2022/06/16 23:30:57 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup_free(const char *s1, char tofree)
{
	char	*ptr;
	size_t	i;

	i = 0;
	while (*(s1 + i))
		i++;
	ptr = (char *)malloc(i + 1);
	if (ptr == 0)
		return (0);
	i = 0;
	while (*(s1 + i))
	{
		*(ptr + i) = *(s1 + i);
		i++;
	}
	*(ptr + i) = '\0';
	if (tofree == 'y')
		free((char *)s1);
	return (ptr);
}

char	*ft_substr_free(char const *s,
	unsigned int start, size_t len, char fr)
{
	char			*ptr;
	unsigned int	i;
	size_t			len2;

	if (!s)
		return (ft_strdup_free("", 'n'));
	len2 = ft_strlen_s(s, 0);
	if (start >= len2)
		return (ft_strdup_free("", 'n'));
	if (start + len < len2)
		len2 = start + len;
	ptr = malloc(len2 - start + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	if (fr == 'y')
		free((char *)s);
	return (ptr);
}

char	*ft_strjoin_free(char *s1, char const *s2)
{
	char	*ptr;
	size_t	i;
	size_t	j;
	size_t	y;

	if (!s1)
		s1 = ft_strdup_free("", 'n');
	if (*s2 == '\0')
		return (ft_strdup_free(s1, 'y'));
	ptr = malloc(ft_strlen_s(s1, 0) + ft_strlen_s(s2, 0) + 1);
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
	free(s1);
	return (ptr);
}
