/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:13:10 by vseel             #+#    #+#             */
/*   Updated: 2022/06/19 21:20:31 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/parser.h"
#include "../libft/libft.h"

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
		throw_error("lstadd_back_dyarr", 5, 'm');
		return (NULL);
	}
	return (*arr_head);
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

char	is_cfg_line(char *line)
{
	char	**tmp;

	
	tmp = ft_split(line, ' ');
	if (!tmp)
		return (throw_error("split", 10, 'm'));
	printf("valid map: %d | size: %d -- %s",is_valid_map_line(line), double_arr_size(tmp), line);
		// return (throw_error("config line error", 11, 'm'));
	return (0);
}

int	main(int argc, char **argv)
{
	int		map_fd;
	char	*line;
	t_map	map;
	// char	*tmp;

	if (argc != 2)
		return (throw_error("Except one argument", 1, 'm'));

	map_fd = open(argv[1], O_RDONLY | O_NOFOLLOW);
	if (map_fd < 0)
		return (throw_error("open", 2, 'p'));

	line = get_next_line(map_fd);
	if (!line)
		return (throw_error("gnl", 3, 'm'));

	while (line)
	{
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
		is_cfg_line(line);

		if (!create_n_push_list(&map.map_arr_l, line))
			return (4);
		line = get_next_line(map_fd);
	}

	// visualize_map(&map);

	if (close(map_fd))
		return (throw_error("close", 5, 'p'));
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

*/