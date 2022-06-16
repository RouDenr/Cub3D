/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 20:48:53 by vseel             #+#    #+#             */
/*   Updated: 2022/06/16 23:30:06 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && *(s + i))
		++i;
	return (i);
}

size_t	ft_strlen_szof(const char *s)
{
	return (sizeof(s) - 1);
}

int	ft_strlen_s(const char *s, char c)
{
	int	i;

	i = 0;
	while (*(s + i) && *(s + i) != c)
		++i;
	return (i);
}

// size_t	ft_strlen_stopchars(const char *s, char *stopchar)
// {
// 	int	i;
// 	int	min_len;

// 	min_len = INT_MAX;
// 	while (*stopchar)
// 	{
// 		i = 0;
// 		while (*(s + i) && *(s + i) != *stopchar)
// 			++i;
// 		if (i < min_len)
// 			min_len = i;		
// 		++stopchar;
// 	}
// 	return (min_len);
// }
