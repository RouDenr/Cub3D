/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:17:02 by vseel             #+#    #+#             */
/*   Updated: 2021/10/16 14:13:52 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *)s;
	while (*(ptr + i))
	{
		if (*(ptr + i) == (unsigned char) c)
		{
			return (ptr + i);
		}
		i++;
	}
	if (*(ptr + i) == (unsigned char) c)
	{
		return (ptr + i);
	}
	return (0);
}
