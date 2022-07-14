/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 22:10:59 by decordel          #+#    #+#             */
/*   Updated: 2022/07/14 04:22:53 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3D.h"

t_img	*get_texture_by_dir(t_sources *sourcer, t_ray *ray, char cell)
{
	int	x;
	int	y;

	if (cell == 'D')
		return (&sourcer->door);
	x = ray->step_x;
	y = ray->step_y;
	if (ray->side)
	{
		if (y < 0)
			return (&sourcer->wall_no);
		return (&sourcer->wall_so);
	}
	if (x > 0)
		return (&sourcer->wall_ea);
	return (&sourcer->wall_we);
}

t_wall	get_texture_info(t_mlx *mlx, t_ray *ray, t_draw_info info)
{
	float	wall_x;
	t_wall	wall_info;

	wall_info.img = get_texture_by_dir(&mlx->sources, ray,
			mlx->map->map_arr[ray->map_y][ray->map_x]);
	if (ray->side == 0)
		wall_x = mlx->player.y + info.w_dist * ray->ray_y;
	else
		wall_x = mlx->player.x + info.w_dist * ray->ray_x;
	wall_x -= floorf(wall_x);
	wall_info.tex_x = (int)(wall_x * (float)wall_info.img->w);
		wall_info.tex_x = wall_info.img->w - wall_info.tex_x - 1;
	wall_info.step = 1.f * wall_info.img->h / info.height_dr;
	wall_info.tex_y[0] = (info.y[0] - mlx->screen.h / 2 + info.height_dr / 2)
		* wall_info.step;
	return (wall_info);
}
