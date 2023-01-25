/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 00:31:57 by hharit            #+#    #+#             */
/*   Updated: 2023/01/25 07:26:07 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include "parsing/parsing.h"

typedef struct s_cub3d
{
    void    *mlx;
    void    *win;
    void    *img;
	void 	*walls;
	void	*player;
    int		*addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
	double	width;
	double	height;	
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	raydirx;
	double	raydiry;
	double	dx;
	double	dy;
	int		x;
	int		y;
	double	deltax;
	double	deltay;
	int		stepx;
	int		stepy;
	int		side;
	double	camerax;
	char	**map;
	double	perpdistwall;
	double	wallx;
	int		line_height;
	int		pixel;
	double	rotspeed;
	double	movespeed;
	int		buffer[800][800];
	int		**textures;
	int		tex_width;
	int		tex_height;
	int		img_width;
	int		img_height;
	char	direction;
}t_cub3d;

int		destroy(t_cub3d *cub);
int		ft_close(int keycode, t_cub3d *cub);
int		raycasting(t_cub3d *cub);
void	dda(t_cub3d *cub);
void	x_hit_wall(t_cub3d *cub);
void	draw(t_cub3d *cub);
void	my_mlx_pixel_put(t_cub3d*, int, int, int);
int		moves(int keycode, t_cub3d *cub);
void    delta_x_y(t_cub3d *cub);
void	dist_x_y(t_cub3d *cub);
void	draw(t_cub3d *cub);
void    ceils(t_cub3d *cub);
void	init(t_cub3d *cub, t_data map);
void	init_window(t_cub3d *cub);
void	init_direction(t_cub3d *cub);
void	init_player(t_cub3d *cub, t_data map);
void	init_north_west(t_cub3d *cub);
void	init_south_east(t_cub3d *cub);
void	init_textures(t_cub3d *cub);
void	init_buffer(t_cub3d *cub);
void	load_image(t_cub3d *cub, t_data map);
void	free_image(t_cub3d *cub);
#endif
