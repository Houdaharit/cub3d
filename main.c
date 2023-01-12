/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <hharit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 00:30:12 by hharit            #+#    #+#             */
/*   Updated: 2023/01/12 23:30:09 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(t_cub3d *cub, t_data map)
{
	cub->mlx = mlx_init();
	cub->width = 800;
	cub->height = 800;
	cub->win = mlx_new_window(cub, cub->width, cub->height, "cub3d");
	cub->map = map.map;
	cub->posx = map.xPposition;
	cub->posy = map.yPposition;
	cub->dirx = -1;
	cub->diry = 0;
	cub->planex = 0;
	cub->planey = 0.66;
}

int	main(int argc, char **argv)
{
	t_cub3d	*cub;
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
	cub = (t_cub3d *)malloc(sizeof(t_cub3d));
	init(cub, map);
	printf("%c\n", cub->map[(int)cub->posx][(int)cub->posy]);
	raycasting(cub, map.map);
	mlx_hook(cub->win, 2, 1L >> 0, ft_close, (void *)cub);
	mlx_hook(cub->win, 17, 0, destroy, (void *)cub);
	mlx_loop(cub->mlx);
}
