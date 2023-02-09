/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 01:37:12 by hharit            #+#    #+#             */
/*   Updated: 2023/02/09 16:20:21 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	normalize_angle(double angle)
{
	angle = fmod(angle, 2 * M_PI);
	if (angle < 0)
		angle += 2 * M_PI;
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
	inter->index_v = 0;
	inter->index_h = 0;
}


double	rotation_angle(char direction)
{
	if (direction == 'S')
		return (M_PI_2);
	else if (direction == 'N')
		return (1.5 * M_PI);
	else if (direction == 'E')
		return (0);
	return (M_PI);
}


void player_cordinates(t_cub3d *cube, char **map)
{
    cube->i = 0;
	while (map[cube->i])
	{
		cube->j = 0;
		while (map[cube->i][cube->j])
		{
			if (map[cube->i][cube->j] == 'N' || map[cube->i][cube->j] == 'S'
				|| map[cube->i][cube->j] == 'W' || map[cube->i][cube->j] == 'E')
				return ;
			cube->j++;
		}
		cube->i++;
	}
	exit(0);
}


void	init(t_cub3d *cub, t_data *map)
{
	player_cordinates(cub,map->map);
	cub->width = 1600;
	cub->height = 1000;
	cub->map_length = map->map_lenght * TILE;
	cub->map_width = map->data_lenght * TILE;
	cub->player_x = cub->j * TILE + TILE * 0.5;
	cub->player_y = cub->i * TILE + TILE * 0.5;	
	cub->angle = rotation_angle(map->map[cub->i][cub->j]);
	cub->mlx = mlx_init();
	cub->mlx_window = mlx_new_window(cub->mlx, WIDTH, HEIGHT, "cub3d");
	cub->dist_plane = (WIDTH * 0.5) / tan(M_PI / 6);
	cub->map = map->map;
	cub->fov_angle = 1.0471975512;
	rending(cub);
}
