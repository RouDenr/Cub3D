/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:45:11 by decordel          #+#    #+#             */
/*   Updated: 2021/12/08 00:09:03 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	ft_bzero(void *s, size_t n)
{
	char	*c;

	c = s;
	while (n-- > 0)
	{
		*c = '\0';
		c++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char		*buf;

	buf = NULL;
	if (count)
	{
		buf = malloc(count * size);
		if (buf == NULL)
			return (NULL);
		ft_bzero(buf, count * size);
	}
	else
	{
		buf = malloc(size);
		if (buf == NULL)
			return (NULL);
		ft_bzero(buf, size);
	}
	return (buf);
}
