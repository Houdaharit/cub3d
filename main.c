/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <hharit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 00:30:12 by hharit            #+#    #+#             */
/*   Updated: 2023/01/25 07:32:06 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	raycasting(&cub);
	ceils(&cub);
	mlx_hook(cub.win, 2, 0, moves, (void *)&cub);
	mlx_loop(cub.mlx);
}
