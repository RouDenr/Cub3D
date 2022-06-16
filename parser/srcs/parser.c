/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:13:10 by vseel             #+#    #+#             */
/*   Updated: 2022/06/16 23:39:09 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/parser.h"
#include "../libft/libft.h"

void	visualize_dyarr(t_dyarr *arr)
{
	while (arr)
	{
		printf("%s", arr->line);
		arr = arr->next;
	}
}

void	visualize_map(t_map *map)
{
	if (!VISUALIZE_MAP)
		return ;
	printf("\n-------------------------------\n");
	// while (map)
	// {
	printf("map:\n");
	visualize_dyarr(map->map_arr_l);
	// }
	printf("\n-------------------------------\n");
	printf("\n");
}

int	throw_error(char *msg, int exit_code, char mode)
{
	ft_putendl_fd("Error", 2);
	if (mode == 'm' && msg)
		ft_putendl_fd(msg, 2);
	if (mode == 'p' && msg)
		perror(msg);
	return (exit_code);
}

t_dyarr	*create_n_push_list(t_dyarr **arr_head, char *line)
{
	t_dyarr	*line_l;
	
	line_l = ft_lstnew_dyarr(line);
	if (!line_l)
	{
		free(line);
		throw_error("lstnew_dyarr", 4, 'm');
		// return ((void *)throw_error("lstnew_dyarr", 4, 'm'));
		return (NULL);
	}
	if (!ft_lstadd_back_dyarr(arr_head, line_l))
	{
		throw_error("lstadd_back_dyarr", 5, 'm');
		return (NULL);
	}
	return(*arr_head);
}

int	main(int argc, char **argv)
{
	int		map_fd;
	char	*line;
	t_map	map;

	if (argc != 2)
		return (throw_error("Except one argument", 1, 'm'));
	
	map_fd = open(argv[1], O_RDONLY | O_NOFOLLOW);
	if (map_fd < 0)
		return (throw_error("open", 2, 'p'));

	line = get_next_line(map_fd);
	if (!line)
		return (throw_error("gnl", 3, 'm'));
	// if (!create_n_push_list(&arr_head, line)) // TODO potentially can add this lines to create_n_push_list func
	// 	return(4);
	
	// line_l = ft_lstnew_dyarr(line);
	// if (!line_l)
	// 	return (throw_error("lstnew_dyarr", 4, 'm'));
	// if (!ft_lstadd_back_dyarr(arr_head, line_l))
	// 	return (throw_error("lstadd_back_dyarr", 5, 'm'));

	while (line)
	{
		if (!create_n_push_list(&map.map_arr_l, line))
			return(4);

		// line_l = ft_lstnew_dyarr(line);
		// if (!line_l)
		// 	return (throw_error("lstnew_dyarr", 4, 'm'));
		// if (!ft_lstadd_back_dyarr(arr_head, line_l))
		// 	return (throw_error("lstadd_back_dyarr", 5, 'm'));
		
		line = get_next_line(map_fd);
	}

	visualize_map(&map);

	if (close(map_fd))
		return (throw_error("close", 5, 'p'));
	return (0);
}
