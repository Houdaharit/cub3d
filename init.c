/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 01:37:12 by hharit            #+#    #+#             */
/*   Updated: 2023/02/01 04:13:26 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	normalize_angle(double angle)
{
	angle = fmod(angle, 2 * M_PI);
	if (angle < 0)
		angle += (2 * M_PI);
	return (angle);
}

void    default_inter(t_inter *inter)
{
    inter->x = 0;
    inter->y = 0;
    inter->stepx = 0;
    inter->stepy = 0;
    inter->horizontal = false;
    inter->vertical = false;
    inter->distance = 0;
}

void	init_window(t_mlx *mlx)
{
	mlx->width = 15 * 32;
	mlx->height = 34 * 32;
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, mlx->width, mlx->height, "cub3d");
	mlx->img = mlx_new_image(mlx->mlx, mlx->width, mlx->height);
	mlx->addr = mlx_get_data_addr(mlx->img, &(mlx->bits_per_pixel),
			&(mlx->line_length), &(mlx->endian));
}

double	rotation_angle(char direction)
{
	if (direction == 'N')
		return (M_PI / 2);
	else if (direction == 'S')
		return ((3 * M_PI) / 2);
	else if (direction == 'E')
		return (0);
	return (M_PI);
}

void	init_player(t_player *player, t_data map)
{
	player->posx = map.xPposition * 32;
	player->posy = map.yPposition * 32;
	player->face = map.direction;
	player->move_speed = 100.0;
	player->rotation_speed = 45 * (M_PI / 180);
	player->rot_angle = rotation_angle(player->face);
	player->turn_dir = 0;
	player->walk_dir = 0;
}

void	init_cub(t_cub3d *cub, t_data map)
{
	cub->map = map.map;
	cub->tile_size = 32;
	cub->fov_angle = 60 * (M_PI / 180);
}

void	init_ray(t_ray *ray)
{
	ray->vertical = false;
	ray->horizontal = false;
	ray->ray_angle = 0;
	ray->distance = 0;
	ray->wallx = 0;
	ray->wally = 0;
}

void	init(t_cub3d *cub, t_data map)
{
	init_window(&cub->mlx);
	init_cub(cub, map);
	init_player(&cub->player, map);
	init_ray(&cub->ray);
}
