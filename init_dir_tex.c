/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dir_tex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 04:20:52 by hharit            #+#    #+#             */
/*   Updated: 2023/01/25 04:37:13 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_north_west(t_cub3d *cub)
{
	if (cub->direction == 'N')
	{
		cub->dirx = 0;
		cub->diry = -1;
		cub->planex = -0.66;
		cub->planey = 0;
	}
	if (cub->direction == 'W')
	{
		cub->dirx = -1;
		cub->diry = 0;
		cub->planex = 0;
		cub->planey = 0.66;
	}
}

void	init_south_east(t_cub3d *cub)
{
	if (cub->direction == 'E')
	{
		cub->dirx = 1;
		cub->diry = 0;
		cub->planex = 0;
		cub->planey = 0.66;
	}
	if (cub->direction == 'S')
	{
		cub->dirx = 0;
		cub->diry = 1;
		cub->planex = 0.66;
		cub->planey = 0;
	}
}
