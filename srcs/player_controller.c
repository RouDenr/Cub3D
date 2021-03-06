/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 00:52:05 by decordel          #+#    #+#             */
/*   Updated: 2022/07/14 23:19:06 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3D.h"

/**
 * @brief
 *
 * @param	map		Game map
 * @param	player	Player info
 * @param	keycode	key code pressed by the user:
 * 					13	- W;		126	- arrow up;
 * 					1	- S;		125	- arrow down;
 * 					2	- D;		124	- arrow right;
 * 					0	- A;		123	- arrow left;
 * 					49	- Spase
 */
void	player_control(t_map *map, t_player *player, int keycode)
{
	if (keycode == 13)
		player_move_up(map, player, 1.f);
	if (keycode == 1)
		player_move_up(map, player, -1.f);
	if (keycode == 2)
		player_move_right(map, player, 1.f);
	if (keycode == 0)
		player_move_right(map, player, -1.f);
	if (keycode == 124)
		player_rotate(player, 1.f);
	if (keycode == 123)
		player_rotate(player, -1.f);
}
