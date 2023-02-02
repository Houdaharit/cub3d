/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:26:51 by hharit            #+#    #+#             */
/*   Updated: 2023/02/01 03:13:39 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast_ray(t_cub3d *cub)
{
	t_inter inter_v;
	t_inter	inter_h;

	inter_h = x_y_step_hor(cub);
	inter_v = x_y_step_ver(cub);
	if (inter_v.distance < inter_h.distance)
	{
		cub->ray.vertical = true;
		cub->ray.distance = inter_v.distance;
	}
	else
	{
		cub->ray.horizontal = true;
		cub->ray.distance = inter_h.distance;
	}
}

void	raycasting(t_cub3d *cub)
{
	float	i;
	//	float	distance_plane;

	i = 0;

	//	distance_plane = (cub->mlx.width / 2) / tan(cub->fov_angle / 2);
	cub->ray.ray_angle = cub->player.rot_angle - (cub->fov_angle / 2);
	while (i < cub->mlx.width)
	{
		//cub->ray.ray_angle = cub->player.rot_angle + atan((i - (cub->mlx.width / 2)) / distance_plane);
		cub->ray.ray_angle = normalize_angle(cub->ray.ray_angle);
		cast_ray(cub);
		draw(cub, i);
		i++;
		cub->ray.ray_angle += cub->fov_angle / cub->mlx.width; 
	}
}
