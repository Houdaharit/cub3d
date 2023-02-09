/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:26:51 by hharit            #+#    #+#             */
/*   Updated: 2023/02/09 08:02:10 by ahakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast_ray(t_cub3d *cub, double ang, t_inter *inter_h, t_inter *inter_v)
{
	double ray_ang;
	double	d_ver;
	double	d_hor;

	ray_ang = normalize_angle(ang);
	x_y_step_hor(cub,ray_ang, inter_h);
	x_y_step_ver(cub,ray_ang, inter_v);
	d_ver = hypot(cub->player_x - inter_v->x,         
			cub->player_y - inter_v->y);
	d_hor = hypot(cub->player_x - inter_h->x,
			cub->player_y - inter_h->y);
	if (d_hor > d_ver)
	{
		cub->ray.horizontal = true;
		cub->inter_x = inter_v->x;
		cub->inter_y = inter_v->y;
		cub->ray.distance =  hypot(cub->player_x - cub->inter_x,
				cub->player_y - cub->inter_y);
	}
	else
	{
		cub->ray.vertical = true;
		cub->inter_x = inter_h->x;
		cub->inter_y = inter_h->y;
		cub->ray.distance =  hypot(cub->player_x - cub->inter_x,
				cub->player_y - cub->inter_y);

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
	int		i;
	double	wallheight;
	t_inter inter_h ;
	t_inter inter_v ;
	double	ray_angle;

	i = 0;
	while (i < WIDTH)
	{
		ray_angle = cub->angle + atan((i - 0.5 * WIDTH) / cub->dist_plane);
		cast_ray(cub, ray_angle, &inter_h, &inter_v);
		wall_strip_height(cub, &wallheight, ray_angle);
		drawing_ray(cub,wallheight, i);
		i++;
	}
}
