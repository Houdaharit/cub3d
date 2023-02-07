/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 00:42:07 by hharit            #+#    #+#             */
/*   Updated: 2023/02/07 21:24:04 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dda(t_cub3d *cub)
{
	/*delta_x_y(cub);
	dist_x_y(cub);*/
	while (cub->map[cub->x][cub->y] != '1')
	{
		if (cub->dx < cub->dy)
		{
			cub->dx += cub->deltax;
			cub->x += cub->stepx;
			cub->side = 0;
		}
		else
		{
			cub->dy += cub->deltay;
			cub->y += cub->stepy;
			cub->side = 1;
		}
	}
	if (cub->side == 0)
		cub->perpdistwall = cub->dx - cub->deltax;
	else
		cub->perpdistwall = cub->dy - cub->deltay;
	cub->line_height = (int)(cub->height / cub->perpdistwall);
	x_hit_wall(cub);
}

void	dist_x_y(t_cub3d *cub)
{
	
	cub->x = (int)cub->posx;
	cub->y = (int)cub->posy;
	if (cub->raydirx < 0)
	{
		cub->stepx = -1;
		cub->dx = (cub->posx - cub->x) * cub->deltax;
	}
	else
	{
		cub->stepx = 1;
		cub->dx = (cub->x + 1.0 - cub->posx) * cub->deltax;
	}
	if (cub->raydiry < 0)
	{
		cub->stepy = -1;
		cub->dy = (cub->posy - cub->y) * cub->deltay;
	}
	else
	{
		cub->stepy = 1;
		cub->dy = (cub->y + 1.0 - cub->posy) * cub->deltay;
	}
}

void	delta_x_y(t_cub3d *cub)
{
	if (!cub->raydirx)
		cub->deltax = 1e30;
	else
		cub->deltax = fabs(1 / cub->raydirx);
	if (!cub->raydiry)
		cub->deltay = 1e30;
	else
		cub->deltay = fabs(1 / cub->raydiry);
}
