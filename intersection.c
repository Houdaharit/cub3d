/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 05:10:03 by hharit            #+#    #+#             */
/*   Updated: 2023/02/12 23:26:52 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_grid(t_cub3d *cub, double x, double y, int moving)
{
	int	grid_x;
	int	grid_y;

	if (x < 0 || x > cub->map_width || y < 0 || y > cub->map_length)
		return (-1);
	grid_x = floor(y / TILE);
	grid_y = floor(x / TILE);
	if (moving)
	{
		if (check_grid(cub, x, cub->player_y, 0) == 1)
			return (1);
		if (check_grid(cub, cub->player_x, y, 0) == 1)
			return (1);
	}
	return (cub->map[(int)grid_x][(int)grid_y] == '1');
}
