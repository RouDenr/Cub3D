/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 22:24:43 by decordel          #+#    #+#             */
/*   Updated: 2022/07/12 17:40:57 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3D.h"

#ifndef FT_W_MINIMAP
# define FT_W_MINIMAP 300
#endif

#ifndef FT_H_MINIMAP
# define FT_H_MINIMAP 300
#endif

#ifndef FT_X_MINIMAP
# define FT_X_MINIMAP 20
#endif

#ifndef FT_Y_MINIMAP
# define FT_Y_MINIMAP 20
#endif

int	is_map_player_pos(t_player *player, int x, int y)
{
	if ((int)(player->x) != x)
		return (0);
	if ((int)(player->y) != y)
		return (0);
	return (1);
}

void	draw_minimap(t_mlx *mlx, t_map *map)
{
	int		i;
	int		j;
	int		temp = 1;
	float	x_map;
	float	y_map;
	char	c;

	x_map = 1.f * ft_strlen(*map->map_arr);
	while (x_map * temp <= FT_W_MINIMAP)
		temp++;
	x_map = 1.f * ft_strlen(*map->map_arr) * --temp;
	y_map = 1.f * ft_strmaslen(map->map_arr) * temp;
	printf("%f %f\n", x_map, y_map);
	i = FT_X_MINIMAP;
	while (i < x_map + FT_X_MINIMAP)
	{
		j = FT_Y_MINIMAP;
		while (j < y_map + FT_Y_MINIMAP)
		{
			c = map->map_arr[(int)((j - FT_Y_MINIMAP) / temp)]
			[(int)((i - FT_X_MINIMAP) / temp)];
			if (c == '1')
				ft_pixel_put(&mlx->screen, i, j, 0x000000);
			else if (is_map_player_pos(&mlx->player,
					(int)((i - FT_X_MINIMAP) / temp),
				(int)((j - FT_Y_MINIMAP) / temp)))
				ft_pixel_put(&mlx->screen, i, j, 0xff0000);
			j++;
		}
		i++;
	}
}
