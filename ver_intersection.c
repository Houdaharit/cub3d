/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver_intersection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 00:19:46 by hharit            #+#    #+#             */
/*   Updated: 2023/02/12 20:11:09 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	v_first_inter(t_cub3d *cub, double ray_ang, t_inter *inter)
{
	inter->x = floor(cub->player_x / TILE) * TILE;
	if (ray_ang < M_PI_2 || ray_ang > 1.5 * M_PI)
		inter->x += TILE;
	else
		inter->index = -1;
	inter->y = cub->player_y + (inter->x - cub->player_x) * tan(ray_ang);
}

void	wallx_y_v(t_cub3d *cub, t_inter *inter)
{
	while (1)
	{
		if (inter->x > 0 && inter->y > 0 && inter->x
			< cub->map_width && inter->stepy < cub->map_length)
		{
			if (check_grid(cub, inter->x + inter->index, inter->y, 0) == 1)
			{
				inter->vertical = true;
				break ;
			}
			inter->x += inter->stepx;
			inter->y += inter->stepy;
		}
		else
			break ;
	}
}

void	x_y_step_ver(t_cub3d *cub, double ray_ang, t_inter	*inter)
{
	default_inter(inter);
	v_first_inter(cub, ray_ang, inter);
	inter->stepx = TILE;
	if (!(ray_ang < M_PI_2 || ray_ang > 1.5 * M_PI))
		inter->stepx *= -1;
	inter->stepy = 64 * tan(ray_ang);
	if ((!(ray_ang > 0 && ray_ang < M_PI) && inter->stepy > 0)
		|| ((ray_ang > 0 && ray_ang < M_PI) && inter->stepy < 0))
		inter->stepy *= -1;
	wallx_y_v(cub, inter);
}
