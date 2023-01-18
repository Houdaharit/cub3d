/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:26:51 by hharit            #+#    #+#             */
/*   Updated: 2023/01/18 01:06:25 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//delete
void	my_mlx_pixel_put(t_cub3d *fr, int x, int y, int color)
{
	char	*dst;

	dst = fr->addr + (y * fr->line_length + x * (fr->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	x_hit_wall_height(t_cub3d *cub)
{
	if (!cub->side)
		cub->wallx = cub->posy + cub->perpdistwall * cub->raydiry;
	else
		cub->wallx = cub->posx + cub->perpdistwall * cub->raydirx;
	cub->wallx -= (int)cub->wallx;
	cub->line_height = (int)(cub->height / cub->perpdistwall);
	draw(cub);
}

void	draw(t_cub3d *cub)
{
	int	color = 0x0000FF;
	int drawstart = cub->height / 2 - cub->line_height / 2;
	if (drawstart < 0) drawstart = 0;
	int drawend = cub->line_height / 2 + cub->height / 2;
	if (drawend >= cub->height) drawend = cub->height - 1;
	if (cub->side == 1)
		color = color / 2;
	int i = drawstart;
	while (i <= drawend)
	{
		my_mlx_pixel_put(cub, cub->pixel, i, color);
		i++;
	}
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
}

int	raycasting(t_cub3d *cub)
{
	cub->pixel = 0;
	while (cub->pixel < cub->width)
	{
		cub->camerax = 2 * cub->pixel / (double)cub->width - 1;
		cub->raydirx = cub->dirx + cub->planex * cub->camerax;
		cub->raydiry = cub->diry + cub->planey * cub->camerax;
		dda(cub);
		cub->pixel++;
	}
	return 1;
}
