/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 22:24:43 by decordel          #+#    #+#             */
/*   Updated: 2022/07/11 23:08:13 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3D.h"

#ifndef FT_W_MINIMAP
# define FT_W_MINIMAP 200
#endif

#ifndef FT_H_MINIMAP
# define FT_H_MINIMAP 200
#endif

#ifndef FT_X_MINIMAP
# define FT_X_MINIMAP 20
#endif

#ifndef FT_Y_MINIMAP
# define FT_Y_MINIMAP 20
#endif

void	draw_minimap(t_mlx *mlx, t_map *map)
{
	int		i;
	int		j;
	float	x_map;
	float	y_map;
	char	c;

	x_map = 1.f * FT_W_MINIMAP / ft_strlen(*map->map_arr);
	y_map = 1.f * FT_H_MINIMAP / ft_strmaslen(map->map_arr);
	printf("%f %f\n", x_map, y_map);
	i = FT_X_MINIMAP;
	while (i < FT_W_MINIMAP + FT_X_MINIMAP)
	{
		j = FT_Y_MINIMAP;
		while (j < FT_H_MINIMAP + FT_Y_MINIMAP)
		{
			c = map->map_arr[(int)((j - FT_Y_MINIMAP) / y_map)][(int)((i - FT_X_MINIMAP) / x_map)];
			if (c == '1')
				ft_pixel_put(&mlx->screen, i, j, 0x000000);
			// else if ((j - FT_Y_MINIMAP) / y_map )
			j++;
		}
		i++;
	}
}
