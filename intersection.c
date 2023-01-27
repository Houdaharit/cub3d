/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 05:10:03 by hharit            #+#    #+#             */
/*   Updated: 2023/01/27 08:12:40 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	wallx_y_h(t_cub3d *cub, t_inter inter)
{
	while (inter.x >= 0 && inter.x <= cub->mlx.width
		&& inter.y >= 0 && inter.y <= cub->mlx.height)
	{
		//It needs a function to check
		if (cub->map[inter.x][inter.y] == '1')
		{
			inter.horizontal = true;
			inter.wallx = inter.x;
			inter.wally = inter.y;
			break ;
		}
		else
		{
			inter.x += inter.stepx;
			inter.y += inter.stepy;
		}
	}
	if (inter.horizontal)
		inter.distance = hypot(cub->player.posx - inter.wallx,
				cub->player.posy - inter.wally);
	return (inter.distance);
}

double	wallx_y_v(t_cub3d *cub, t_inter inter)
{
	while (inter.x >= 0 && inter.x <= cub->mlx.width
		&& inter.y >= 0 && inter.y <= cub->mlx.height)
	{
		//It needs a function to check
		if (cub->map[inter.x][inter.y] == '1')
		{
			inter.vertical = true;
			inter.wallx = inter.x;
			inter.wally = inter.y;
			break ;
		}
		else
		{
			inter.x += inter.stepx;
			inter.y += inter.stepy;
		}
	}
	if (inter.vertical)
		inter.distance = hypot(cub->player.posx - inter.wallx,
				cub->player.posy - inter.wally);
	return (inter.distance);
}

void	v_intersection(t_cub3d *cub)
{
	t_inter	inter;

	default_inter(&inter);
	inter.x = floor(cub->player.posx / cub->tile_size) * cub->tile_size;
	if (cub->player.face == 'E')
		inter.x *= -1;
	inter.y = cub->player.posy + (inter.y - cub->player.posy)
		/ tan(cub->ray.ray_angle);
	inter.stepx = cub->tile_size;
	if (cub->player.face == 'W')
		inter.stepx *= -1;
	inter.stepy = cub->tile_size * tan(cub->ray.ray_angle);
	if (cub->player.face == 'N' && inter.stepy > 0)
		inter.stepy *= -1;
	if (cub->player.face == 'S' && inter.stepy < 0)
		inter.stepy *= -1;
	if (cub->player.face == 'N')
		inter.y--;
	wallx_y_v(cub, inter);
}

void	h_intersection(t_cub3d *cub)
{
	t_inter	inter;

	default_inter(&inter);
	inter.y = floor(cub->player.posy / cub->tile_size) * cub->tile_size;
	if (cub->player.face == 'S')
		inter.y += cub->tile_size;
	inter.x = cub->player.posx + (inter.y - cub->player.posy)
		/ tan(cub->ray.ray_angle);
	inter.stepy = cub->tile_size;
	if (cub->player.face == 'N')
		inter.stepy *= -1;
	inter.stepx = cub->tile_size / tan(cub->ray.ray_angle);
	if (cub->player.face == 'W' && inter.stepx > 0)
		inter.stepx *= -1;
	if (cub->player.face == 'E' && inter.stepx < 0)
		inter.stepx *= -1;
	if (cub->player.face == 'N')
		inter.y--;
	wallx_y_h(cub, inter);
}
