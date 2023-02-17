/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 02:05:50 by hharit            #+#    #+#             */
/*   Updated: 2023/02/12 23:39:32 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_for(t_cub3d *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player_x + SPEED * cos(game->angle);
	new_y = game->player_y + SPEED * sin(game->angle);
	if (check_grid(game, new_x, new_y, 1) != 1)
	{
		game->player_x = new_x;
		game->player_y = new_y;
		update(game);
	}
}

void	move_back(t_cub3d *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player_x - SPEED * cos(game->angle);
	new_y = game->player_y - SPEED * sin(game->angle);
	if (check_grid(game, new_x, new_y, 1) != 1)
	{
		game->player_x = new_x;
		game->player_y = new_y;
		update(game);
	}
}

void	move_left(t_cub3d *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player_x + SPEED * cos(normalize_angle(game->angle - M_PI_2));
	new_y = game->player_y + SPEED * sin(normalize_angle(game->angle - M_PI_2));
	if (check_grid(game, new_x, new_y, 1) != 1)
	{
		game->player_x = new_x;
		game->player_y = new_y;
		update(game);
	}
}

void	move_right(t_cub3d *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player_x + SPEED * cos(normalize_angle(game->angle + M_PI_2));
	new_y = game->player_y + SPEED * sin(normalize_angle(game->angle + M_PI_2));
	if (check_grid(game, new_x, new_y, 1) != 1)
	{
		game->player_x = new_x;
		game->player_y = new_y;
		update(game);
	}
}
