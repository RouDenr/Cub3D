/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 00:25:18 by decordel          #+#    #+#             */
/*   Updated: 2022/07/01 04:00:22 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3D.h"

int	exit_hook(void)
{
	exit(0);
}

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
	{
		mlx_destroy_window(mlx->init, mlx->win);
		exit(0);
	}
	if (keycode == 49)
		visualize_map(*mlx->map);
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
		player_control(mlx->map, &mlx->player, keycode);
	if (keycode == 126 || keycode == 123 || keycode == 125 || keycode == 124)
		player_control(mlx->map, &mlx->player, keycode);
	return (0);
}

t_img	init_wall(t_mlx mlx, char *source)
{
	int		x;
	int		y;
	t_img	img;

	img.img = mlx_xpm_file_to_image(mlx.init, source, &x, &y);
	img.w = x;
	img.h = y;
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	return (img);
}

t_mlx	game_init(t_map *map)
{
	t_mlx	mlx;

	mlx.map = map;
	mlx.init = mlx_init();
	mlx.win = mlx_new_window(mlx.init, FT_WIN_W, FT_WIN_H, "cub3D");
	mlx.sources.wall_ea = init_wall(mlx, map->wall_ea);
	mlx.sources.wall_no = init_wall(mlx, map->wall_no);
	mlx.sources.wall_so = init_wall(mlx, map->wall_so);
	mlx.sources.wall_we = init_wall(mlx, map->wall_we);
	mlx.screen.img = mlx_new_image(mlx.init, FT_WIN_W, FT_WIN_H);
	mlx.screen.addr = mlx_get_data_addr(mlx.screen.img,
			&mlx.screen.bits_per_pixel,
			&mlx.screen.line_length,
			&mlx.screen.endian);
	mlx.screen.h = FT_WIN_H;
	mlx.screen.w = FT_WIN_W;
	mlx.player = player_init(map->map_arr);
	mlx_hook(mlx.win, 17, 0L, exit_hook, &mlx);
	mlx_hook(mlx.win, 2, 1L << 0, key_hook, &mlx);
	mlx_loop_hook(mlx.init, do_next_frame, &mlx);
	mlx_loop(mlx.init);
	return (mlx);
}
