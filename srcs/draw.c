/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 20:07:56 by decordel          #+#    #+#             */
/*   Updated: 2022/07/05 08:29:58 by decordel         ###   ########.fr       */
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

unsigned int get_pixel_by_xy(t_img *img, int x, int y)
{
	char			*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *) dst);
}

void	draw_ver_line_wall(t_mlx *mlx, int x, int y[], t_img *img)
{
	int	i;
	unsigned int	color;

	i = y[0];
	while (i <= y[1])
	{
		color = get_pixel_by_xy(img, 0, i / img->h);
		ft_pixel_put(&mlx->screen, x, i, color);
		i++;
	}
}

t_img	*get_wall_by_dir(t_sources *sourcer, t_ray *ray)
{
	float	x;
	float	y;

	x = ray->ray_x;
	y = ray->ray_y;
	if (x > 0 && (y < .5f || y > -.5f))
		return (&sourcer->wall_ea);
	if (y > 0 && (x < .5f || x > -.5f))
		return (&sourcer->wall_no);
	if (y < 0 && (x < .5f || x > -.5f))
		return (&sourcer->wall_so);
	return (&sourcer->wall_we);
}
