/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 00:52:05 by decordel          #+#    #+#             */
/*   Updated: 2022/07/24 18:32:48 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3D.h"
#ifndef FT_ROTATE_SPEED
# define FT_ROTATE_SPEED .025f
#endif
#ifndef FT_STEP_SPEED
# define FT_STEP_SPEED .05f
#endif

void	player_move_right(t_map *map, t_player *player, int step)
{
	float	x;
	float	y;
	char	cell;

	x = (player->x + player->dir.y * FT_STEP_SPEED * step * -1);
	y = (player->y + player->dir.x * FT_STEP_SPEED * step);
	cell = map->map_arr[(int) player->y][(int) x];
	if (cell == '0')
	{
		player->x = x;
	}
	cell = map->map_arr[(int) y][(int) player->x];
	if (cell == '0')
	{
		player->y = y;
	}
}

void	player_move_up(t_map *map, t_player *player, int step)
{
	float	x;
	float	y;
	char	cell;

	x = (player->x + player->dir.x * FT_STEP_SPEED * step);
	cell = map->map_arr[(int) player->y][(int) x];
	if (cell == '0')
	{
		player->x = x;
	}
	y = (player->y + player->dir.y * FT_STEP_SPEED * step);
	cell = map->map_arr[(int) y][(int) player->x];
	if (cell == '0')
	{
		player->y = y;
	}
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
}
