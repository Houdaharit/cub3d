/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <hharit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 00:30:12 by hharit            #+#    #+#             */
/*   Updated: 2023/01/27 11:11:58 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	update(int keycode, t_cub3d *cub)
{
	move(keycode, cub);
	move_player(cub);
	raycasting(cub);
	return (1);
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
	init(&cub, map);
	mlx_hook(cub.mlx.win, 2, 0, update, (void *)&cub);
	mlx_hook(cub.mlx.win, 3, 0, key_release, (void*)&cub);
	mlx_hook(cub.mlx.win, 17, 0, destroy, (void*)&cub);
	mlx_loop(cub.mlx.mlx);
}
