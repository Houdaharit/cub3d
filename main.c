/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <hharit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 00:30:12 by hharit            #+#    #+#             */
/*   Updated: 2023/01/23 03:48:11 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(t_cub3d *cub, t_data map)
{
	cub->width = 800;
	cub->height = 800;
	cub->map = map.map;
	cub->posx = map.xPposition;
	cub->posy = map.yPposition;
	cub->dirx = -1;
	cub->diry = 0;
	cub->planex = 0;
	cub->planey = 0.66;
	cub->rotspeed = 0.8;
	cub->movespeed = 1.0;
	cub->win = mlx_new_window(cub->mlx, cub->width, cub->height, "cub3d");
}

void	init_textures(t_cub3d *cub)
{
	int	y = 0;
	int x = 0;
	//calloc
	cub->buffer = (int**)calloc(64 * 64, sizeof(int*));
	cub->textures = (int**)calloc(1, sizeof(int*));
	cub->img = mlx_xpm_file_to_image(cub->mlx, "./zellige.xpm" , (int*)&cub->width, (int*)&cub->height);
	cub->addr = (int *)mlx_get_data_addr(cub->img, &(cub->bits_per_pixel),
			&(cub->line_length), &(cub->endian));
	while (y < cub->height)
	{
		x = 0;
		while(x < cub->width)
		{
			cub->textures[(int)cub->width * y + x] = &cub->addr[(int)cub->width * y + x];
			x++;
			printf("here\n");
		}
		y++;
	}
	mlx_destroy_image(cub->mlx, cub->img);
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
	init_textures(&cub);
	mlx_loop_hook(cub.mlx, &raycasting, &cub);
	mlx_hook(cub.win, 2, 1L >> 0, moves, (void *)&cub);
	mlx_loop(cub.mlx);
}
