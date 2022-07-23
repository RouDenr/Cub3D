/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:13:10 by vseel             #+#    #+#             */
/*   Updated: 2022/07/23 20:54:57 by vseel            ###   ########.fr       */
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

char	get_texture_path(char **tmp, char **wall)
{
	if (double_arr_size(tmp) != 2 || tmp[1][0] == '\n')
		return (throw_error("invalid config texture line", 0, 'm'));
	if (*wall)
		return (throw_error("invalid config line: dublicated instruction",
				0, 'm'));
	*wall = ft_substr(tmp[1], 0, ft_strlen(tmp[1]) - 1);
	if (!*wall)
		return (throw_error("strdup failed", 0, 'm'));
	return (1);
}

char	get_config(char	**tmp, t_map *map)
{
	if (!ft_strncmp("NO", tmp[0], 2) && !get_texture_path(tmp, &map->wall_no))
		return (0);
	else if (!ft_strncmp("SO", tmp[0], 2)
		&& !get_texture_path(tmp, &map->wall_so))
		return (0);
	else if (!ft_strncmp("WE", tmp[0], 2)
		&& !get_texture_path(tmp, &map->wall_we))
		return (0);
	else if (!ft_strncmp("EA", tmp[0], 2)
		&& !get_texture_path(tmp, &map->wall_ea))
		return (0);
	else if (!ft_strncmp("F", tmp[0], 1) && !get_color(tmp, &map->color_floor))
		return (0);
	else if (!ft_strncmp("C", tmp[0], 1) && !get_color(tmp, &map->color_ceil))
		return (0);
	return (1);
}

char	parse_config_line(char *line, t_map *map)
{
	char	**tmp;
	char	ret;

	if (!line)
		return (0);
	if (*line == '\n')
		return (1);
	ret = 1;
	tmp = ft_split(line, ' ');
	if (!tmp)
		return (throw_error("split failed", 0, 'm'));
	if (double_arr_size(tmp) != 2)
		ret = throw_error("invalid config line", 0, 'm');
	if (!get_config(tmp, map))
		ret = 0;
	double_arr_free(tmp);
	return (ret);
}
