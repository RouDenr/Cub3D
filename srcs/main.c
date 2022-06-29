/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 21:19:09 by decordel          #+#    #+#             */
/*   Updated: 2022/06/29 22:34:12 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3D.h"

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
		throw_error("lstadd_back_dyarr", 5, 'm');
		return (NULL);
	}
	return (*arr_head);
}

int	pars_map(int argc, char **argv, t_map *new_map)
{
	int		map_fd;
	char	*line;
	t_map	map;
	// char	*tmp;

	if (argc != 2)
		return (throw_error("one argument excepted", 1, 'm'));

	if (!is_cub_extention(argv[1]))
		return (1);

	map_fd = open(argv[1], O_RDONLY | O_NOFOLLOW);
	if (map_fd < 0)
		return (throw_error("open failed", 1, 'p'));

	line = get_next_line(map_fd);
	if (!line)
		return (throw_error("gnl failed", 1, 'm'));

	ft_memset(&map, 0, sizeof map);
	map.color_ceil = -2;
	map.color_floor = -2;
	while (!is_valid_map_line(line))
	{
		if (!parse_config_line(line, &map))
		{
			free (line);
			return (1);
		}
		line = get_next_line(map_fd);
	}
	while (line)
	{
		if (!is_valid_map_line(line))
		{
			free(line);
			return (throw_error("invalid map line", 1, 'p'));
		}
		if (!create_n_push_list(&map.map_arr_l, line))
			return (4);
		line = get_next_line(map_fd);
	}
	create_and_fill_arr(&map);
	visualize_map(&map);

	if (close(map_fd))
		return (throw_error("close failed", 1, 'p'));
	new_map = &map;
	return (0);
}

int main(int argc, char *argv[])
{
	t_map *map;

	// void *init = mlx_init();
	map = NULL;
	if (argc != 2)
		return (ft_ret_err("./cub3D map.cub", 1));
	if (pars_map(argc, argv, map))
		return (1);
	return 0;
}
