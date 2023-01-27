/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 00:31:57 by hharit            #+#    #+#             */
/*   Updated: 2023/01/27 03:33:13 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <stdbool.h>
# include "parsing/parsing.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*addr;
	void	*img;
	int		width;
	int		height;
}	t_mlx;

typedef struct s_player
{
	//maybe I have to change some variables' type
	int	posx;
	int	posy;
	int	move_speed;
	int	rotation_speed;
	int	turn_dir;
	int	walk_dir;
	int	rot_angle;
}	t_player;

typedef struct	s_cub3d
{
	t_mlx		mlx;
	t_player	player;
	char		**map;
	int			tile_size;
	double		fov_angle;
}	t_cub3d;

void	move(int keycode, t_cu3d *cub);
bool	if_hit_wall(t_cub3d *cub, int x, int y);
void	move_player(t_cub3d *cub);
#endif
