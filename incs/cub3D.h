/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:48:26 by decordel          #+#    #+#             */
/*   Updated: 2022/06/30 00:53:35 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef FT_WIN_H
#  define FT_WIN_H 1080
# endif

# ifndef FT_WIN_W
#  define FT_WIN_W 1920
# endif

# define FT_PL_STEP	0.5

# include "../libft/libft.h"
# include "../parser/incs/parser.h"
# include "../minilibx/mlx.h"

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		w;
	int		h;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;

	char	start_dir;
}			t_player;

typedef struct s_sources
{
	t_img	screen;
	t_img	wall_no;
	t_img	wall_so;
	t_img	wall_we;
	t_img	wall_ea;
}				t_sources;

typedef struct s_mlx
{
	void		*init;
	void		*win;
	t_map		*map;
	t_player	player;
	t_img		screen;
	t_sources	sources;
}				t_mlx;

t_mlx	game_init(t_map *map);

// int		check_invalid_items(char *map);
// void	find_pl(t_player *player, char **data);
// int		check_wall(char **map);
// void	ft_pixel_put(t_img *img, int x, int y, int color);
// void	ft_img_put_screen(t_img *screen, t_img *img, int x, int y);

#endif