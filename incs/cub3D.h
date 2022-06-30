/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:48:26 by decordel          #+#    #+#             */
/*   Updated: 2022/06/30 23:02:48 by decordel         ###   ########.fr       */
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
	float	x;
	float	y;
	float	dir_x;
	float	dir_y;
	float	plane_x;
	float	plane_y;
	char	start_dir;
}			t_player;

typedef struct s_ray
{
	int			x;
	int			map_x;
	int			map_y;
	float		ray_x;
	float		ray_y;
	int			step_x;
	int			step_y;
	int			side;
	float		side_dist_x;
	float		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;

}			t_ray;

typedef struct s_sources
{
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

t_mlx		game_init(t_map *map);
int			do_next_frame(t_mlx *mlx);
t_player	player_init(char **map);
void		raycasting(t_mlx *mlx);
void		ft_pixel_put(t_img *img, int x, int y, int color);
void		draw_ver_line(t_mlx *mlx, int x, int y[], int color);
void		draw_background(t_mlx *mlx);

#endif
