/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 01:37:12 by hharit            #+#    #+#             */
/*   Updated: 2023/01/27 10:23:34 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    default_inter(t_inter *inter)
{
    inter->x = 0;
    inter->y = 0;
    inter->stepx = 0;
    inter->stepy = 0;
    inter->horizontal = false;
    inter->vertical = false;
    inter->distance = -1;
}

void	init_window(t_mlx *mlx)
{
	mlx->width = 800;
	mlx->height = 800;
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, mlx->width, mlx->height, "cub3d");
}

void	init_player(t_player *player, t_data map)
{
	player->posx = map.xPposition;
	player->posy = map.yPposition;
	player->face = map.direction;
	player->move_speed = 1.0;
	player->rotation_speed = 2 * (M_PI / 180);
	player->rot_angle = M_PI / 2;
	player->turn_dir = 0;
	player->walk_dir = 0;
}

void	init_cub(t_cub3d *cub, t_data map)
{
	cub->map = map.map;
	cub->tile_size = 64;
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
