/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floorAndCellings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 04:23:14 by ahakam            #+#    #+#             */
/*   Updated: 2023/02/12 20:07:12 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	floor_and_cellings(t_cub3d *cub)
{
	int	i;
	int	j;
	int	end_ceilling;

	i = 0;
	end_ceilling = HEIGHT / 2;
	while (i < end_ceilling)
	{
		j = 0;
		while (j < WIDTH)
			my_mlx_pixel_put(cub, j++, i, cub->ceilling);
		i++;
	}
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
			my_mlx_pixel_put(cub, j++, i, cub->floors);
		i++;
	}
}
