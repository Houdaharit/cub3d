/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 00:30:12 by hharit            #+#    #+#             */
/*   Updated: 2023/02/09 07:38:29 by ahakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	update(t_cub3d *cub)
{
	mlx_destroy_image(cub->mlx,cub->img);
	rending(cub);
	mlx_put_image_to_window(cub->mlx, cub->mlx_window, cub->img, 0, 0);
	return (1);
}

int	key_hook(int keycode, t_cub3d *game)
{
	if (keycode == 53)
		destroy(game);
	else if (keycode == 123)
	{
		game->angle = normalize_angle(game->angle - ROT_SPEED);
		update(game);
	}
	else if (keycode == 124)
	{
		game->angle = normalize_angle(game->angle + ROT_SPEED);
		update(game);
	}
	else if (keycode == 126 || keycode == 13)
		move_for(game);
	else if (keycode == 125 || keycode == 1)
		move_back(game);
	else if (keycode == 0)
		move_left(game);
	else if (keycode == 2)
		move_right(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_cub3d	*cub;
	t_data *map;

	if (argc == 2)
	{
		
		map = valid_map(argv[1]);
		storecolores(map);
	}
	else
	{
		printf("please enter a valid map only !\n");
		exit(1);
	}
	cub = malloc(sizeof(t_cub3d));
	init(cub,map);
	mlx_hook(cub->mlx_window, 2, 0, key_hook, (void *)cub);
	mlx_hook(cub->mlx_window, 17, 0, destroy, (void*)cub);
	mlx_loop(cub->mlx);
}

