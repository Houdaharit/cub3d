/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:26:51 by hharit            #+#    #+#             */
/*   Updated: 2023/02/07 23:52:39 by hharit           ###   ########.fr       */
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

int get_pixel(t_cub3d *fr, int x, int y)
{
	char *dst;
	dst = fr->addr1 + (y * fr->line_length1 + x * (fr->bits_per_pixel1 / 8));
	return *(int*)dst;
}

void	x_hit_wall(t_cub3d *cub)
{
	if (!cub->side)
		cub->wallx = cub->posy + cub->perpdistwall * cub->raydiry;
	else
		cub->wallx = cub->posx + cub->perpdistwall * cub->raydirx;
	cub->wallx -= (int)cub->wallx;
	draw(cub);
}

void	draw(t_cub3d *cub)
{
	//int	offsetx;
	//int	offsety;

	int	color = 0x0000FF;
	int drawstart = 0.5 * (cub->height - cub->line_height);
	if (drawstart < 0) drawstart = 0;
	int drawend = 0.5 * (cub->line_height + cub->height);
	if (drawend >= cub->height) drawend = cub->height - 1;
	int i = drawstart;
	if (cub->side == 1)
	color *= 0.5;
	while (i <= drawend)
	{
		//offsety = (i + (cub->line_height * 0.5) - cub->height * 0.5) * (64/ cub->line_height);
		my_mlx_pixel_put(cub, cub->pixel, i , color);
		i++;
	}
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
}

int	raycasting(t_cub3d *cub)
{
	double	width_2;

	width_2 = 2 / cub->width;
	cub->pixel = 0;
	while (cub->pixel < cub->width)
	{
		cub->camerax = cub->pixel * width_2 - 1;
		cub->raydirx = cub->dirx + cub->planex * cub->camerax;
		cub->raydiry = cub->diry + cub->planey * cub->camerax;
		delta_x_y(cub);
		dist_x_y(cub);
		dda(cub);
		cub->pixel++;
	}
	return 1;
}
