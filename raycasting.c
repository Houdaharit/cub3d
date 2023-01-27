/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:26:51 by hharit            #+#    #+#             */
/*   Updated: 2023/01/27 10:26:37 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast_ray(t_cub3d *cub)
{
	t_inter inter_v;
	t_inter	inter_h;

	inter_h = h_intersection(cub);
	inter_v = v_intersection(cub);
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
	int	i;

	i = 0;
	cub->ray.ray_angle = cub->player.rot_angle - (cub->fov_angle / 2);
	while (i < cub->mlx.width)
	{
		cast_ray(cub);
		i += cub->fov_angle / cub->mlx.width;
	}
}
