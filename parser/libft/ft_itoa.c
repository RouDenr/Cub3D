/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:17:58 by vseel             #+#    #+#             */
/*   Updated: 2021/10/16 15:07:15 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_check(int n)
{
	char	*str;

	if (n == -2147483648)
		str = ft_strdup("-2147483648");
	if (n == 0)
		str = ft_strdup("0");
	return (str);
}

static int	ft_numlen(int n)
{
	int		buf;
	int		len;

	buf = n;
	len = 0;
	while (buf != 0)
	{
		buf /= 10;
		len++;
	}
	if (n < 0)
		len++;
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		buf;

	len = ft_numlen(n);
	buf = n;
	if (n == 0 || n == -2147483648)
		return (ft_check(n));
	if (n < 0)
		buf = -n;
	str = malloc(len + 1);
	if (!str)
		return (str);
	str[len--] = '\0';
	while (len >= 0)
	{
		if (len == 0 && n < 0)
		{
			str[len] = '-';
			break ;
		}
		str[len--] = buf % 10 + 48;
		buf = buf / 10;
	}
	return (str);
}
