#include "cub3d.h"

void    draw(t_cub3d *cub)
{
	t_tex	tex;
	int		i;

	tex->drawstart = cub->height / 2 - cub->line_height / 2;
	if (tex->drawstart < 0)
		tex->drawstart = 0;
	tex->drawend = cub->line_height / 2 + cub->height / 2;
	if (tex->drawend >= cub->height) tex->drawend = cub->height - 1;
	i = tex->drawstart;
	while (i <= tex->drawend)
	{
		my_mlx_pixel_put(cub, cub->pixel, i, color);
		i++;
	}
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
}

t_tex	texture_calcul(t_cub3d *cub)
{
	double	step;
	int		y;

	tex->tex_x = (int)(cub->wallx * 64);
	if (!cub->side && cub->raydirx > 0)
		tex->tex_x = 64 - tex->tex_x - 1;
	if (side == 1 && cub->raydirx < 0)
		tex->tex_x = 64 - tex->tex_x - 1;
	step = 1.0 * 64 / cub->line_height;
	tex->tex_pos = (tex->drawstart - cub->height / 2 + cub->line_height / 2) * step;
	y = 0;
	while (y < tex->drawend)
	{
		tex->tex_y = (int)tex->tex_pos;
		tex->tex_pos += step;
		int color = tex->texture[0][64 * tex->tex_y + tex->tex_x];
		if (side == 1) color = (color >> 1);
		buffer[y][cub->pixel] = color;
		y++;
	}
}
