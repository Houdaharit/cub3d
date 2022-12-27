/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:26:51 by hharit            #+#    #+#             */
/*   Updated: 2022/12/27 17:38:35 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void raylen(t_cub3d *cub)
{
	if (!cub->raydirX)
		cub->dx = 1e30;
	else
		cub->dx = abs(1 / raydirx);
	if (!cub->raydiry)
		cub->dy = 1e30;
	else
		cub->dy = abs(1 / raydiry);
}

void	raylen_start(t_cub3d *cub)
{
	int	x;
	int	y;

	x = (int)cub->posx;
	y = (int)cub->posy;
	if (cub->raydirx < 0)
	{
		cub->stepx = -1;
		cub->sidex = (cub->posx - x) * cub->dx;
	}
	else
	{
		cub->stepx = 1;
		cub->sidex = (x + 1.0 - cub->posx) * cub->dx;
	}
	if (cub->raydiry < 0)
	{
		cub->stepy = -1;
		cub->sidey = (cub->posy - y) * cub->dy;
	}
	else
	{
		cub->stepy = 1;
		cub->sidey = (y + 1.0 - cub->posy) * cub->dy;
	}
}

void dda(t_cub3d *cub)
{
	while ()
	{

	}
}
