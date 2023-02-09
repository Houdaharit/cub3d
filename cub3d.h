/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 00:31:57 by hharit            #+#    #+#             */
/*   Updated: 2023/02/09 08:00:18 by ahakam           ###   ########.fr       */
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

#define	WIDTH 1600
#define HEIGHT 1000
#define TILE  64
#define SPEED 10
#define ROT_SPEED 0.17453292519

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
	double	inter_x;
	double	inter_y;
	char	v_or_h;
	char	wall;
	int		flag_ver;
	int		flag_hor;
	double	x_ver;
	double	y_ver;
	double	x_hor;
	double	y_hor;
}	t_ray;

typedef struct	s_cub3d
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
	t_player	player;
	t_ray		ray;
	int			tile_size;
	double		fov_angle;
	int			flag_hor;
	double inter_y;
	int flag_ver;
	char v_or_h ;
	double inter_x;
		/////////////////////
	void			*mlx_window;
	int				map_rows;
	int				map_columns;
	int				map_length;
	int				map_width;
	char			**map;
	double			player_x;
	double			player_y;
	double			angle;
	double			d2pp;	
	int				floor;
	int				ceilling;
	double			dist_plane;
	int i;
	int j;
	void			*play;
	void			*walls;
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
	double	index_v;
	double	index_h;
	

}	t_inter;

int		destroy(t_cub3d *cub);
void	init(t_cub3d *cub, t_data *map);
double	normalize_angle(double angle);
int		move(int keycode, t_cub3d *cub);
bool	if_hit_wall_collision(t_cub3d *cub, int x, int y);
int		key_release(int keycode, t_cub3d *cub);
int		move_player(t_cub3d *cub);
void	wallx_y_h(t_cub3d *cub, t_inter *inter);
void	wallx_y_v(t_cub3d *cub, t_inter *inter);
void	default_inter(t_inter *inter);
void	cast_ray(t_cub3d *cub, double,t_inter *inter_h,t_inter *inter_y);
void	raycasting(t_cub3d *cub);
t_inter	v_intersection(t_cub3d *cub);
t_inter	h_intersection(t_cub3d *cub);void	rending(t_cub3d *cub);
void    draw(t_cub3d *cub, int pixel);
int		wall_height(t_cub3d *cub);
void    my_mlx_pixel_put(t_cub3d *fr, int x, int y, int color);
int 	check_grid(t_cub3d *cub, double x, double y, int moving);
void	x_y_step_ver(t_cub3d *cub, double, t_inter *);
void	x_y_step_hor(t_cub3d *cub, double, t_inter *);
void	drawing_ray(t_cub3d *game, double wallheight, int i);
void	move_for(t_cub3d *game);
void	move_right(t_cub3d *game);
void	move_left(t_cub3d *game);
void	move_back(t_cub3d *game);
int	update(t_cub3d *cub);
#endif
