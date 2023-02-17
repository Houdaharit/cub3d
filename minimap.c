/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 04:58:17 by ahakam            #+#    #+#             */
/*   Updated: 2023/02/17 18:06:45 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_minimap(t_cub3d *cub)
{
	cub->mini_j = 0;
	cub->mini_y = 0;
	cub->play_xpm = mlx_xpm_file_to_image(cub->mlx, "./textures/red.xpm",
			(int *)&cub->mini_width, (int *)&cub->mini_height);
	cub->walls_xpm = mlx_xpm_file_to_image(cub->mlx, "./textures/black.xpm",
			(int *)&cub->mini_width, (int *)&cub->mini_height);
	if (!cub->play_xpm || !cub->walls_xpm)
	{
		write(2, "Error\nAccess to texture denied!\n", 33);
		exit(1);
	}
}

void	minimap(t_cub3d *cub)
{
	init_minimap(cub);
	while (cub->map[cub->mini_j] != NULL)
	{
		cub->mini_i = 0;
		cub->mini_x = 0;
		while (cub->map[cub->mini_j][cub->mini_i])
		{
			if (cub->map[cub->mini_j][cub->mini_i] == '1')
				mlx_put_image_to_window(cub->mlx, cub->mlx_window,
					cub->walls_xpm, cub->mini_x, cub->mini_y);
			if (cub->mini_i == floor(cub->player_x / TILE) && \
					cub->mini_j == floor(cub->player_y / TILE))
				mlx_put_image_to_window(cub->mlx, cub->mlx_window,
					cub->play_xpm, cub->mini_x, cub->mini_y);
			cub->mini_x += cub->mini_width;
			cub->mini_i++;
		}
		cub->mini_j++;
		cub->mini_y += cub->mini_height;
	}
}
