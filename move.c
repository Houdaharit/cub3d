/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 02:05:50 by hharit            #+#    #+#             */
/*   Updated: 2023/02/07 18:22:01 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move(int keycode, t_cub3d *cub)
{
	if (keycode == 53)
		destroy(cub);
	if (keycode == 124)
		cub->player.turn_dir = 1;
	if (keycode == 123)
		cub->player.turn_dir = -1;
	if (keycode == 126)
		cub->player.walk_dir = 1;
	if (keycode == 125)
		cub->player.walk_dir = -1;
	return (1);
}

int	key_release(int keycode, t_cub3d *cub)
{
	if (keycode == 124)
		cub->player.turn_dir = 0;
	if (keycode == 123)
		cub->player.turn_dir = 0;
	if (keycode == 126)
		cub->player.walk_dir = 0;
	if (keycode == 125)
		cub->player.walk_dir = 0;
	return (1);
}

bool	if_hit_wall(t_cub3d *cub, int x, int y)
{
	if (x < 0 || x > cub->width || y < 0 || y > cub->height)
		return (1);
	else
	{
		x = floor(x / cub->tile_size);
		y = floor(y / cub->tile_size);
		if (cub->map[y][x] == '1')
			return (1);
	}
	return (0);
}

int	move_player(t_cub3d *cub)
{
	double	step;
	double	next_x;
	double	next_y;

	cub->player.rot_angle += cub->player.turn_dir * cub->player.rotation_speed;
	step = cub->player.walk_dir* cub->player.move_speed;
	next_x = cub->player.posx + cos(cub->player.rot_angle) * step;
	next_y = cub->player.posy + sin(cub->player.rot_angle) * step;
	if (!if_hit_wall(cub, next_x, next_y))
	{
		cub->player.posx = next_x;
		cub->player.posy = next_y;
		cub->img = mlx_new_image(cub->mlx, cub->width, cub->height);
		cub->addr = mlx_get_data_addr(cub->img, &(cub->bits_per_pixel),
				&(cub->line_length), &(cub->endian));
	}
	return (1);
}
