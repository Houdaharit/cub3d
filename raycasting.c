/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:26:51 by hharit            #+#    #+#             */
/*   Updated: 2023/02/09 16:19:35 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast_ray(t_cub3d *cub, double angle)
{
	double	d_ver;
	double	d_hor;
	t_inter	inter_h;
	t_inter	inter_v;

	angle = normalize_angle(angle);
	x_y_step_hor(cub, angle, &inter_h);
	x_y_step_ver(cub, angle, &inter_v);
	d_ver = hypot(cub->player_x - inter_v.x,         
			cub->player_y - inter_v.y);
	d_hor = hypot(cub->player_x - inter_h.x,
			cub->player_y - inter_h.y);
	if (d_hor > d_ver)
	{
		cub->ray.horizontal = true;
		cub->ray.inter_x = inter_v.x;
		cub->ray.inter_y = inter_v.y;
		cub->ray.distance =  hypot(cub->player_x - cub->ray.inter_x,
				cub->player_y - cub->ray.inter_y);
	}
	else
	{
		cub->ray.vertical = true;
		cub->ray.inter_x = inter_h.x;
		cub->ray.inter_y = inter_h.y;
		cub->ray.distance =  hypot(cub->player_x - cub->ray.inter_x,
				cub->player_y - cub->ray.inter_y);

	}
}
void	wall_strip_height(t_cub3d *cub, double *wallstripheight, double ray_angle)
{
	double	wall_distance;

	wall_distance =	 cub->ray.distance * cos(ray_angle - cub->angle);
	*wallstripheight = round((TILE / wall_distance) * cub->dist_plane);
}

void	raycasting(t_cub3d *cub)
{
	double	wallheight;
	double	ray_angle;
	int	pixel;

	pixel = 0;
	ray_angle = cub->angle - (cub->fov_angle * 0.5);
	while (pixel < WIDTH)
	{
		cast_ray(cub, ray_angle);
		wall_strip_height(cub, &wallheight, ray_angle);
		drawing_ray(cub, wallheight, pixel, 0);
		ray_angle += cub->fov_angle / WIDTH;
		pixel++;
	}
}
