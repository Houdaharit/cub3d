/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver_intersection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 00:19:46 by hharit            #+#    #+#             */
/*   Updated: 2023/02/07 18:17:25 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wallx_y_v(t_cub3d *cub, t_inter *inter)
{
	while (1)
	{
		if (inter->x >= 0 && inter->x <= cub->width
				&& inter->y >= 0 && inter->y <= cub->height)
		{
			if (check_grid(*cub, inter->x, inter->y + inter->index_v) == 1)
			{
				inter->vertical = true;
				break ;
			}
			else
			{
				inter->x += inter->stepx;
				inter->y += inter->stepy;
			}
			inter->wallx = inter->x;
			inter->wally = inter->y;
		}
		else
			break;
	}
	if (inter->vertical)
	{
		inter->distance = hypot(inter->wallx - cub->player.posx ,
				inter->wally - cub->player.posy);
	}
	if (!inter->distance)
		inter->distance = 1e30;
}

t_inter	v_first_inter(t_cub3d *cub)
{
	t_inter	inter;

	default_inter(&inter);
	inter.x = floor(cub->player.posx / cub->tile_size) * cub->tile_size;
	if (cub->ray.ray_angle < M_PI_2 || cub->ray.ray_angle > 3 * M_PI_2)
		inter.y += cub->tile_size;
	else
		inter.index_v = -1;
	inter.y = cub->player.posy + (inter.x - cub->player.posy)
		/ tan(cub->ray.ray_angle);
	return (inter);
}

t_inter	x_y_step_ver(t_cub3d *cub)
{
	t_inter	inter;

	default_inter(&inter);
	inter.stepx = cub->tile_size;
	if (!(cub->ray.ray_angle < M_PI_2 || cub->ray.ray_angle > 3 * M_PI_2))
		inter.stepx *= -1;
	inter.stepy = inter.stepx * tan(cub->ray.ray_angle);
	if (!(cub->ray.ray_angle > 0 && cub->ray.ray_angle < M_PI) && \
			inter.stepy > 0)
		inter.stepy *= -1;
	if (cub->ray.ray_angle > 0 && cub->ray.ray_angle < M_PI && inter.stepy < 0)
		inter.stepy *= -1;
	wallx_y_v(cub, &inter);
	return (inter);
}
