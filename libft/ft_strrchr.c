/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 00:25:12 by decordel          #+#    #+#             */
/*   Updated: 2021/12/08 00:09:03 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const void *s, int c)
{
	const unsigned char	*buf;
	int					i;

	i = 0;
	buf = s;
	while (buf[i])
		i++;
	while (i >= 0)
	{
		if (buf[i] == (unsigned char)c)
			return ((void *)&buf[i]);
		if (i == 0 && !buf[i])
			return (NULL);
		i--;
	}
	return (NULL);
}
