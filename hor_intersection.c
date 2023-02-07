/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hor_intersection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 23:35:52 by hharit            #+#    #+#             */
/*   Updated: 2023/02/07 18:17:23 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wallx_y_h(t_cub3d *cub, t_inter *inter)
{
	printf("HERE\n");
	while (inter->x >= 0 && inter->x <= cub->mlx.width
			&& inter->y >= 0 && inter->y <= cub->mlx.height)
	{
		if (check_grid(*cub, inter->x, inter->y, 'H'))
		{
			inter->horizontal = true;
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
	if (inter->horizontal)
	{
		inter->distance = hypot(inter->wallx - cub->player.posx,
				inter->wally - cub->player.posy);
		printf("distance h: %f\n", inter->distance);
	}
	if (!inter->distance)
		inter->distance = 1e30;
}

t_inter	hor_first_inter(t_cub3d *cub)
{
	t_inter	inter;

	default_inter(&inter);
	inter.y = floor(cub->player.posy / cub->tile_size) * cub->tile_size;
	if (cub->ray.ray_angle > 0 && cub->ray.ray_angle < M_PI)
		inter.y += cub->tile_size;
	inter.x = cub->player.posx + (inter.y - cub->player.posy)
		/ tan(cub->ray.ray_angle);
	return (inter);
}

t_inter	x_y_step_hor(t_cub3d *cub)
{
	t_inter	inter;

	inter = hor_first_inter(cub);
	inter.stepy = cub->tile_size;
	if (!(cub->ray.ray_angle > 0 && cub->ray.ray_angle < M_PI))
		inter.stepy *= -1;
	inter.stepx = inter.stepy / tan(cub->ray.ray_angle);
	if (((cub->ray.ray_angle < M_PI_2 || cub->ray.ray_angle > 3 * M_PI_2)
				&& inter.stepx < 0))
		inter.stepy *= -1;
	if (!(cub->ray.ray_angle < M_PI_2
				|| cub->ray.ray_angle > 3 * M_PI_2) && inter.stepx > 0)
		inter.stepy *= -1;
	wallx_y_h(cub, &inter);
	return (inter);
}
