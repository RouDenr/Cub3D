/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map_validation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:13:10 by vseel             #+#    #+#             */
/*   Updated: 2022/07/14 03:02:30 by decordel         ###   ########.fr       */
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

void	double_arr_free(char **strs)
{
	char	*to_free;
	char	**to_free_head;

	if (!strs)
		return ;
	to_free_head = strs;
	while (*strs)
	{
		to_free = *strs;
		++strs;
		free(to_free);
	}
	free(to_free_head);
}

char	is_valid_map_line(char *line)
{
	const char	allowed_chars[] = "01NSEWD \n";

	if (!line || *line == '\n')
		return (0);
	while (*line)
	{
		if (!ft_strchr(allowed_chars, *line))
			return (0);
		++line;
	}
	return (1);
}

char	get_texture_path(char **tmp, char **wall)
{
	if (*wall)
	{
		double_arr_free(tmp);
		return (throw_error("invalid config line: dublicated instruction",
				0, 'm'));
	}
	*wall = ft_substr(tmp[1], 0, ft_strlen(tmp[1]) - 1);
	if (!*wall)
		return (throw_error("strdup failed", 0, 'm'));
	return (1);
}

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
	{
		double_arr_free(colors_str);
		return (throw_error("invalid config line", -1, 'm'));
	}
	colors[0] = ft_atoi(colors_str[0]);
	colors[1] = ft_atoi(colors_str[1]);
	colors[2] = ft_atoi(colors_str[2]);
	double_arr_free(colors_str);
	if (colors[0] > 255 || colors[0] < 0
		|| colors[1] > 255 || colors[1] < 0
		|| colors[2] > 255 || colors[2] < 0)
		return (throw_error("Colors allowed from 0 to 255 inc", -1, 'm'));

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
		double_arr_free(tmp);
		return (throw_error("invalid config line: dublicated instruction",
				0, 'm'));
	}
	*color = parse_color(tmp[1]);
	if (*color == -1)
		return (0);
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
	{
		double_arr_free(tmp);
		return (throw_error("invalid config line", 0, 'm'));
	}
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
