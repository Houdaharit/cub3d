/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 00:31:57 by hharit            #+#    #+#             */
/*   Updated: 2023/02/03 18:54:38 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "parsing/parsing.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*addr;
	void	*img;
	int		width;
	int		height;
	int     bits_per_pixel;
	int     line_length;
	int     endian;
}	t_mlx;

typedef struct s_player
{
	//maybe I have to change some variables' type
	int			posx;
	int			posy;
	double		move_speed;
	double		rotation_speed;
	int			turn_dir;
	int			walk_dir;
	double		rot_angle;
	char		face;
}	t_player;

typedef struct	s_ray
{
	bool	vertical;
	bool	horizontal;
	double	wallx;
	double	wally;
	double	ray_angle;
	double	distance;
}	t_ray;

typedef struct	s_cub3d
{
	t_mlx		mlx;
	t_player	player;
	t_ray		ray;
	char		**map;
	int			tile_size;
	double		fov_angle;
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
	double	wallx;
	double	wally;

}	t_inter;

int		destroy(t_cub3d *cub);
void	init(t_cub3d *cub, t_data map);
double	normalize_angle(double angle);
int		move(int keycode, t_cub3d *cub);
bool	if_hit_wall(t_cub3d *cub, int x, int y);
int		key_release(int keycode, t_cub3d *cub);
int		move_player(t_cub3d *cub);
void	wallx_y_h(t_cub3d *cub, t_inter *inter);
void	wallx_y_v(t_cub3d *cub, t_inter *inter);
void	default_inter(t_inter *inter);
void	cast_ray(t_cub3d *cub);
void	raycasting(t_cub3d *cub);
t_inter	v_intersection(t_cub3d *cub);
t_inter	h_intersection(t_cub3d *cub);
void    draw(t_cub3d *cub, int pixel);
int wall_height(t_cub3d *cub);
void    my_mlx_pixel_put(t_cub3d *fr, int x, int y, int color);
int check_grid(t_cub3d cub, int x, int y, char dir);
t_inter	x_y_step_ver(t_cub3d *cub);
t_inter	x_y_step_hor(t_cub3d *cub);
#endif
