/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:05:01 by vseel             #+#    #+#             */
/*   Updated: 2021/11/12 11:05:28 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	get_buff_to_next_nl(char *buff, char *nl_check)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE && i + 1 <= ft_strlen_s(nl_check, '\0'))
	{
		buff[i] = nl_check[i + 1];
		i++;
	}
	buff[i] = '\0';
}

void	*free_output_n_ret_null(void *str)
{
	free(str);
	return (NULL);
}

char	*nl_check_func(char *buff, char *output, char *nl_check)
{
	int	len_to_nl;

	if (nl_check != NULL && *nl_check == '\n')
	{
		len_to_nl = ft_strlen_s(output, '\n');
		get_buff_to_next_nl(buff, nl_check);
		output = ft_substr_free(output, 0, len_to_nl + 1, 'y');
	}
	return (output);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE];
	char		*output;
	char		*nl_check;
	int			read_check;

	if (fd < 0)
		return (NULL);
	read_check = 1;
	output = NULL;
	while (read_check != 0)
	{
		output = ft_strjoin_free(output, buff);
		if (!output)
			return (NULL);
		nl_check = ft_strchr(output, '\n');
		if (nl_check != NULL && *nl_check == '\n')
			return (nl_check_func(buff, output, nl_check));
		read_check = read(fd, buff, BUFFER_SIZE);
		if (read_check <= 0 && *buff == '\0' && *output == '\0')
			return (free_output_n_ret_null(output));
		buff[read_check] = '\0';
	}
	return (output);
}
