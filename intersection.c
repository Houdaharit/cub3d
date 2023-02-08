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

int	check_grid(t_cub3d cub, int x, int y)
{
	int	grid_x;
	int	grid_y;

	if (x < 0 || x > cub.width || y < 0 || y > cub.height)
		return (2);
	grid_x = floor(x / cub.tile_size);
	grid_y = floor(y / cub.tile_size);
	return (cub.map[grid_y][grid_x] == '1');
}
