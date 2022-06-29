/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 00:51:17 by decordel          #+#    #+#             */
/*   Updated: 2022/06/27 21:47:38 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*split_free(char **paths)
{
	size_t	i;

	if (paths)
	{
		i = 0;
		while (paths[i])
			free(paths[i++]);
		free(paths);
	}
	return (NULL);
}

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			n++;
		while (s[i] != c && s[i])
			i++;
	}
	return (n);
}

static size_t	count_chars(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static int	split(char	**str, char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			str[i] = malloc(count_chars(s, c) + 1);
			if (str[i] == NULL)
			{
				split_free(str);
				return (0);
			}
			j = 0;
			while (*s != c && *s)
				str[i][j++] = *(s++);
			str[i++][j] = '\0';
		}
	}
	str[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	if (!s)
		return (NULL);
	str = (char **)malloc(count_words(s, c) * sizeof(str) + 1);
	if (str == NULL)
		return (NULL);
	if (!split(str, s, c))
		return (NULL);
	return (str);
}
