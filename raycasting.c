/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:26:51 by hharit            #+#    #+#             */
/*   Updated: 2022/12/26 16:33:55 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(t_cub3d *cub)
{
	int x = 0;
	double cameraX;

	while (x <= 800)
	{
		cameraX = 2 * x / 800  - 1;
		cub->raydirX = cub->dirx + cub->planex * cameraX;
		cub->raydirY = cub->diry + cub->planey * cameraX;
	}
}

