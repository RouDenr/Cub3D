/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:13:10 by vseel             #+#    #+#             */
/*   Updated: 2022/06/30 23:37:11 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/parser.h"
#include "../libft/libft.h"

t_map	*create_and_fill_arr(t_map *map)
{
	int		arr_size;
	t_dyarr	*arr;
	int		i;

	arr = map->map_arr_l;
	arr_size = ft_lstsize_dyarr(arr);
	if (arr_size != 0)
	{
		map->map_arr = malloc(sizeof (char *) * arr_size + 1);
		if (!map->map_arr)
			return (0);
		i = 0;
		while (arr)
		{
			map->map_arr[i++] = arr->line;
			arr = arr->next;
		}
		map->map_arr[i] = NULL;
	}
	return (map);
}

t_map	*dyarr_to_arr(t_map *head_token)
{
	if (!create_and_fill_arr(head_token))
		return (0);
	return (head_token);
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

int	parse_main(int argc, char **argv, t_map *map)
{
	int		map_fd;
	char	*line;

	// if (argc != 2)
	// 	return (throw_error("one argument excepted", 0, 'm'));
	(void) argc;

	if (!is_cub_extention(argv[1]))
		return (0);

	map_fd = open(argv[1], O_RDONLY | O_NOFOLLOW);
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
	while (line)
	{
		if (!is_valid_map_line(line))
		{
			free(line);
			return (throw_error("invalid map line", 0, 'p'));
		}
		if (!create_n_push_list(&map->map_arr_l, line))
			return (0);
		// free (line);
		line = get_next_line(map_fd);
	}
	create_and_fill_arr(map);
	visualize_map(map);

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

		1) Your program must take as a first argument a scene description file with the .cub extension.
		2) The map must be closed/surrounded by walls, if not the program must return an error.
		3) Except for the map content, each type of element can be separated by one or more empty line(s).
		4) Except for the map content which always has to be the last, each type of element can be set in any order in the file.
		5) The map must be parsed as it looks in the file. Spaces are a valid part of the map and are up to you to handle. You must be able to parse any kind of map, as long as it respects the rules of the map.

		6) Each element (except the map) firsts information is the type identifier (composed by one or two character(s)), followed by all specific informations for each object in a strict order
		7) If any misconfiguration of any kind is encountered in the file, the program must exit properly and return "Error\n" followed by an explicit error message of your choice.
*/
