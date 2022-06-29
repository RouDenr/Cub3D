/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:52:07 by decordel          #+#    #+#             */
/*   Updated: 2022/05/18 17:24:45 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*addbuf(char *str, char *buf, size_t size)
{
	char	*clone;
	size_t	i;

	if (!*buf)
		return (str);
	i = 0;
	clone = (char *)malloc((size + 1) * sizeof(char));
	if (!clone)
	{
		free(str);
		return (NULL);
	}
	while (str && str[i])
	{
		clone[i] = str[i];
		i++;
	}
	if (str)
		free(str);
	while (*buf && *buf != '\n')
		clone[i++] = *(buf++);
	if (*buf == '\n')
		clone[i++] = '\n';
	clone[i] = '\0';
	return (clone);
}

char	*bufstart(char *buf, size_t len)
{
	char	*start;
	size_t	i;
	size_t	j;

	start = (char *)malloc((len + 1) * sizeof(char));
	if (!start)
	{
		free(buf);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	while (buf[++i])
		start[j++] = buf[i];
	free(buf);
	start[j] = '\0';
	if (j != 0)
		return (start);
	free(start);
	return (NULL);
}
