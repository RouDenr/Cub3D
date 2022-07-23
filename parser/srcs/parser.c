/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:13:10 by vseel             #+#    #+#             */
/*   Updated: 2022/07/23 21:01:23 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/parser.h"
#include "../libft/libft.h"
/**
 * malloc +3 cuz of null-term and two empty lines
 */
t_map	*create_and_fill_arr(t_map *map)
{
	int		arr_size;
	t_dyarr	*arr;
	int		i;

	arr = map->map_arr_l;
	arr_size = ft_lstsize_dyarr(arr);
	if (arr_size != 0)
	{
		map->map_arr = malloc(sizeof (char *) * (arr_size + 3));
		if (!map->map_arr)
			return (0);
		i = 0;
		map->map_arr[i++] = ft_memset(ft_strdup(arr->line),
				' ', ft_strlen(arr->line) - 1);
		while (arr)
		{
			map->map_arr[i++] = arr->line;
			arr->line = 0;
			arr = arr->next;
		}
		map->map_arr[i] = ft_memset(ft_strdup(map->map_arr[i - 1]),
				' ', ft_strlen(map->map_arr[i - 1]) - 1);
		map->map_arr[++i] = NULL;
	}
	return (map);
}

t_dyarr	*create_n_push_list(t_dyarr **arr_head, char *line)
{
	t_dyarr	*line_l;

	line_l = ft_lstnew_dyarr(line);
	if (!line_l)
	{
		free(line);
		throw_error("lstnew_dyarr", 4, 'm');
		return (NULL);
	}
	if (!ft_lstadd_back_dyarr(arr_head, line_l))
	{
		free (line);
		throw_error("lstadd_back_dyarr", 5, 'm');
		return (NULL);
	}
	return (*arr_head);
}

char	parse_config(char **line, t_map *map, int map_fd)
{
	while (!is_valid_map_line(*line))
	{
		if (!parse_config_line(*line, map))
		{
			free(*line);
			return (0);
		}
		free(*line);
		*line = get_next_line(map_fd);
	}
	if (map->color_ceil == -2 || map->color_floor == -2 || !map->wall_no
		|| !map->wall_so || !map->wall_we || !map->wall_ea)
	{
		free(*line);
		return (throw_error("invalid config line", 0, 'm'));
	}
	return (1);
}

char	parse_map(char **line, t_map *map, int map_fd)
{
	while (*line)
	{
		if (!is_valid_map_line(*line))
		{
			free(*line);
			return (map_free(map) && throw_error("invalid map line", 0, 'm'));
		}
		if (!create_n_push_list(&map->map_arr_l, *line))
			return (0);
		*line = get_next_line(map_fd);
	}
	return (1);
}

int	parse_main(char *map_file, t_map *map)
{
	int		map_fd;
	char	*line;

	if (!is_cub_extention(map_file))
		return (0);
	map_fd = open(map_file, O_RDONLY | O_NOFOLLOW);
	if (map_fd < 0)
		return (throw_error("open failed", 0, 'p'));
	line = get_next_line(map_fd);
	if (!line)
		return (throw_error("gnl failed", 0, 'm'));
	if (!parse_config(&line, map, map_fd))
		return (map_free(map) && 0);
	if (!line)
		return (map_free(map) && throw_error("no map in file", 0, 'm'));
	if (!parse_map(&line, map, map_fd))
		return (map_free(map) && 0);
	create_and_fill_arr(map);
	if (!is_valid_map(map))
		return (map_free(map) && 0);
	visualize_map(*map);
	if (close(map_fd))
		return (throw_error("close failed", 0, 'p'));
	return (1);
}
