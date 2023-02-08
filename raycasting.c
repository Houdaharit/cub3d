/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:26:51 by hharit            #+#    #+#             */
/*   Updated: 2023/02/07 17:56:11 by hharit           ###   ########.fr       */
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
		cub->ray.wallx = inter_v.wallx;
		cub->ray.wally  = inter_v.wally;
	}
	else
	{
		cub->ray.horizontal = true;
		cub->ray.distance = inter_h.distance;
		cub->ray.wallx = inter_h.wallx;
		cub->ray.wally  = inter_h.wally;

	}
}

void	raycasting(t_cub3d *cub)
{
	int	i;

	i = 0;
	cub->ray.ray_angle = cub->player.rot_angle - (cub->fov_angle / 2);
	while (i < cub->mlx.width)
	{
	//	printf("i: %d\n", i);
		cub->ray.ray_angle = normalize_angle(cub->ray.ray_angle);
		cast_ray(cub);
		draw(cub, i);
		i++;
		cub->ray.ray_angle += cub->fov_angle / cub->mlx.width; 
	}
}
