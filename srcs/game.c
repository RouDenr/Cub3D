/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 01:01:45 by decordel          #+#    #+#             */
/*   Updated: 2022/07/11 22:36:59 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3D.h"

int	do_next_frame(t_mlx *mlx)
{
	draw_background(mlx);
	raycasting(mlx);
	draw_minimap(mlx, mlx->map);
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->screen.img, 0, 0);
	return (mlx->player.dir.x);
}
