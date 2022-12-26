/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 00:30:12 by hharit            #+#    #+#             */
/*   Updated: 2022/12/26 16:26:39 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(t_cub3d *cub)
{
	cub = (t_cub3d *)malloc(sizeof(t_cub3d));
	cub->mlx = mlx_init();
	cub->win = mlx_new_window(cub, 800, 800, "cub3d");
	cub->posx = 22;
	cub->posy = 12;
	cub->dirx = -1;
	cub->diry = 0;
	cub->planex = 0;
	cub->planey = 0.66;
}

int	main(void)
{
	t_cub3d	*cub;

	init(cub);
	raycasting(cub);
	mlx_hook(cub->win, 2, 1L >> 0, ft_close, (void *)cub);
	mlx_hook(cub->win, 17, 0, destroy, (void *)cub);
	mlx_loop(cub->mlx);
}
