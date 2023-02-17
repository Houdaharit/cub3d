/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 03:59:56 by ahakam            #+#    #+#             */
/*   Updated: 2023/02/12 14:08:57 by ahakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	update(t_cub3d *cub)
{
	mlx_destroy_image(cub->mlx, cub->img);
	rending(cub);
	return (1);
}

int	mouse_hook(int move, int x, int y, t_cub3d *cub)
{
	x = 0;
	y = 0;
	if (move == 1)
	{
		cub->angle = normalize_angle(cub->angle - ROT_SPEED);
		update(cub);
	}
	else if (move == 2)
	{
		cub->angle = normalize_angle(cub->angle + ROT_SPEED);
		update(cub);
	}
	return (0);
}

int	key_hook(int keycode, t_cub3d *cub)
{
	if (keycode == 53)
		destroy(cub);
	else if (keycode == 123)
	{
		cub->angle = normalize_angle(cub->angle - ROT_SPEED);
		update(cub);
	}
	else if (keycode == 124)
	{
		cub->angle = normalize_angle(cub->angle + ROT_SPEED);
		update(cub);
	}
	else if (keycode == 126 || keycode == 13)
		move_for(cub);
	else if (keycode == 125 || keycode == 1)
		move_back(cub);
	else if (keycode == 0)
		move_left(cub);
	else if (keycode == 2)
		move_right(cub);
	return (0);
}
