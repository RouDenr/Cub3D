/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_opt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:13:10 by vseel             #+#    #+#             */
/*   Updated: 2022/07/23 20:22:02 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/parser.h"
#include "../libft/libft.h"

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
	map_free(&map);
	return (0);
}
