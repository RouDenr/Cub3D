/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_file_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:13:10 by vseel             #+#    #+#             */
/*   Updated: 2022/07/23 18:02:04 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/parser.h"
#include "../libft/libft.h"

int	is_cub_extention(char *filename)
{
	int	size;

	size = ft_strlen(filename);
	if (size < 5)
		return (throw_error("map filename too short", 0, 'm'));
	if (filename[size - 4] == '.'
		&& filename[size - 3] == 'c'
		&& filename[size - 2] == 'u'
		&& filename[size - 1] == 'b')
		return (1);
	return (throw_error("wrong extention. \".cub\" expected", 0, 'm'));
}
