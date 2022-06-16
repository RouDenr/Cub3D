/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:17:58 by vseel             #+#    #+#             */
/*   Updated: 2022/05/03 15:21:59 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (c == 0)
		return (1);
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
				i++;
			count++;
		}
		i++;
	}
	return (count);
}

static size_t	ft_strlen_stopchar(const char *s, char c)
{
	int	i;

	i = 0;
	while (*(s + i) && *(s + i) != c)
		i++;
	return (i);
}

static char	**ft_free(char **res, size_t j)
{
	while (j >= 0)
		free(res[j--]);
	free (res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	count;
	char	**res;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	count = ft_wordcount(s, c);
	res = (char **)malloc((sizeof(char *) * (count + 1)));
	if (!res)
		return (0);
	while (s[i] != '\0' && j < count)
	{
		while (s[i] == c)
			i++;
		res[j] = ft_substr(s, i, ft_strlen_stopchar(&s[i], c));
		if (!res[j])
			return (ft_free(res, j));
		i = i + ft_strlen_stopchar(&s[i], c);
		j++;
	}
	res[j] = NULL;
	return (res);
}
