/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 04:12:42 by hharit            #+#    #+#             */
/*   Updated: 2023/01/25 05:44:59 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_window(t_cub3d *cub)
{
	cub->width = 800;
	cub->height = 800;
	cub->win = mlx_new_window(cub->mlx, cub->width, cub->height, "cub3d");
	cub->img = mlx_new_image(cub->mlx, cub->width, cub->height);
	cub->addr = (int *)mlx_get_data_addr(cub->img, &(cub->bits_per_pixel),
			&(cub->line_length), &(cub->endian));
}

void	init_direction(t_cub3d *cub)
{
	init_north_west(cub);
	init_south_east(cub);
}

void	init_player(t_cub3d *cub, t_data map)
{
	cub->rotspeed = 0.7;
	cub->movespeed = 1.1;
	cub->posx = map.xPposition;
	cub->posy = map.yPposition;
	init_direction(cub);
//	cub->map[(int)cub->posx][(int)cub->posy] = '0';
}

void	init(t_cub3d *cub, t_data map)
{
	cub->map = map.map;
	cub->direction = map.direction;
	init_window(cub);
	init_player(cub, map);
}
