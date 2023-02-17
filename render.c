/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 03:05:11 by hharit            #+#    #+#             */
/*   Updated: 2023/02/10 05:20:05 by ahakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_cub3d *fr, int x, int y, int color)
{
	char	*dst;

	dst = fr->addr + (y * fr->line_length + x * (fr->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	get_pixel(t_texture *texture, int x, int y)
{
	char	*dst;

	dst = texture->addr_ + (y * texture->line_length
			+ x * (texture->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	start_end(double wallheight, int *start, int *end)
{
	*start = 0.5 * (HEIGHT - wallheight);
	*end = 0.5 * (HEIGHT + wallheight);
	if (*start < 0)
		*start = 0;
	if (*end > HEIGHT)
		*end = HEIGHT - 1;
}

void	drawing_ray(t_cub3d *game, double wallheight, int pixel, int tex_id)
{
	int	start;
	int	end;
	int	y;

	start_end(wallheight, &start, &end);
	y = start;
	if (game->ray.vertical)
		game->offsetx = (int)game->ray.inter_y % TILE;
	else
		game->offsetx = (int)game->ray.inter_x % TILE;
	while (y < end)
	{
		game->offsety = (y + wallheight * 0.5 - HEIGHT * 0.5)
			* (game->tex[tex_id].height / wallheight);
		my_mlx_pixel_put(game, pixel, y, get_pixel(&game->tex[tex_id],
				game->offsetx, game->offsety));
		y++;
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
