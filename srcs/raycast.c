/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 20:07:56 by decordel          #+#    #+#             */
/*   Updated: 2022/07/03 20:56:10 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3D.h"

void	set_delta_dist_ray(t_ray *ray)
{
	if (ray->ray_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_x);
	if (ray->ray_y == 0)
		ray->delta_dist_y = 1e30;
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
			mlx->map->map_arr[ray->map_y][ray->map_x] = '*';
			hit = 1;
		}
	}
}

void	draw_ray(t_ray *ray, t_mlx *mlx)
{
	int			height_dr;
	int			y[2];
	float		w_dist;

	if (ray->side == 0)
		w_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		w_dist = (ray->side_dist_y - ray->delta_dist_y);
	height_dr = (int)(mlx->screen.h / w_dist);
	y[0] = -height_dr / 2 + mlx->screen.h / 2;
	if (y[0] < 0)
		y[0] = 0;
	y[1] = height_dr / 2 + mlx->screen.h / 2;
	if (y[1] >= mlx->screen.h)
		y[1] = mlx->screen.h - 1;
	draw_ver_line(mlx, ray->x, y, 0x00FF0000);
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
