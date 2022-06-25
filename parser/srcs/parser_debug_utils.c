/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_debug_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:13:10 by vseel             #+#    #+#             */
/*   Updated: 2022/06/25 20:54:42 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/parser.h"
#include "../libft/libft.h"

void	showbits(unsigned int x)
{
	int i;

	i = (sizeof(int) * 8) - 1;
	while (i >= 0)
	{
		if (x & (1u << i))
			ft_putchar_fd('1', 0);
		else
			ft_putchar_fd('0', 0);
		--i;
	}
	ft_putchar_fd('\n', 0);
}

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
	printf("configs:\n");
	if (map->wall_no)
		printf("\tNO: %s\n", map->wall_no);
	if (map->wall_so)
		printf("\tSO: %s\n", map->wall_so);
	if (map->wall_we)
		printf("\tWE: %s\n", map->wall_we);
	if (map->wall_ea)
		printf("\tEA: %s\n", map->wall_ea);
	printf("\tfloor: %d\n", map->color_floor);
	printf("\tceil:  %d\n", map->color_ceil);
	printf("map dyarr:\n");
	visualize_dyarr(map->map_arr_l);
	printf("\n\nmap double array:\n");
	while (map->map_arr && *map->map_arr)
		printf("%s", *map->map_arr++);
	printf("\n-------------------------------\n");
	printf("\n");
}
