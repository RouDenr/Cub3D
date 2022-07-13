/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 22:24:43 by decordel          #+#    #+#             */
/*   Updated: 2022/07/14 00:54:23 by decordel         ###   ########.fr       */
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

void	draw_minimap(t_mlx *mlx, int scale_factor, float x_scale, float y_scale)
{
	int		i;
	int		j;
	char	c;

	i = FT_X_MINIMAP;
	while (i < x_scale + FT_X_MINIMAP)
	{
		j = FT_Y_MINIMAP;
		while (j < y_scale + FT_Y_MINIMAP)
		{
			c = mlx->map->map_arr[(int)((j - FT_Y_MINIMAP) / scale_factor)]
			[(int)((i - FT_X_MINIMAP) / scale_factor)];
			if (c == '1')
				ft_pixel_put(&mlx->screen, i, j, 0x000000);
			else if (is_map_player_pos(&mlx->player,
					(int)((i - FT_X_MINIMAP) / scale_factor),
				(int)((j - FT_Y_MINIMAP) / scale_factor)))
				ft_pixel_put(&mlx->screen, i, j, 0xff0000);
			j++;
		}
		i++;
	}
}

void	init_minimap(t_mlx *mlx, t_map *map)
{
	int		scale_factor;
	float	x_scale;
	float	y_scale;

	scale_factor = 1;
	x_scale = 1.f * ft_strlen(*map->map_arr);
	while (x_scale * scale_factor <= FT_W_MINIMAP)
		scale_factor++;
	x_scale = 1.f * ft_strlen(*map->map_arr) * --scale_factor;
	y_scale = 1.f * ft_strmaslen(map->map_arr) * scale_factor;
	draw_minimap(mlx, scale_factor, x_scale, y_scale);
	printf("%f %f\n", x_scale, y_scale);
}
