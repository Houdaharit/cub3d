/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 00:31:57 by hharit            #+#    #+#             */
/*   Updated: 2023/01/13 00:33:07 by hharit           ###   ########.fr       */
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
	void	*mlx;
	void	*win;
	double	width;
	double	height;	
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	raydirX;
	double	raydirY;
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
}t_cub3d;

int		destroy(t_cub3d *cub);
int		ft_close(int keycode, t_cub3d *cub);
void	raycasting(t_cub3d *cub);

#endif
