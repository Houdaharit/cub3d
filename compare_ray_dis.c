/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_ray_dis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 04:33:26 by ahakam            #+#    #+#             */
/*   Updated: 2023/02/12 20:09:36 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ray_out_of_range(t_cub3d *cub, t_inter inter_v, t_inter inter_h)
{
	if (inter_v.vertical == false)
	{
		cub->ray.horizontal = true;
		cub->ray.inter_x = inter_h.x;
		cub->ray.inter_y = inter_h.y;
		cub->ray.distance = hypot(cub->player_x - cub->ray.inter_x,
				cub->player_y - cub->ray.inter_y);
		return (1);
	}
	else if (inter_h.horizontal == false)
	{
		cub->ray.vertical = true;
		cub->ray.inter_x = inter_v.x;
		cub->ray.inter_y = inter_v.y;
		cub->ray.distance = hypot(cub->player_x - cub->ray.inter_x,
				cub->player_y - cub->ray.inter_y);
		return (1);
	}
	return (0);
}

void	hor_dis(t_cub3d *cub, t_inter inter_h)
{
	cub->ray.horizontal = true;
	cub->ray.inter_x = inter_h.x;
	cub->ray.inter_y = inter_h.y;
	cub->ray.distance = hypot(cub->player_x - cub->ray.inter_x,
			cub->player_y - cub->ray.inter_y);
}

void	ver_dis(t_cub3d *cub, t_inter inter_v)
{
	cub->ray.vertical = true;
	cub->ray.inter_x = inter_v.x;
	cub->ray.inter_y = inter_v.y;
	cub->ray.distance = hypot(cub->player_x - cub->ray.inter_x,
			cub->player_y - cub->ray.inter_y);
}

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
	if (ray_out_of_range(cub, inter_v, inter_h))
		return ;
	if (d_hor > d_ver)
		ver_dis(cub, inter_v);
	else if (d_hor < d_ver)
		hor_dis(cub, inter_h);
}
