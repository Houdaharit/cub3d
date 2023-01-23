#include "cub3d.h"

void    draw(t_cub3d *cub)
{
	int	i;
	int	drawstart;
	int	drawend;

	drawstart = cub->height / 2 - cub->line_height / 2;
	if (drawstart < 0)
		drawstart = 0;
	drawend = cub->line_height / 2 + cub->height / 2;
	if (drawend >= cub->height) drawend = cub->height - 1;
	i = drawstart;
	while (i <= drawend)
	{
		my_mlx_pixel_put(cub, cub->pixel, i, color);
		i++;
	}
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
}

int	**texture_calcul(t_cub3d *cub, int drawstart, int drawend)
{
	double	step;
	int		y;
	int		buffer[64][64];

	tex_x = (int)(cub->wallx * 64);
	if (!cub->side && cub->raydirx > 0)
		tex_x = 64 - tex_x - 1;
	if (side == 1 && cub->raydirx < 0)
		tex_x = 64 - tex_x - 1;
	step = 1.0 * 64 / cub->line_height;
	tex_pos = (drawstart - cub->height / 2 + cub->line_height / 2) * step;
	y = 0;
	while (y < drawend)
	{
		tex_y = (int)tex_pos;
		tex_pos += step;
		int color = texture[0][64 * tex_y + tex_x];
		if (side == 1) color = (color >> 1);
		buffer[y][cub->pixel] = color;
		y++;
	}
	return (buffer);
}
