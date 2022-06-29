/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 21:19:09 by decordel          #+#    #+#             */
/*   Updated: 2022/06/28 20:19:27 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3D.h"

int main(int argc, char *argv[])
{
	t_map *map;

	// void *init = mlx_init();
	if (argc != 2)
		return (ft_ret_err("./cub3D map.cub", 1));
	map = parse_main(argv[1]);
	printf("HELLO CUB");
	return 0;
}
