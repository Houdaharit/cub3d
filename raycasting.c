/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:26:51 by hharit            #+#    #+#             */
/*   Updated: 2023/01/17 02:08:03 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//delete
/*void	my_mlx_pixel_put(t_cub3d *fr, int x, int y, int color)
  {
  char	*dst;

  dst = fr->addr + (y * fr->line_length + x * (fr->bits_per_pixel / 8));
 *(unsigned int *)dst = color;
 }*/

void	x_hit_wall_height(t_cub3d *cub)
{
	if (!cub->side)
		cub->wallx = cub->posy + cub->perpdistwall * cub->raydiry;
	else
		cub->wallx = cub->posx + cub->perpdistwall * cub->raydirx;
	cub->wallx -= (int)cub->wallx;
	cub->line_height = (int)(cub->height / cub->perpdistwall);
}

void	draw(t_cub3d *cub)
{
	int drawstart = cub->height / 2 - cub->line_height / 2;
	if (drawstart < 0) drawstart = 0;
	int drawend = cub->line_height / 2 + cub->height / 2;
	if (drawend >= cub->height) drawend = cub->height - 1;
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
		draw(cub);
	}
}
