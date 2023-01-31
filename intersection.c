/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 05:10:03 by hharit            #+#    #+#             */
/*   Updated: 2023/01/31 23:52:05 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_grid(t_cub3d cub, int x, int y, char dir)
{
	int	grid_x;
	int	grid_y;

	if (dir == 'H')
	{
		if (!(cub.ray.ray_angle > 0 && cub.ray.ray_angle < M_PI))
			y -= 1;
	}
	else if (dir == 'V')
	{
		if (!(cub.ray.ray_angle < M_PI_2 || cub.ray.ray_angle < (1.5 * M_PI)))
			x -= 1;
	}
	if (x < 0 || x > cub.mlx.width || y < 0 || y > cub.mlx.height)
		return (0);
	grid_x = floor(x / cub.tile_size);
	grid_y = floor(y / cub.tile_size);
	return (cub.map[grid_x][grid_y] == '1');
}

void	wallx_y_h(t_cub3d *cub, t_inter *inter)
{
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
		inter->distance = hypot(cub->player.posx - inter->wallx,
				cub->player.posy - inter->wally);
	if (!inter->distance)
		inter->distance = 1e30;
}

void	wallx_y_v(t_cub3d *cub, t_inter *inter)
{
	while (inter->x >= 0 && inter->x <= cub->mlx.width
		&& inter->y >= 0 && inter->y <= cub->mlx.height)
	{
		if (check_grid(*cub, inter->x, inter->y, 'V'))
		{
			inter->vertical = true;
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
	if (inter->vertical)
		inter->distance = hypot(cub->player.posx - inter->wallx,
				cub->player.posy - inter->wally);
	if (!inter->distance)
		inter->distance = 1e30;
}

t_inter	v_intersection(t_cub3d *cub)
{
	t_inter	inter;

	default_inter(&inter);
	inter.x = floor(cub->player.posx / cub->tile_size) * cub->tile_size;
	if (cub->ray.ray_angle < M_PI_2 || cub->ray.ray_angle > (1.5 * M_PI))
		inter.x += cub->tile_size;
	inter.y = cub->player.posy + (inter.y - cub->player.posy)
		/ tan(cub->ray.ray_angle);
	inter.stepx = cub->tile_size;
	if (!(cub->ray.ray_angle < M_PI_2 || cub->ray.ray_angle > (1.5 * M_PI)))
		inter.stepx *= -1;
	inter.stepy = cub->tile_size * tan(cub->ray.ray_angle);
	if (!(cub->ray.ray_angle > 0 && cub->ray.ray_angle < M_PI) && \
			inter.stepy > 0)
		inter.stepy *= -1;
	if (cub->ray.ray_angle > 0 && cub->ray.ray_angle < M_PI && inter.stepy < 0)
		inter.stepy *= -1;
/*	if (!(cub->ray.ray_angle > 0 && cub->ray.ray_angle < M_PI))
		inter.y--;*/
	wallx_y_v(cub, &inter);
	return (inter);
}

t_inter	h_intersection(t_cub3d *cub)
{
	t_inter	inter;

	default_inter(&inter);
	inter.y = floor(cub->player.posy / cub->tile_size) * cub->tile_size;
	if (cub->ray.ray_angle > 0 && cub->ray.ray_angle < M_PI)
		inter.y += cub->tile_size;
	inter.x = cub->player.posx + (inter.y - cub->player.posy)
		/ tan(cub->ray.ray_angle);
	inter.stepy = cub->tile_size;
	if (!(cub->ray.ray_angle > 0 && cub->ray.ray_angle < M_PI))
		inter.stepy *= -1;
	inter.stepx = cub->tile_size / tan(cub->ray.ray_angle);
	if (!(cub->ray.ray_angle < M_PI_2 || cub->ray.ray_angle > (3 * M_PI_2)) && inter.stepx > 0)
		inter.stepx *= -1;
	if ((cub->ray.ray_angle < M_PI_2 || cub->ray.ray_angle > (3 * M_PI_2)) && inter.stepx < 0)
		inter.stepx *= -1;
	if (!(cub->ray.ray_angle > 0 && cub->ray.ray_angle < M_PI))
		inter.y--;
	wallx_y_h(cub, &inter);
	return (inter);
}
