/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 03:05:11 by hharit            #+#    #+#             */
/*   Updated: 2023/02/01 04:13:58 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_cub3d *fr, int x, int y, int color)
{
	char	*dst;

	dst = fr->mlx.addr + (y * fr->mlx.line_length + x * (fr->mlx.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

float	wall_strip_height(t_cub3d *cub)
{
	double	wall_strip_height;
	double	wall_distance;
	double	distance_plane;

	wall_distance = cub->ray.distance * cos(cub->ray.ray_angle - cub->player.rot_angle);
	distance_plane = (cub->mlx.width / 2) / tan(cub->fov_angle / 2);
	wall_strip_height = (cub->tile_size / wall_distance) * distance_plane;
	return (wall_strip_height);
}

void draw(t_cub3d *cub, int pixel)
{
	int	color = 0x0000FF;
	int	wallstripheight;
	
	wallstripheight = (int)wall_strip_height(cub);
	int drawstart = (cub->mlx.height / 2) - ((int)wallstripheight / 2);
	if (drawstart < 0) drawstart = 0;
	int drawend = ((int)wallstripheight / 2) + (cub->mlx.height / 2);
	if (drawend > cub->mlx.height) drawend = cub->mlx.height;
	int i = drawstart;
//	printf("start: %d\t end: %d\n", drawstart, drawend);
	while (i <= drawend)
	{
		my_mlx_pixel_put(cub, pixel, i, color);
		i++;
	}
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win, cub->mlx.img, 0, 0);
}
