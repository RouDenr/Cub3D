/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 20:07:56 by decordel          #+#    #+#             */
/*   Updated: 2022/07/14 03:40:41 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3D.h"

void	set_delta_dist_ray(t_ray *ray)
{
	if (ray->ray_x == 0)
		ray->delta_dist_x = 1.000015f;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_x);
	if (ray->ray_y == 0)
		ray->delta_dist_y = 1.000015f;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_y);
}

void	set_side_dist_ray(t_ray *ray, t_player player)
{
	if (ray->ray_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player.x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0f - player.x) * ray->delta_dist_x;
	}
	if (ray->ray_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player.y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0f - player.y) * ray->delta_dist_y;
	}
}

void	hit_ray(t_ray *ray, t_mlx *mlx)
{
	int			hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (mlx->map->map_arr[ray->map_y][ray->map_x] != '0')
		{
			hit = 1;
		}
	}
}

void	draw_ray(t_ray *ray, t_mlx *mlx)
{
	t_draw_info	info;

	if (ray->side == 0)
		info.w_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		info.w_dist = (ray->side_dist_y - ray->delta_dist_y);
	info.height_dr = (int)(mlx->screen.h / info.w_dist);
	info.y[0] = -info.height_dr / 2 + mlx->screen.h / 2;
	if (info.y[0] < 0)
		info.y[0] = 0;
	info.y[1] = info.height_dr / 2 + mlx->screen.h / 2;
	if (info.y[1] >= mlx->screen.h)
		info.y[1] = mlx->screen.h - 1;
	draw_ver_line_wall(mlx, ray->x, info.y, get_texture_info(mlx, ray, info));
}

void	raycasting(t_mlx *mlx)
{
	t_player	player;
	t_ray		ray;
	float		cam_x;

	ray.x = 0;
	player = mlx->player;
	while (ray.x < mlx->screen.w)
	{
		cam_x = 2 * ray.x / (float)mlx->screen.w - 1;
		ray.ray_x = mlx->player.dir.x + mlx->player.dir.plane_x * cam_x;
		ray.map_x = (int) mlx->player.x;
		ray.ray_y = mlx->player.dir.y + mlx->player.dir.plane_y * cam_x;
		ray.map_y = (int) mlx->player.y;
		set_delta_dist_ray(&ray);
		set_side_dist_ray(&ray, player);
		hit_ray(&ray, mlx);
		draw_ray(&ray, mlx);
		ray.x++;
	}
}
