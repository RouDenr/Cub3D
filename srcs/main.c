/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 21:19:09 by decordel          #+#    #+#             */
/*   Updated: 2022/06/30 22:09:24 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3D.h"
#include "../parser/incs/parser.h"

int	main(int argc, char *argv[])
{
	t_map	map;

	if (argc != 2)
		return (ft_ret_err("./cub3D map.cub", 1));
		
	ft_memset(&map, 0, sizeof map);
	map.color_ceil = -2;
	map.color_floor = -2;

	if (!parse_main(argc, argv, &map))
		return (1);

	game_init(&map);
	ft_lstclear_dyarr(&map.map_arr_l, free);
	return (0);
}
