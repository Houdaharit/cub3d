/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:26:51 by hharit            #+#    #+#             */
/*   Updated: 2023/01/13 00:31:20 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	delta_x_y(t_cub3d *cub)
{
	if (!cub->raydirX)
		cub->deltax = 1e30;
	else
		cub->deltax = fabs(1 / cub->raydirX);
	if (!cub->raydirY)
		cub->deltay = 1e30;
	else
		cub->deltay = fabs(1 / cub->raydirY);
}

void	dist_x_y(t_cub3d *cub)
{
	cub->x = (int)cub->posx;
	cub->y = (int)cub->posy;

	delta_x_y(cub);
	if (cub->raydirX < 0)
	{
		cub->stepx = -1;
		cub->dx = (cub->posx - cub->x) * cub->deltax;
	}
	else
	{
		cub->stepx = 1;
		cub->dx = (cub->x + 1.0 - cub->posx) * cub->deltax;
	}
	if (cub->raydirY < 0)
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

void dda(t_cub3d *cub, char **map)
{
	dist_x_y(cub);
	while (map[cub->x][cub->y] != '1')
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
	printf("x: %d\n", cub->x);
	printf("y: %d\n", cub->y);
	printf("Wall\n");
}

void	raycasting(t_cub3d *cub, char **map)
{
	int	x = 0;

	while (x < cub->width)
	{
		cub->camerax = 2 * x / (double)cub->width - 1;
		cub->raydirX = cub->dirx + cub->planex * cub->camerax;
		cub->raydirY = cub->diry + cub->planey * cub->camerax;
		dda(cub, map);
		x++;
	}
}
