/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 00:52:05 by decordel          #+#    #+#             */
/*   Updated: 2022/07/03 22:06:27 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3D.h"
#ifndef FT_ROTATE_SPEED
# define FT_ROTATE_SPEED .2f
#endif
#ifndef FT_STEP_SPEED
# define FT_STEP_SPEED .1f
#endif

void	player_move(t_map *map, t_player *player, int step)
{
	int		x;
	int		y;
	char	cell;

	x = (int)(player->x + player->dir.x * FT_STEP_SPEED * step);
	cell = map->map_arr[(int) player->y][x];
	if (cell == '0')
	{
		player->x += player->dir.x * FT_STEP_SPEED * step;
	}
	y = (int)(player->y + player->dir.y * FT_STEP_SPEED * step);
	cell = map->map_arr[y][(int) player->x];
	if (cell == '0')
	{
		player->y += player->dir.y * FT_STEP_SPEED * step;
	}
	printf("%d %d %c\n", x, y, cell);
}

void	player_rotate(t_player *player, float rotate)
{
	float	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir.x;
	old_plane_x = player->dir.plane_x;
	player->dir.x = player->dir.x * cos(FT_ROTATE_SPEED * rotate)
		- player->dir.y * sin(FT_ROTATE_SPEED * rotate);
	player->dir.y = old_dir_x * sin(FT_ROTATE_SPEED * rotate)
		+ player->dir.y * cos(FT_ROTATE_SPEED * rotate);
	player->dir.plane_x = player->dir.plane_x * cos(FT_ROTATE_SPEED * rotate)
		- player->dir.plane_y * sin(FT_ROTATE_SPEED * rotate);
	player->dir.plane_y = old_plane_x * sin(FT_ROTATE_SPEED * rotate)
		+ player->dir.plane_y * cos(FT_ROTATE_SPEED * rotate);
	printf("player rotate x = %f y = %f\n", player->dir.x, player->dir.y);
	printf("player plane x = %f y =\
	%f\n", player->dir.plane_x, player->dir.plane_y);
}

void	player_control(t_map *map, t_player *player, int keycode)
{
	if (keycode == 13 || keycode == 126)
		player_move(map, player, 1.f);
	if (keycode == 1 || keycode == 125)
		player_move(map, player, -1);
	if (keycode == 2 || keycode == 124)
		player_rotate(player, -1.f);
	if (keycode == 0 || keycode == 123)
		player_rotate(player, 1.f);
	printf("%d\n", keycode);
}
