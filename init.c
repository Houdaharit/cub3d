/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 01:37:12 by hharit            #+#    #+#             */
/*   Updated: 2023/01/27 05:08:53 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_window(t_mlx *mlx)
{
	mlx->width = 800;
	mlx->heiht = 800;
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, mlx->width, mlx->height, "cub3d");
}

void	init_player(t_player *player, t_data map)
{
	player->posx = map.xPposition;
	player->posy = map.yPposition;
	player->move_speed = 1.0;
	player->rotation_speed = 2 * (M_PI / 180);
	player->rot_angle = M_PI / 2;
	player->turn_dir = 0;
	player->walk_dir = 0;
	player->face = map.direction;
}

void	init_cub(t_cub3d *cub)
{
	cub->map = map.map;
	cub->tile_size = 64;
	cub->fov_angle = 60 * (M_PI / 180);
}

void	init(t_cub3d *cub, t_data map)
{
	init_window(&cub.mlx);
	init_cub(cub);
	init_player(&cub.player, map);
	init_cub(cub);
}
