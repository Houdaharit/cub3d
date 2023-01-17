/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <hharit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 00:30:12 by hharit            #+#    #+#             */
/*   Updated: 2023/01/17 03:35:58 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(t_cub3d *cub, t_data map)
{
	cub->width = 650;
	cub->height = 650;
	cub->map = map.map;
	cub->posx = map.xPposition;
	cub->posy = map.yPposition;
	cub->dirx = -1;
	cub->diry = 0;
	cub->planex = 0;
	cub->planey = 0.66;
	cub->win = mlx_new_window(cub->mlx, cub->width, cub->height, "cub3d");
	cub->img = mlx_new_image(cub->mlx, cub->width, cub->height);
	cub->addr = mlx_get_data_addr(cub->img, &(cub->bits_per_pixel),
			&(cub->line_length), &(cub->endian));

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
	cub->mlx = mlx_init();
	init(cub, map);
	raycasting(cub);
	mlx_hook(cub->win, 2, 1L >> 0, ft_close, (void *)cub);
	mlx_hook(cub->win, 17, 0, destroy, (void *)cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
	mlx_loop(cub->mlx);
}
