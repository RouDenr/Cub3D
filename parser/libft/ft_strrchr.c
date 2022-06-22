/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 20:48:53 by vseel             #+#    #+#             */
/*   Updated: 2022/06/22 21:46:57 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;
	char	*buf;

	i = 0;
	ptr = (char *)s;
	buf = 0;
	while (*(ptr + i))
	{
		if (*(ptr + i) == (unsigned char) c)
			buf = ptr + i;
		++i;
	}
	if (*(ptr + i) == (unsigned char) c)
		buf = ptr + i;
	return (buf);
}
