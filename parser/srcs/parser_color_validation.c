/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_color_validation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:13:10 by vseel             #+#    #+#             */
/*   Updated: 2022/07/23 20:27:54 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/parser.h"
#include "../libft/libft.h"

int	is_valid_color_str(char *str)
{
	int	length;

	length = ft_strlen(str);
	if (str[length - 1] == '\n')
		str[length-- - 1] = 0;
	if (length > 3 || length == 0)
		return (0);
	while (--length != -1)
		if (str[length] < '0' || str[length] > '9')
			return (0);
	return (1);
}

int	parse_color(char *str)
{
	char	**colors_str;
	int		colors[3];

	colors_str = ft_split(str, ',');
	if (!colors_str)
		return (throw_error("parse_color", -1, 'm'));
	if (double_arr_size(colors_str) != 3
		|| !is_valid_color_str(colors_str[0])
		|| !is_valid_color_str(colors_str[1])
		|| !is_valid_color_str(colors_str[2]))
		return (double_arr_free(colors_str)
			&& throw_error("invalid config color line", -1, 'm'));
	colors[0] = ft_atoi(colors_str[0]);
	colors[1] = ft_atoi(colors_str[1]);
	colors[2] = ft_atoi(colors_str[2]);
	double_arr_free(colors_str);
	if (colors[0] > 255 || colors[0] < 0
		|| colors[1] > 255 || colors[1] < 0
		|| colors[2] > 255 || colors[2] < 0)
		return (throw_error("Colors allowed from 0 to 255 inc", -1, 'm'));
	return ((colors[0] << 16) | (colors[1] << 8) | colors[2]);
}

/**
 * @param color should be initialised as -2
*/
char	get_color(char **tmp, int *color)
{
	if (*color != -2)
	{
		double_arr_free(tmp);
		return (throw_error("invalid config line: dublicated instruction",
				0, 'm'));
	}
	*color = parse_color(tmp[1]);
	if (*color == -1)
		return (0);
	return (1);
}
