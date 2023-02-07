/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 00:31:57 by hharit            #+#    #+#             */
/*   Updated: 2023/02/07 23:51:56 by hharit           ###   ########.fr       */
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
	void	*minimap;
	void	*player;
	int		*addr;
	int     bits_per_pixel;
	int     line_length;
	int     endian;
	void		*addr1;
	int     bits_per_pixel1;
	int     line_length1;
	int     endian1;
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
	int		img_width_m;
	int		img_height_m;
	int		img_width;
	int		img_height;

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
#endif
