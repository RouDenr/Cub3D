/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 04:19:27 by decordel          #+#    #+#             */
/*   Updated: 2022/07/24 19:25:03 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3D.h"

int	exit_hook(void)
{
	exit(0);
}

int	mouse_hook(int x, int y, t_mlx *mlx)
{
	(void) y;
	if (x > FT_WIN_W / 2)
		player_control(mlx->map, &mlx->player, -25);
	if (x < FT_WIN_W / 2)
		player_control(mlx->map, &mlx->player, 25);
	mlx_mouse_move(mlx->win, FT_WIN_W / 2, FT_WIN_H / 2);
	do_next_frame(mlx);
	return (0);
}

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
	{
		mlx_destroy_window(mlx->init, mlx->win);
		exit(0);
	}
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
		player_control(mlx->map, &mlx->player, keycode);
	if (keycode == 126 || keycode == 123 || keycode == 125 || keycode == 124)
		player_control(mlx->map, &mlx->player, keycode);
	if (keycode == 49)
		player_control(mlx->map, &mlx->player, keycode);
	do_next_frame(mlx);
	return (0);
}
