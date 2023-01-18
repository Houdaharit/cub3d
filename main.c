/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <hharit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 00:30:12 by hharit            #+#    #+#             */
/*   Updated: 2023/01/18 01:14:00 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(t_cub3d *cub, t_data map)
{
	cub->width = 400;
	cub->height = 400;
	cub->map = map.map;
	cub->posx = map.xPposition;
	cub->posy = map.yPposition;
	cub->dirx = -1;
	cub->diry = 0;
	cub->planex = 0;
	cub->planey = 0.66;
	cub->rotspeed = 0.4;
	cub->movespeed = 1.0;
	cub->win = mlx_new_window(cub->mlx, cub->width, cub->height, "cub3d");
	cub->img = mlx_new_image(cub->mlx, cub->width, cub->height);
	cub->addr = mlx_get_data_addr(cub->img, &(cub->bits_per_pixel),
			&(cub->line_length), &(cub->endian));

}

int	main(int argc, char **argv)
{
	t_cub3d	cub;
	t_data map;

	if (argc == 2)
	{
		valid_map(argv[1], &map);
		storecolores(&map);
	}
	else
	{
		printf("please enter a valid map only !\n");
		exit(1);
	}
	cub.mlx = mlx_init();
	init(&cub, map);
	mlx_loop_hook(cub.mlx, &raycasting, &cub);
	mlx_hook(cub.win, 2, 1L >> 0, moves, (void *)&cub);
	mlx_loop(cub.mlx);
}
