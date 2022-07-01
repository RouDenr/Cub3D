/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 00:52:05 by decordel          #+#    #+#             */
/*   Updated: 2022/07/01 04:07:48 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3D.h"
#ifndef FT_ROTATE_SPEED
# define FT_ROTATE_SPEED .05f
#endif
#ifndef FT_STEP_SPEED
# define FT_STEP_SPEED 1.f
#endif

void	player_move(t_map *map, t_player *player, int step)
{
	int		x;
	int		y;
	char	cell;

	x = (int)(player->x + player->dir_x * FT_STEP_SPEED * step);
	y = (int)(player->y + player->dir_y * FT_STEP_SPEED * step);
	cell = map->map_arr[(int) player->y][x];
	printf("%d %d %c\n", x, y, cell);
	if (map->map_arr[(int) player->y][x] == 0)
		player->x += player->dir_x * FT_STEP_SPEED * step;
	x = (int)(player->x + player->dir_x * FT_STEP_SPEED * step);
	cell = map->map_arr[y][(int) player->x];
	printf("%d %d %c\n\n", x, y, cell);
	if (map->map_arr[y][(int) player->x] == 0)
		player->y += player->dir_y * FT_STEP_SPEED * step;
}

void	player_rotate(t_map *map, t_player *player, float rotate)
{
	float	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	old_plane_x = player->plane_x;
	player->dir_x = player->dir_x * cos(FT_ROTATE_SPEED * rotate)
		- player->dir_y * sin(FT_ROTATE_SPEED * rotate);
	player->dir_y = old_dir_x * sin(FT_ROTATE_SPEED * rotate)
		+ player->dir_y * cos(FT_ROTATE_SPEED * rotate);
	player->plane_x = player->plane_x * cos(FT_ROTATE_SPEED * rotate)
		- player->plane_y * sin(FT_ROTATE_SPEED * rotate);
	player->plane_y = old_plane_x * sin(FT_ROTATE_SPEED * rotate)
		+ player->plane_y * cos(FT_ROTATE_SPEED * rotate);
	printf("player rotate x = %f y = %f\n", player->dir_x, player->dir_y);
	printf("player plane x = %f y = %f\n", player->plane_x, player->plane_y);
}

void	player_control(t_map *map, t_player *player, int keycode)
{
	if (keycode == 13 || keycode == 126)
		player_move(map, player, 1.f);
	if (keycode == 1 || keycode == 125)
		player_move(map, player, -1);
	if (keycode == 2 || keycode == 124)
		player_rotate(map, player, -1.f);
	if (keycode == 0 || keycode == 123)
		player_rotate(map, player, 1.f);
	printf("%d\n", keycode);
}
