/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:26:51 by hharit            #+#    #+#             */
/*   Updated: 2022/12/27 20:07:45 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void raylen(t_cub3d *cub)
{
	if (!cub->raydirX)
		cub->dx = 1e30;
	else
		cub->dx = fabs(1 / cub->raydirX);
	if (!cub->raydirY)
		cub->dy = 1e30;
	else
		cub->dy = fabs(1 / cub->raydirY);
}

void	raylen_start(t_cub3d *cub)
{
	cub->x = (int)cub->posx;
	cub->y = (int)cub->posy;
	if (cub->raydirX < 0)
	{
		cub->stepx = -1;
		cub->sidex = (cub->posx - cub->x) * cub->dx;
	}
	else
	{
		cub->stepx = 1;
		cub->sidex = (cub->x + 1.0 - cub->posx) * cub->dx;
	}
	if (cub->raydirY < 0)
	{
		cub->stepy = -1;
		cub->sidey = (cub->posy - cub->y) * cub->dy;
	}
	else
	{
		cub->stepy = 1;
		cub->sidey = (cub->y + 1.0 - cub->posy) * cub->dy;
	}
}

void dda(t_cub3d *cub, char **map)
{

	while (map[cub->x][cub->y] != '1')
	{
		if (cub->sidex < cub->sidey)
		{
			cub->sidex += cub->dx;
			cub->x += cub->stepx;
			cub->side = 0;
		}
		else
		{
			cub->sidey += cub->dy;
			cub->y += cub->stepy;
			cub->side = 1;
		}
	}
}
