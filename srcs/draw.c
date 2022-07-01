/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 20:07:56 by decordel          #+#    #+#             */
/*   Updated: 2022/07/01 03:20:59 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3D.h"

void	ft_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	draw_background(t_mlx *mlx)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	color = mlx->map->color_ceil;
	while (i < FT_WIN_H)
	{
		j = 0;
		if (i == FT_WIN_H / 2)
			color = mlx->map->color_floor;
		while (j < FT_WIN_W)
		{
			ft_pixel_put(&mlx->screen, j, i, color);
			j++;
		}
		i++;
	}
}

void	draw_ver_line(t_mlx *mlx, int x, int y[], int color)
{
	int	i;

	i = y[0];
	while (i <= y[1])
	{
		ft_pixel_put(&mlx->screen, x, i, color);
		i++;
	}
}
