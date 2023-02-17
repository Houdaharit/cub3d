/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <hharit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 04:43:53 by ahakam            #+#    #+#             */
/*   Updated: 2023/02/17 18:06:10 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_img(void *mlx, t_texture *texture, char *file)
{
	texture->img = mlx_xpm_file_to_image(mlx, file,
			&texture->width, &texture->height);
	if (!texture->img)
	{
		write(2, "Error!\nAccess to texture denied!\n", 33);
		exit(1);
	}
	texture->addr_ = mlx_get_data_addr(texture->img,
			&texture->bits_per_pixel, &texture->line_length, &texture->endian);
}

void	init_tex(t_cub3d *cub, t_data map)
{
	load_img(cub->mlx, &cub->tex[0], map.north[1]);
	load_img(cub->mlx, &cub->tex[1], map.south[1]);
	load_img(cub->mlx, &cub->tex[2], map.east[1]);
	load_img(cub->mlx, &cub->tex[3], map.west[1]);
}

int	tex_id(t_cub3d cub, double angle)
{
	if (angle > 0 && angle < M_PI && cub.ray.horizontal)
		return (1);
	else if (cub.ray.horizontal)
		return (0);
	else if (angle < M_PI_2 || angle > 3 * M_PI_2)
		return (2);
	return (3);
}
