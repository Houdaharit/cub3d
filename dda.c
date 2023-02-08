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

double	dda(t_cub3d *cub, int x, int y)
{
	double	d[2];

	dist_x_y(cub, d, x, y);
	while (1)
	{
		if (d[0] < d[1])
		{
			d[0] += cub->deltax;
			x += cub->stepx;
			cub->side = 0;
		}
		else
		{
			d[1] += cub->deltay;
			y += cub->stepy;
			cub->side = 1;
		}
		if (cub->map[x][y] == '1')
			break;
	}
	if (cub->side == 0)
		return cub->perpdistwall = d[0] - cub->deltax;
	return cub->perpdistwall = d[1] - cub->deltay;
}

void	dist_x_y(t_cub3d *cub, double *d, int x, int y)
{

	if (cub->raydirx < 0)
	{
		cub->stepx = -1;
		d[0] = (cub->posx - x) * cub->deltax;
	}
	else
	{
		cub->stepx = 1;
		d[0] = (x + 1.0 - cub->posx) * cub->deltax;
	}
	if (cub->raydiry < 0)
	{
		cub->stepy = -1;
		d[1] = (cub->posy - y) * cub->deltay;
	}
	else
	{
		cub->stepy = 1;
		d[1] = (y + 1.0 - cub->posy) * cub->deltay;
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
