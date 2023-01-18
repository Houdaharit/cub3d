#include "cub3d.h"

void	free_image(t_cub3d *cub)
{
	mlx_clear_window(cub->mlx, cub->win);
	cub->img = mlx_new_image(cub->mlx, cub->width, cub->height);
	cub->addr = mlx_get_data_addr(cub->img, &(cub->bits_per_pixel),
			&(cub->line_length), &(cub->endian));
}

void	rotation_right(t_cub3d *cub)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = cub->dirx;
	cub->dirx = cub->dirx * cos(-1 * cub->rotspeed) - cub->diry * sin(-1 * cub->rotspeed);
	cub->diry = old_dirx * sin(-1 * cub->rotspeed) + cub->diry * cos(-1 * cub->rotspeed);
	old_planex = cub->planex;
	cub->planex = cub->planex * cos(-1 * cub->rotspeed) - cub->planey * sin(-1 * cub->rotspeed);
	cub->planey = old_planex * sin(-1 * cub->rotspeed) + cub->planey * cos(-1 * cub->rotspeed);
}

void	rotation_left(t_cub3d *cub)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = cub->dirx;
	cub->dirx = cub->dirx * cos(cub->rotspeed) - cub->diry * sin(cub->rotspeed);
	cub->diry = old_dirx * sin(cub->rotspeed) + cub->diry * cos(cub->rotspeed);
	old_planex = cub->planex;
	cub->planex = cub->planex * cos(cub->rotspeed) - cub->planey * sin(cub->rotspeed);
	cub->planey = old_planex * sin(cub->rotspeed) + cub->planey * cos(cub->rotspeed);
}

void	forward(t_cub3d *cub)
{
	if(cub->map[(int)(cub->posx + cub->dirx * cub->movespeed)][(int)cub->posy] != '1')
		cub->posx += cub->dirx * cub->movespeed;
	if(cub->map[(int)cub->posx][(int)(cub->posy + cub->diry * cub->movespeed)] != '1')
		cub->posy += cub->diry * cub->movespeed;
}
int	moves(int keycode, t_cub3d *cub)
{
	printf("key: %d\n", keycode);
	if (keycode == 53)
		destroy(cub);
	if (keycode == 13)
	{
		rotation_right(cub);
		free_image(cub);
	}
	if (keycode == 123)
	{
		rotation_left(cub);
		free_image(cub);
	}
	if (keycode == 126)
	{
		forward(cub);
		free_image(cub);
	}
	return 1;
}
