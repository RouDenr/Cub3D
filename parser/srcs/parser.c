/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:13:10 by vseel             #+#    #+#             */
/*   Updated: 2022/07/19 23:35:23 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/parser.h"
#include "../libft/libft.h"
/**
 * malloc +3 cuz for null-tenm and for two empty lines
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

/**
 * @param m is for map
*/
char	is_vaild_near_cells(char **m, int i, int j)
{
	return (((m[i][j - 1] != '1' && m[i][j - 1] != '0' && m[i][j - 1] != 'N'
			&& m[i][j - 1] != 'S' && m[i][j - 1] != 'E' && m[i][j - 1] != 'W')
			|| (m[i][j + 1] != '1' && m[i][j + 1] != '0' && m[i][j + 1] != 'N'
			&& m[i][j + 1] != 'S' && m[i][j + 1] != 'E' && m[i][j + 1] != 'W')
			|| (m[i - 1][j] != '1' && m[i - 1][j] != '0' && m[i - 1][j] != 'N'
			&& m[i - 1][j] != 'S' && m[i - 1][j] != 'E' && m[i - 1][j] != 'W')
			|| (m[i + 1][j] != '1' && m[i + 1][j] != '0' && m[i + 1][j] != 'N'
		&& m[i + 1][j] != 'S' && m[i + 1][j] != 'E' && m[i + 1][j] != 'W')));
}

/**
 * @param m is alias for `map->map_arr`
*/
char	is_valid_map(t_map *map)
{
	int		i;
	int		j;
	char	is_player_here;
	char	**m;

	i = 0;
	is_player_here = 0;
	m = map->map_arr;
	while (m[++i])
	{
		j = -1;
		while (m[i][++j])
		{
			if (m[i][j] != '1' && m[i][j] != ' ' && m[i][j] != '\n'
			&& is_vaild_near_cells(m, i, j))
				return (throw_error("map: map can't be unclosed", 0, 'm'));
			if ((m[i][j] == 'N' || m[i][j] == 'S'
			|| m[i][j] == 'E' || m[i][j] == 'W') && is_player_here++)
				return (throw_error("map: there is can be only one player char",
						0, 'm'));
		}
	}
	if (!is_player_here)
		return (throw_error("map: no player char on map", 0, 'm'));
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

	while (!is_valid_map_line(line))
	{
		if (!parse_config_line(line, map))
		{
			free (line);
			return (0);
		}
		free (line);
		line = get_next_line(map_fd);
	}
	if (map->color_ceil == -2 || map->color_floor == -2 || !map->wall_no
		 || !map->wall_so  || !map->wall_we  || !map->wall_ea)
		return (throw_error("invalid config line", 0, 'm'));
	while (line)
	{
		if (!is_valid_map_line(line))
		{
			free(line);
			return (throw_error("invalid map line", 0, 'm'));
		}
		if (!create_n_push_list(&map->map_arr_l, line))
			return (0);
		// free (line);
		line = get_next_line(map_fd);
	}
	create_and_fill_arr(map);
	is_valid_map(map);
	visualize_map(*map);

	if (close(map_fd))
		return (throw_error("close failed", 0, 'p'));
	return (1);
}

/*
	Possible configs:
		NO
		SO
		WE
		EA

		F
		C

	Possible map chars:
		0 - empty space
		1 - wall
		NSEW - player start position and orientation

			N
		W		E
			S

		1) Your program must take as a first argument a 
		scene description file with the .cub extension.
		2) The map must be closed/surrounded by walls, 
		if not the program must return an error.
		3) Except for the map content, each type of 
		element can be separated by one or more empty line(s).
		4) Except for the map content which always has to be the last, 
		each type of element can be set in any order in the file.
		5) The map must be parsed as it looks in the file. 
		Spaces are a valid part of the map and are up to you to handle. 
		You must be able to parse any kind of map, 
		as long as it respects the rules of the map.

		6) Each element (except the map) firsts information is the type 
		identifier (composed by one or two character(s)), 
		followed by all specific informations for each object in a strict order
		7) If any misconfiguration of any kind is encountered in the file, 
		the program must exit properly and return "Error\n" 
		followed by an explicit error message of your choice.
*/
