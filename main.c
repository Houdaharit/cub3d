/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <hharit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 00:30:12 by hharit            #+#    #+#             */
/*   Updated: 2023/02/07 23:54:12 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(t_cub3d *cub, t_data map)
{
    int img_width, img_height;
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
	cub->movespeed = 1.5;
	cub->win = mlx_new_window(cub->mlx, cub->width, cub->height, "cub3d");
   	cub->img = mlx_new_image(cub->mlx, cub->width, cub->height);
	cub->addr = (int *)mlx_get_data_addr(cub->img, &(cub->bits_per_pixel),
			&(cub->line_length), &(cub->endian));
    cub->player = mlx_xpm_file_to_image(cub->mlx, "./red.xpm", (int*)&cub->img_width_m, (int*)&cub->img_height_m);
    cub->minimap = mlx_xpm_file_to_image(cub->mlx, "./green.xpm", (int*)&img_width, (int*)&img_height);
	cub->walls = mlx_xpm_file_to_image(cub->mlx, "./greystone.xpm", (int*)&img_width, (int*)&img_height);
cub->addr1 = (int *)mlx_get_data_addr(cub->walls, &(cub->bits_per_pixel1),
			&(cub->line_length1), &(cub->endian1));
}

void	init_buffer(t_cub3d *cub)
{
	int	j;
	int	i;
	int	max;

	max = cub->height * cub->width;
	//cub->buffer = (int**)malloc(sizeof(int*) * cub->height);
	i = 0;
	while (i < cub->height)
	{
		//	cub->buffer[i] = (int*)malloc(sizeof(int) * cub->height * cub->width);
		j = 0;
		while (j < cub->width)
		{
			cub->buffer[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	init_textures(t_cub3d *cub)
{
	int	j;
	int max;

	cub->tex_width = 64;
	cub->tex_height = 64;
	cub->textures = (int**)malloc(sizeof(int*));
	cub->textures[0] = (int*)malloc(sizeof(int) * cub->tex_width * cub->tex_height);
	max = cub->tex_height * cub->tex_width;
	j = 0;
	while (j < max)
	{
		cub->textures[0][j] = 0;
		j++;
	}
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
	ceils(&cub);
	raycasting(&cub);
	mlx_hook(cub.win, 2, 0, moves, (void *)&cub);
	mlx_loop(cub.mlx);
}
