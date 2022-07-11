/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_opt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:13:10 by vseel             #+#    #+#             */
/*   Updated: 2022/07/11 22:20:34 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/parser.h"
#include "../libft/libft.h"

void	destroy_dyarr_struc(void *elem)
{
	if (((t_dyarr *) elem)->line)
		free(((t_dyarr *) elem)->line);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		return (throw_error("one argument excepted", 0, 'm'));

	ft_memset(&map, 0, sizeof map);
	map.color_ceil = -2;
	map.color_floor = -2;

	if (!parse_main(argv[1], &map))
		return (1);

	ft_lstclear_dyarr(&map.map_arr_l, destroy_dyarr_struc);
	free(map.wall_no);
	free(map.wall_so);
	free(map.wall_we);
	free(map.wall_ea);
	return (0);

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

// if (!ft_memcmp("NO", line, 2))
		// {
		// 	tmp = ft_substr(line, 3, ft_strlen(line + 3));
		// 	if (!tmp)
		// 		return (throw_error("substr_no", 11, 'm'));
		// 	map.wall_no = tmp;
		// }
		// else if (!ft_memcmp("SO", line, 2))
		// {
		// 	tmp = ft_substr(line, 3, ft_strlen(line + 3));
		// 	if (!tmp)
		// 		return (throw_error("substr_so", 12, 'm'));
		// 	map.wall_so = tmp;
		// }
		// else if (!ft_memcmp("WE", line, 2))
		// {
		// 	tmp = ft_substr(line, 3, ft_strlen(line + 3));
		// 	if (!tmp)
		// 		return (throw_error("substr_we", 13, 'm'));
		// 	map.wall_we = tmp;
		// }
		// else if (!ft_memcmp("EA", line, 2))
		// {
		// 	tmp = ft_substr(line, 3, ft_strlen(line + 3));
		// 	if (!tmp)
		// 		return (throw_error("substr_ea", 14, 'm'));
		// 	map.wall_ea = tmp;
		// }
		// else if (!ft_memcmp("F", line, 1))
		// {
		// 	tmp = ft_substr(line, 2, ft_strlen(line + 2));
		// 	if (!tmp)
		// 		return (throw_error("substr_f", 15, 'm'));
		// 	map.color_floor = parse_color(tmp);
		// 	if (map.color_floor == -1)
		// 		return (throw_error("Colors allowed from 0 to 255 inc", 16, 'm'));
		// 	free(tmp);
		// }
		// else if (!ft_memcmp("C", line, 1))
		// {
		// 	tmp = ft_substr(line, 2, ft_strlen(line + 2));
		// 	if (!tmp)
		// 		return (throw_error("substr_c", 17, 'm'));
		// 	map.color_ceil = parse_color(tmp);
		// 	if (map.color_ceil == -1)
		// 		return (throw_error("Colors allowed from 0 to 255 inc", 18, 'm'));
		// 	free(tmp);
		// }
		// else if (!ft_memcmp("\n", line, 1))
		// {
		// 	free(line);
		// 	line = get_next_line(map_fd);
		// 	continue ;
		// }
