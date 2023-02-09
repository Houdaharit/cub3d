/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 03:05:11 by hharit            #+#    #+#             */
/*   Updated: 2023/02/09 15:35:40 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_cub3d *fr, int x, int y, int color)
{
	char	*dst;

	dst = fr->addr + (y * fr->line_length + x * (fr->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	start_end(double wallheight, int *start, int *end)
{
	
		*start = 0.5 * (HEIGHT - wallheight);
		if (*start < 0) *start = 0;
		*end = 0.5 * (HEIGHT + wallheight);
		if (*end > HEIGHT)
		*end = HEIGHT;
	
}

void	drawing_ray(t_cub3d *game,double wallheight, int i)
{
	int	start;
	int	end;
	int	y;
	int color = 0X0000FF;
	
	start_end(wallheight, &start, &end);	
	y = start;
	while (y < end)
	{ 
		my_mlx_pixel_put(game, i, y, color);
		y++;
	}
	
}

void	floor_and_cellings(t_cub3d *cub)
{
	int	i;
	int	j;
	int	end_ceilling;

	i = 0;
	int color = 0x87CEEB;
	int pink = 0x808080;
	end_ceilling = HEIGHT / 2;
	while (i < end_ceilling)
	{
		j = 0;
		while (j < WIDTH)
			my_mlx_pixel_put(cub, j++, i, color);
		i++;
	}
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
			my_mlx_pixel_put(cub, j++, i,pink);
		i++;
	}
}

void	rending(t_cub3d *cub)
{
	cub->img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	cub->addr = mlx_get_data_addr(cub->img,
			&cub->bits_per_pixel, &cub->line_length, &cub->endian);
	floor_and_cellings(cub);
	raycasting(cub);
	mlx_put_image_to_window(cub->mlx, cub->mlx_window, cub->img, 0, 0);
	minimap(cub);
}
