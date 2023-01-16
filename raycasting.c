/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:26:51 by hharit            #+#    #+#             */
/*   Updated: 2023/01/17 00:55:06 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	x_hit_wall(t_cub3d *cub)
{
	if (!cub->side)
		cub->wallx = cub->posy + cub->perpdistwall * cub->raydiry;
	else
		cub->wallx = cub->posx + cub->perpdistwall * cub->raydirx;
	cub->wallx -= (int)cub->wallx;
}


void	raycasting(t_cub3d *cub)
{
	int	x;

	x = 0;
	while (x < cub->width)
	{
		cub->camerax = 2 * x / (double)cub->width - 1;
		cub->raydirx = cub->dirx + cub->planex * cub->camerax;
		cub->raydiry = cub->diry + cub->planey * cub->camerax;
		dda(cub);
		x++;
	}
}
