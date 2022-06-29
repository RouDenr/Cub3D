/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:52:04 by decordel          #+#    #+#             */
/*   Updated: 2022/05/18 17:25:21 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

void	checkfd(int fd, char **buf)
{
	static int	cfd;

	if (fd != cfd)
	{
		cfd = fd;
		if (*buf && **buf)
		{
			free(*buf);
			*buf = NULL;
		}
	}
}

int	findend(char *buf)
{
	while (*buf)
		if (*(buf++) == '\n')
			return (1);
	return (0);
}

int	readfd(int fd, size_t *size, char **str, char **buf)
{
	int	len;

	*buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!*buf)
		return (0);
	len = read(fd, *buf, BUFFER_SIZE);
	if (len < 0)
	{
		free(*buf);
		if (*str)
			free(*str);
		return (0);
	}
	if (!len)
	{
		free(*buf);
		*buf = NULL;
		return (0);
	}
	buf[0][len] = '\0';
	*size += len;
	*str = addbuf(*str, *buf, *size);
	if (findend(*buf))
		return (0);
	return (1);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*buf;
	size_t		size;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 1000000000)
		return (NULL);
	size = 0;
	str = NULL;
	checkfd(fd, &buf);
	if (buf != NULL && *buf)
	{
		buf = bufstart(buf, ft_strlen(buf));
		if (buf)
		{
			str = addbuf(str, buf, ft_strlen(buf));
			size = ft_strlen(str);
			if (findend(buf))
				return (str);
			free(buf);
		}
		buf = NULL;
	}
	while (readfd(fd, &size, &str, &buf))
		free(buf);
	return (str);
}
