/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hor_intersection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 23:35:52 by hharit            #+#    #+#             */
/*   Updated: 2023/02/12 20:11:44 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wallx_y_h(t_cub3d *cub, t_inter *inter)
{
	while (1)
	{
		if (inter->x > 0 && inter->y > 0 && inter->x
			< cub->map_width && inter->y < cub->map_length)
		{
			if (check_grid(cub, inter->x, inter->y + inter->index, 0) == 1)
			{
				inter->horizontal = true;
				break ;
			}
			inter->x += inter->stepx;
			inter->y += inter->stepy;
		}
		else
			break ;
	}
}

void	hor_first_inter(t_cub3d *cub, double ray_ang, t_inter*inter)
{	
	inter->y = floor(cub->player_y / TILE) * TILE;
	if (ray_ang > 0 && ray_ang < M_PI)
		inter->y += TILE;
	else
		inter->index = -1;
	inter->x = cub->player_x + (inter->y - cub->player_y)
		/ tan(ray_ang);
}

void	x_y_step_hor(t_cub3d *cub, double ray_ang, t_inter	*inter)
{
	default_inter(inter);
	hor_first_inter(cub, ray_ang, inter);
	inter->stepy = TILE;
	if (!(ray_ang > 0 && ray_ang < M_PI))
		inter->stepy *= -1;
	inter->stepx = TILE / tan(ray_ang);
	if ((!(ray_ang < M_PI_2 || ray_ang > 1.5 * M_PI) \
				&& inter->stepx > 0))
		inter->stepx *= -1;
	if ((ray_ang < M_PI_2
			|| ray_ang > 3 * M_PI_2) && inter->stepx < 0)
		inter->stepx *= -1;
	wallx_y_h(cub, inter);
}
