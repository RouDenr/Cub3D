/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 01:01:45 by decordel          #+#    #+#             */
/*   Updated: 2022/06/30 03:08:27 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3D.h"

int	do_next_frame(t_mlx *mlx)
{
	// int i = 0;
	// int j;

	// while (i < 500)
	// {
	// 	j = 0;
	// 	while (j < 1920)
	// 	{
	// 		ft_pixel_put(&mlx->screen, j, i, 0x00FF0000);
	// 		j++;
	// 	}
	// 	i++;
	// }

	// mlx_put_image_to_window(mlx->init, mlx->win, mlx->screen.img, 0, 0);

	// mlx_destroy_image(mlx->init, mlx->screen.img);

	raycasting(mlx);
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->screen.img, 0, 0);
	return (mlx->player.dir_x);
}
