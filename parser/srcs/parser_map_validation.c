/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map_validation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:13:10 by vseel             #+#    #+#             */
/*   Updated: 2022/06/22 23:19:32 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/parser.h"
#include "../libft/libft.h"

int	double_arr_size(char **strs)
{
	int	size;

	size = 0;
	if (!strs)
		return (-1);
	while (*strs)
	{
		++strs;
		++size;
	}
	return (size);
}

char	is_valid_map_line(char *line)
{
	char	allowed_chars[] = "01NSEW \n";

	if (!line)
		return (-1);
	if (*line == '\n')
		return (0);
	while (*line)
	{
		if(!ft_strchr(allowed_chars, *line))
			return (0);
		++line;
	}
	return (1);
}

char	get_texture_path(char **tmp, char **wall)
{
	if (*wall)
	{
		free(tmp[0]);
		free(tmp[1]);
		free(tmp);
		return (throw_error("invalid config line: dublicated instruction", 0, 'm'));
	}
	// *wall = ft_strdup(tmp[1]);
	*wall = ft_substr(tmp[1], 0, ft_strlen(tmp[1]) - 1);
	if (!*wall)
		return (throw_error("strdup failed", 0, 'm'));
	return (1);
}

int	parse_color(char *str)
{
	char	**colors_str;
	int		colors[3];

	colors_str = ft_split(str, ',');
	if (!colors_str)
		return(throw_error("parse_color", -1, 'm'));
	colors[0] = ft_atoi(colors_str[0]);
	colors[1] = ft_atoi(colors_str[1]);
	colors[2] = ft_atoi(colors_str[2]);
	if (colors[0] > 255 || colors[0] < 0
		|| colors[1] > 255 || colors[1] < 0
		|| colors[2] > 255 || colors[2] < 0)
		return (-1);

	// TODO get this onto separate func
	if (VISUALIZE_MAP)
	{
		showbits(colors[0]);
		showbits(colors[1]);
		showbits(colors[2]);
		showbits((colors[0] << 16) | (colors[1] << 8) | colors[2]);
	}
	return ((colors[0] << 16) | (colors[1] << 8) | colors[2]);
}

/**
 * @param color should be initialised as -2
*/
char	get_color(char **tmp, int *color)
{
	if (*color != -2)
	{
		free(tmp[0]);
		free(tmp[1]);
		free(tmp);
		return (throw_error("invalid config line: dublicated instruction", 0, 'm'));
	}
	*color = parse_color(tmp[1]);
	if (*color == -1)
		return (throw_error("Colors allowed from 0 to 255 inc", 16, 'm'));
	return (1);
}

char	parse_config_line(char *line, t_map *map)
{
	char	**tmp;

	if (*line == '\n')
		return (1);
	tmp = ft_split(line, ' ');
	if (!tmp)
		return (throw_error("split failed", 0, 'm'));
	if (double_arr_size(tmp) != 2)
		return (throw_error("invalid config line", 0, 'm'));
	if (!ft_strncmp("NO", tmp[0], 2) && !get_texture_path(tmp, &map->wall_no))
		return (0);
	else if (!ft_strncmp("SO", tmp[0], 2) && !get_texture_path(tmp, &map->wall_so))
		return (0);
	else if (!ft_strncmp("WE", tmp[0], 2) && !get_texture_path(tmp, &map->wall_we))
		return (0);
	else if (!ft_strncmp("EA", tmp[0], 2) && !get_texture_path(tmp, &map->wall_ea))
		return (0);
	else if (!ft_strncmp("F", tmp[0], 1) && !get_color(tmp, &map->color_floor))
		return (0);
	else if (!ft_strncmp("C", tmp[0], 1) && !get_color(tmp, &map->color_ceil))
		return (0);
	free(tmp[0]);
	free(tmp[1]);
	free(tmp);
	return (1);
}
