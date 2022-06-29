/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 21:43:09 by decordel          #+#    #+#             */
/*   Updated: 2021/12/08 00:09:03 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	const char			*buf;
	size_t				i;

	i = 0;
	buf = s;
	while (buf[i])
	{
		if (buf[i] == (unsigned char)c)
			return ((char *)&buf[i]);
		i++;
	}
	if (buf[i] == c)
		return ((char *)&buf[i]);
	return (NULL);
}
