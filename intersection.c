/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 05:10:03 by hharit            #+#    #+#             */
/*   Updated: 2023/01/27 06:57:55 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wallx_y_h(t_cub3 *cub)
{
	while (cub->inter.x >= 0 && cub->inter.x <= cub->mlx.width
		&& cub->inter.y >= 0 && cub->inter.y <= cub->mlx.height)
	{
		if (cub->map[cub->inter.x][cub->inter.y] == '1')
		{
			cub->ray.horizontal = true;
			cub->ray.wallx = cub->inter.x;
			cub->ray.wally = cub->inter.y;
			default_inter(&cub.inter);
			break ;
		}
		else
		{
			cub->inter.x += cub->inter.stepx;
			cub->inter.y += cub->inter.stepy;
		}
	}
	default_inter(&cub.inter);
}

void	wallx_y_v(t_cub3d *cub)
{
	while (cub->inter.x >= 0 && cub->inter.x <= cub->mlx.width
		&& cub->inter.y >= 0 && cub->inter.y <= cub->mlx.height)
	{
		if (cub->map[cub->inter.x][cub->inter.y] == '1')
		{
			cub->ray.vertical = true;
			cub->ray.wallx = cub->inter.x;
			cub->ray.wally = cub->inter.y;
			default_inter(&cub.inter);
			break ;
		}
		else
		{
			cub->inter.x += cub->inter.stepx;
			cub->inter.y += cub->inter.stepy;
		}
	}
	default_inter(&cub.inter);
}

void	v_intersection(t_cub3d *cub)
{
	cub->inter.x = floor(cub->player.posx / cub->tile_size) * tile_size;
	if (cub->player.face == 'E')
		cub->inter.x *= -1;
	cub->inter.y = cub->player.posy + (cub->inter.y - cub->player.posy)
		/ tan(cub->ray.ray_angle);
	cub->inter.stepx = cub->tile_size;
	if (cub->player.face == 'W')
		cub->inter.stepx *= -1;
	cub->inter.stepy = cub->tile_size * tan(cub->ray.ray_angle);
	if (cub->player.face == 'N' && cub->inter.stepy > 0)
		cub->inter.stepy *= -1;
	if (cub->player.face == 'S' && cub->inter.stepy < 0)
		cub->inter.stepy *= -1;
	if (cub->player.face == 'N')
		cub->inter.y--;
	wallx_y_v(cub);
}

void	h_intersection(t_cub3d *cub)
{
	cub->inter.y = floor(cub->player.posy / cub->tile_size) * cub->tile_size;
	if (cub->player.face == 'S')
		cub->inter.y += cub->tile_size;
	cub->inter.x = cub->player.posx + (cub->inter.y - cub->player.posy)
		/ tan(cub->ray.ray_angle);
	cub->inter.stepy = cub->size_tile;
	if (cub->player.face == 'N')
		cub->inter.stepy *= -1;
	cub->inter.stepx = cub->tile_size / tan(cub->ray.ray_angle);
	if (cub->player.face == 'W' && dx > 0)
		cub->inter.stepx *= -1;
	if (cub->player.face == 'E' && dx < 0)
		cub->inter.stepx *= -1;
	if (cub->player.face == 'N')
		cub->inter.y--;
	wallx_y_h(cub);
}
