/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_calcul.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 02:58:46 by hharit            #+#    #+#             */
/*   Updated: 2023/01/23 23:32:35 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	texture_calcul(t_cub3d *cub, int drawstart, int drawend)
{
	double	step;
	int		y;
	int tex_x;
	int tex_y;
	int	tex_pos;

	tex_x = (int)(cub->wallx * cub->tex_width);
	if (!cub->side && cub->raydirx > 0)
		tex_x = cub->tex_width - tex_x - 1;
	if (cub->side == 1 && cub->raydirx < 0)
		tex_x = cub->tex_width - tex_x - 1;
	step = 1.0 * cub->tex_height / cub->line_height;
	tex_pos = (drawstart - cub->height / 2 + cub->line_height / 2) * step;
	y = drawstart;
	while (y < drawend)
	{
		tex_y = (int)tex_pos;
		tex_pos += step;
		int color = cub->textures[0][cub->tex_height * tex_y + tex_x];
		if (cub->side == 1) color = (color >> 1);
		cub->buffer[y][cub->pixel] = color;
		y++;
	}
}

void    draw(t_cub3d *cub)
{
	int y = 0;
	int x = 0;
	int	drawstart;
	int	drawend;

	drawstart = cub->height / 2 - cub->line_height / 2;
	if (drawstart < 0)
		drawstart = 0;
	drawend = cub->line_height / 2 + cub->height / 2;
	if (drawend >= cub->height) drawend = cub->height - 1;
	y = drawstart;
	texture_calcul(cub, drawstart, drawend);
	while (y < cub->height)
	{
		while (x < cub->width)
		{
			cub->addr[(int)(y * cub->width + x)] = cub->buffer[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
}


