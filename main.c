/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <hharit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 05:41:50 by ahakam            #+#    #+#             */
/*   Updated: 2023/02/12 23:43:11 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cub3d	*cub;
	t_data	*map;

	map = NULL;
	if (argc == 2)
	{
		if (ft_strcmp(ft_strchr(argv[1], '.'), ".cub"))
		{
			write(2, "Error!\ninvalid file!\n", 22);
			exit(1);
		}
		map = valid_map(argv[1], map);
		storecolores(map);
	}
	else
	{
		printf("please enter a valid map only!\n");
		exit(1);
	}
	cub = malloc(sizeof(t_cub3d));
	init(cub, map);
	mlx_hook(cub->mlx_window, 2, 0, key_hook, (void *)cub);
	mlx_hook(cub->mlx_window, 17, 0, destroy, (void *)cub);
	mlx_mouse_hook(cub->mlx_window, mouse_hook, (void *)cub);
	mlx_loop(cub->mlx);
}
