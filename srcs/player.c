/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 01:02:34 by decordel          #+#    #+#             */
/*   Updated: 2022/07/13 19:15:18 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3D.h"

char	is_pl(char ch)
{
	return (ch == 'E' || ch == 'N' || ch == 'S' || ch == 'W');
}

t_player_dir	player_dir(float x, float y, float plane_x, float plane_y)
{
	t_player_dir	dir;

	dir.x = x;
	dir.y = y;
	dir.plane_x = plane_x;
	dir.plane_y = plane_y;
	return (dir);
}

void	init_player_dir(t_player *player, char dir)
{
	if (dir == 'E')
		player->dir = player_dir(1.f, 0.f, 0.f, 0.80f);
	if (dir == 'N')
		player->dir = player_dir(0.f, -1.f, 0.80f, 0.f);
	if (dir == 'S')
		player->dir = player_dir(0.f, 1.f, -0.80f, 0.f);
	if (dir == 'W')
		player->dir = player_dir(-1.f, 0.f, 0.f, -0.80f);
}

void	find_pl(t_player *player, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_pl(map[i][j]))
			{
				player->x = j + .5f;
				player->y = i + .5f;
				init_player_dir(player, map[i][j]);
				map[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}

t_player	player_init(char **map)
{
	t_player	player;

	player.x = -1;
	player.y = -1;
	find_pl(&player, map);
	if (player.x == -1 || player.y == -1)
		ft_put_err("cub3D: no player");
	return (player);
}
