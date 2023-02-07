/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 05:10:03 by hharit            #+#    #+#             */
/*   Updated: 2023/02/07 18:17:37 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_grid(t_cub3d cub, int x, int y, char dir)
{
	int	grid_x;
	int	grid_y;

	if (dir == 'H' && (!(cub.ray.ray_angle > 0 && cub.ray.ray_angle < M_PI)))
		y--;
	else if (dir == 'V' && (!(cub.ray.ray_angle < 0.5 * M_PI || cub.ray.ray_angle > (1.5 * M_PI))))
		x--;
	if (x < 0 || x > cub.mlx.width || y < 0 || y > cub.mlx.height)
		return (1);
	grid_x = floor(x / cub.tile_size);
	grid_y = floor(y / cub.tile_size);
	return (cub.map[grid_y][grid_x] == '1');
}
