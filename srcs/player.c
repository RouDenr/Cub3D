/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 01:02:34 by decordel          #+#    #+#             */
/*   Updated: 2022/06/30 04:48:50 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3D.h"

char	is_pl(char ch)
{
	return (ch == 'E' || ch == 'N' || ch == 'S' || ch == 'W');
}

void	init_player_dir(t_player *player, char dir)
{
	if (dir == 'E')
	{
		player->dir_x = -1;
		player->dir_y = 0;
	}
	if (dir == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
	}
	if (dir == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
	}
	if (dir == 'W')
	{
		player->dir_x = 1;
		player->dir_y = 0;
	}
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
				player->x = j;
				player->y = i;
				init_player_dir(player, map[i][j]);
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

	find_pl(&player, map);
	player.plane_x = 0;
	player.plane_y = 0.66;
	return (player);
}
