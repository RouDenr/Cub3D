/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map_validation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:13:10 by vseel             #+#    #+#             */
/*   Updated: 2022/07/23 21:18:36 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/parser.h"
#include "../libft/libft.h"

char	is_valid_map_line(char *line)
{
	const char	allowed_chars[] = "01NSEWD \n";

	if (!line)
		return (1);
	if (!line || *line == '\n')
		return (0);
	while (*line)
	{
		if (!ft_strchr(allowed_chars, *line))
			return (0);
		++line;
	}
	return (1);
}

/**
 * @param m is for map
*/
char	is_vaild_near_cells(char **m, int i, int j)
{
	return (((m[i][j - 1] != '1' && m[i][j - 1] != '0' && m[i][j - 1] != 'N'
			&& m[i][j - 1] != 'S' && m[i][j - 1] != 'E' && m[i][j - 1] != 'W')
			|| (m[i][j + 1] != '1' && m[i][j + 1] != '0' && m[i][j + 1] != 'N'
			&& m[i][j + 1] != 'S' && m[i][j + 1] != 'E' && m[i][j + 1] != 'W')
			|| (m[i - 1][j] != '1' && m[i - 1][j] != '0' && m[i - 1][j] != 'N'
			&& m[i - 1][j] != 'S' && m[i - 1][j] != 'E' && m[i - 1][j] != 'W')
			|| (m[i + 1][j] != '1' && m[i + 1][j] != '0' && m[i + 1][j] != 'N'
		&& m[i + 1][j] != 'S' && m[i + 1][j] != 'E' && m[i + 1][j] != 'W')));
}

/**
 * @param m is alias for `map->map_arr`
*/
char	is_valid_map(t_map *map)
{
	int		i;
	int		j;
	char	is_player_here;
	char	**m;

	i = 0;
	is_player_here = 0;
	m = map->map_arr;
	while (m[++i])
	{
		j = -1;
		while (m[i][++j])
		{
			if (m[i][j] != '1' && m[i][j] != ' ' && m[i][j] != '\n'
			&& is_vaild_near_cells(m, i, j))
				return (throw_error("map: map can't be unclosed", 0, 'm'));
			if ((m[i][j] == 'N' || m[i][j] == 'S'
			|| m[i][j] == 'E' || m[i][j] == 'W') && is_player_here++)
				return (throw_error("map: there is can be only one player char",
						0, 'm'));
		}
	}
	if (!is_player_here)
		return (throw_error("map: no player char on map", 0, 'm'));
	return (1);
}
