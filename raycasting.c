/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:26:51 by hharit            #+#    #+#             */
/*   Updated: 2023/02/17 23:36:29 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wall_strip_height(t_cub3d *cub, double *wallstriph, double ray_angle)
{
	double	wall_distance;

	wall_distance = cub->ray.distance * cos(ray_angle - cub->angle);
	*wallstriph = round((TILE / wall_distance) * cub->dist_plane);
}

void	raycasting(t_cub3d *cub)
{
	double	wallheight;
	double	ray_angle;
	int		pixel;

	pixel = 0;
	while (pixel < WIDTH)
	{
		cub->ray.horizontal = false;
		cub->ray.vertical = false;
		ray_angle = cub->angle + atan((pixel - 0.5
					* WIDTH) / cub->dist_plane);
		ray_angle = normalize_angle(ray_angle);
		cast_ray(cub, ray_angle);
		wall_strip_height(cub, &wallheight, ray_angle);
		drawing_ray(cub, wallheight, pixel, tex_id(*cub, ray_angle));
		pixel++;
	}
}
