/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <hharit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 00:30:12 by hharit            #+#    #+#             */
/*   Updated: 2023/01/25 05:43:11 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

/*void	init_textures(t_cub3d *cub)
{
	int	j;
	int	i;
	int max;

	cub->tex_width = 340;
	cub->tex_height = 510;
	init_buffer(cub);
	cub->textures = (int**)malloc(sizeof(int*));
	cub->textures[0] = (int*)malloc(sizeof(int) * cub->tex_width * cub->tex_height);
	max = cub->tex_height * cub->tex_width;
	j = 0;
	while (j < max)
	{
		cub->textures[0][j] = 0;
		j++;
	}
	j = 0;
	while (j < cub->img_height)
	{
		i = 0;
		while (i < cub->img_width)
		{
			cub->textures[0][(int)cub->img_width * j + i] = cub->addr[(int)cub->img_width * j + i];
			i++;
		}
		j++;
	}
	cub->img = mlx_new_image(cub->mlx, cub->width, cub->height);
	cub->addr = (int *)mlx_get_data_addr(cub->img, &(cub->bits_per_pixel),
			&(cub->line_length), &(cub->endian));

}*/

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
	//	init_textures(&cub);
	raycasting(&cub);
	ceils(&cub);
	mlx_hook(cub.win, 2, 0, moves, (void *)&cub);
	mlx_loop(cub.mlx);
}
