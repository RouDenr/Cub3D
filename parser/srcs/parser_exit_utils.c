/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_exit_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:13:10 by vseel             #+#    #+#             */
/*   Updated: 2022/07/23 20:26:01 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/parser.h"
#include "../libft/libft.h"

int	throw_error(char *msg, int exit_code, char mode)
{
	ft_putendl_fd("Error", 2);
	ft_putstr_fd("cub3d: ", 2);
	if (mode == 'm' && msg)
		ft_putendl_fd(msg, 2);
	if (mode == 'p' && msg)
		perror(msg);
	return (exit_code);
}

char	double_arr_free(char **strs)
{
	char	*to_free;
	char	**to_free_head;

	if (!strs)
		return (1);
	to_free_head = strs;
	while (*strs)
	{
		to_free = *strs;
		++strs;
		free(to_free);
	}
	free(to_free_head);
	return (1);
}

void	destroy_dyarr_struc(void *elem)
{
	if (!elem)
		return ;
	free(((t_dyarr *) elem)->line);
	((t_dyarr *) elem)->line = 0;
}

char	map_free(t_map *map)
{
	free(map->wall_no);
	free(map->wall_so);
	free(map->wall_we);
	free(map->wall_ea);
	map->wall_no = 0;
	map->wall_so = 0;
	map->wall_we = 0;
	map->wall_ea = 0;
	double_arr_free(map->map_arr);
	map->map_arr = 0;
	ft_lstclear_dyarr(&map->map_arr_l, destroy_dyarr_struc);
	map->map_arr_l = 0;
	return (1);
}
