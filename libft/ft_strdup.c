/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 01:30:28 by decordel          #+#    #+#             */
/*   Updated: 2022/05/09 18:40:05 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		len;

	if (!s1)
		return (NULL);
	len = 0;
	while (s1[len])
		len++;
	dup = NULL;
	dup = malloc((len + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	dup[len--] = '\0';
	while (len >= 0)
	{
		dup[len] = s1[len];
		len--;
	}
	return (dup);
}
