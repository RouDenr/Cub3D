/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:40:35 by decordel          #+#    #+#             */
/*   Updated: 2021/12/08 00:09:03 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	calc_size(int n)
{
	size_t	i;

	i = 0;
	while (n / 10 != 0)
	{
		n /= 10;
		i++;
	}
	return (++i);
}

char	*min_int(void)
{
	char	*min;
	int		i;

	min = malloc(12);
	i = 0;
	while (i < 12)
	{
		min[i] = "-2147483648"[i];
		i++;
	}
	min[i] = '\0';
	return (min);
}

char	*ft_itoa(int n)
{
	size_t	size;
	char	*str;

	size = 0;
	if (n < 0)
	{
		if (n == INT32_MIN)
			return (min_int());
		size++;
		n *= -1;
	}
	size += calc_size(n);
	str = malloc(size + 1);
	if (str == NULL)
		return (NULL);
	str[size--] = '\0';
	while (n / 10 != 0)
	{
		str[size--] = (char)(n % 10) + '0';
		n /= 10;
	}
	str[size--] = (char)(n % 10) + '0';
	if (size == 0)
		str[0] = '-';
	return (str);
}
