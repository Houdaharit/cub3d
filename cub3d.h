/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 00:31:57 by hharit            #+#    #+#             */
/*   Updated: 2023/02/17 15:39:50 by ahakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "parsing/parsing.h"
# include <mlx.h>

# define WIDTH 1600
# define HEIGHT 1000
# define TILE  64
# define SPEED 20
# define ROT_SPEED 0.17453292519

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*addr;
	void	*img;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx;

typedef struct s_ray
{
	bool	vertical;
	bool	horizontal;
	double	distance;
	double	inter_x;
	double	inter_y;
}	t_ray;

typedef struct s_texture
{
	void	*img;
	void	*addr_;
	int		height;
	int		width;
	int		endian;
	int		line_length;
	int		bits_per_pixel;
}	t_texture;

typedef struct s_cub3d
{
	t_ray		ray;
	t_texture	tex[4];
	void		*mlx;
	void		*addr;
	int			mini_width;
	int			mini_height;
	void		*img;
	void		*mlx_window;
	int			width;
	int			height;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	double		fov_angle;
	int			map_rows;
	int			map_columns;
	int			map_length;
	int			map_width;
	char		**map;
	double		player_x;
	double		player_y;
	double		angle;
	int			floors;
	int			ceilling;
	double		dist_plane;
	int			i;
	int			j;
	int			floor;
	int			ceillings;
	int			mini_i;
	int			mini_j;
	int			mini_x;
	int			mini_y;	
	void		*play_xpm;
	void		*walls_xpm;
	int			offsetx;
	int			offsety;
}	t_cub3d;

typedef struct s_inter
{
	double	x;
	double	y;
	double	stepx;
	double	stepy;
	bool	vertical;
	bool	horizontal;
	double	distance;
	double	index;
	bool	ver_flag;
	bool	hor_flag;
}	t_inter;

int			destroy(t_cub3d *cub);
void		init(t_cub3d *cub, t_data *map);
int			move(int keycode, t_cub3d *cub);
bool		if_hit_wall_collision(t_cub3d *cub, int x, int y);
int			key_release(int keycode, t_cub3d *cub);
int			move_player(t_cub3d *cub);
void		wallx_y_h(t_cub3d *cub, t_inter *inter);
void		wallx_y_v(t_cub3d *cub, t_inter *inter);
void		default_inter(t_inter *inter);
void		cast_ray(t_cub3d *cub, double angle);
void		raycasting(t_cub3d *cub);
void		rending(t_cub3d *cub);
double		normalize_angle(double angle);
void		draw(t_cub3d *cub, int pixel);
int			wall_height(t_cub3d *cub);
void		my_mlx_pixel_put(t_cub3d *fr, int x, int y, int color);
int			check_grid(t_cub3d *cub, double x, double y, int moving);
void		x_y_step_ver(t_cub3d *cub, double angle, t_inter *inter_v);
void		x_y_step_hor(t_cub3d *cub, double angle, t_inter *inter_h);
void		drawing_ray(t_cub3d *game, double wallheight,
				int pixel, int tex_id);
void		move_for(t_cub3d *game);
void		move_right(t_cub3d *game);
void		move_left(t_cub3d *game);
void		move_back(t_cub3d *game);
int			update(t_cub3d *cub);
void		minimap(t_cub3d *cub);
void		init_tex(t_cub3d *cub, t_data map);
t_inter		v_intersection(t_cub3d *cub);
t_inter		h_intersection(t_cub3d *cub);
int			tex_id(t_cub3d cub, double ray_angle);
void		floor_and_cellings(t_cub3d *cub);
int			key_hook(int keycode, t_cub3d *cub);
int			mouse_hook(int move, int x, int y, t_cub3d *cub);
#endif
