/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 21:38:35 by decordel          #+#    #+#             */
/*   Updated: 2021/12/09 14:10:17 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*buf1;
	const unsigned char	*buf2;
	int					i;

	buf1 = (unsigned char *) s1;
	buf2 = (unsigned char *) s2;
	i = 0;
	while (n-- > 0 && (buf1[i] || buf2[i]))
	{
		if (buf1[i] != buf2[i])
			return (buf1[i] - buf2[i]);
		i++;
	}
	return (0);
}

int	ft_strnendcmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*buf1;
	const unsigned char	*buf2;
	int					i;
	int					j;

	buf1 = (unsigned char *) s1;
	buf2 = (unsigned char *) s2;
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	while (n-- > 0 && i >= 0 && j >= 0)
	{
		if (buf1[i] != buf2[j])
			return (buf1[i] - buf2[j]);
		i--;
		j--;
	}
	return (0);
}
