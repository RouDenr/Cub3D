/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 20:07:56 by decordel          #+#    #+#             */
/*   Updated: 2022/07/14 00:44:49 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3D.h"

void	ft_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= img->w || y >= img->h)
		return ;
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
	while (i < FT_WIN_H - 1)
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

unsigned int	get_pixel_by_xy(t_img *img, int x, int y)
{
	char			*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *) dst);
}

void	draw_ver_line_wall(t_mlx *mlx, int x, int y[], t_wall wall)
{
	int				i;
	int				wall_i;
	unsigned int	color;

	i = y[0];
	while (i <= y[1])
	{
		wall_i = (int) wall.tex_y[0];
		wall.tex_y[0] += wall.step;
		color = get_pixel_by_xy(wall.img, wall.tex_x, wall_i);
		ft_pixel_put(&mlx->screen, x, i, color);
		i++;
	}
}
