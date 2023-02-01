/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver_intersection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 00:19:46 by hharit            #+#    #+#             */
/*   Updated: 2023/02/01 04:09:50 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wallx_y_v(t_cub3d *cub, t_inter *inter)
{
	while (inter->x >= 0 && inter->x <= cub->mlx.width
		&& inter->y >= 0 && inter->y <= cub->mlx.height)
	{
		if (check_grid(*cub, inter->x, inter->y, 'V'))
		{
			inter->vertical = true;
			inter->wallx = inter->x;
			inter->wally = inter->y;
			break ;
		}
		else
		{
			inter->x += inter->stepx;
			inter->y += inter->stepy;
		}
	}
	if (inter->vertical)
		inter->distance = hypot(cub->player.posx - inter->wallx,
				cub->player.posy - inter->wally);
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
