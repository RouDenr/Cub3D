/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:48:26 by decordel          #+#    #+#             */
/*   Updated: 2022/07/24 15:52:05 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef FT_WIN_H
#  define FT_WIN_H 1080
# endif

# ifndef FT_WIN_H_CENTER
#  define FT_WIN_H_CENTER FT_WIN_H / 2
# endif

# ifndef FT_WIN_W
#  define FT_WIN_W 1920
# endif

# ifndef FT_DEBUG_MOD
#  define FT_DEBUG_MOD 1
# endif

# ifndef FT_WIN_W_CENTER
#  define FT_WIN_W_CENTER FT_WIN_W / 2
# endif

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

typedef struct s_player_dir
{
	float	x;
	float	y;
	float	plane_x;
	float	plane_y;
}			t_player_dir;

typedef struct s_mouse
{
	int	mouse_hook;
}			t_mouse;

typedef struct s_player
{
	float			x;
	float			y;
	t_player_dir	dir;
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

typedef struct s_draw_info
{
	int			height_dr;
	int			y[2];
	float		w_dist;
}				t_draw_info;

typedef struct s_wall
{
	t_img	*img;
	float	tex_x;
	float	tex_y[2];
	float	step;
}				t_wall;

typedef struct s_sources
{
	t_img	wall_no;
	t_img	wall_so;
	t_img	wall_we;
	t_img	wall_ea;
	t_img	door;
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

int			exit_hook(void);
int			mouse_hook(int x, int y, t_mlx *mlx);
int			key_hook(int keycode, t_mlx *mlx);

t_player	player_init(char **map);
void		player_control(t_map *map, t_player *player, int keycode);
void		player_move_right(t_map *map, t_player *player, int step);
void		player_move_up(t_map *map, t_player *player, int step);
void		player_rotate(t_player *player, float rotate);

void		raycasting(t_mlx *mlx);
void		ft_pixel_put(t_img *img, int x, int y, int color);
void		draw_ver_line_wall(t_mlx *mlx, int x, int y[], t_wall wall);
void		draw_background(t_mlx *mlx);

t_img		*get_texture_by_dir(t_sources *sourcer, t_ray *ray, char cell);
t_wall		get_texture_info(t_mlx *mlx, t_ray *ray, t_draw_info info);

void		init_minimap(t_mlx *mlx, t_map *map);

int			print_log_ray(int keycode, t_ray *ray);

#endif
