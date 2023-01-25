#include "cub3d.h"

void	free_image(t_cub3d *cub)
{
	/*int i = 0;
	  int j = 0;

	  while(i < cub->height)
	  {
	  j = 0;
	  while (j < cub->width)
	  {
	  cub->buffer[i][j] = 0;
	  j++;
	  }
	  i++;
	  }*/
	cub->img = mlx_new_image(cub->mlx, cub->width, cub->height);
	cub->addr = (int *)mlx_get_data_addr(cub->img, &(cub->bits_per_pixel),
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

void	forward_back(t_cub3d *cub, int keycode)
{
	int	x;
	int	y;

	if (keycode == 126)
	{
		x = (int)(cub->posx + cub->dirx * cub->movespeed);
		y = (int)(cub->posy + cub->diry * cub->movespeed);
		if(cub->map[x][(int)cub->posy] == '0')
			cub->posx += cub->dirx * cub->movespeed;
		if(cub->map[(int)cub->posx][y] == '0')
			cub->posy += cub->diry * cub->movespeed;
	}
	else
	{
		x = (int)(cub->posx - cub->dirx * cub->movespeed);
		y = (int)(cub->posy - cub->diry * cub->movespeed);
		if(cub->map[x][(int)cub->posy] == '0')
			cub->posx -= cub->dirx * cub->movespeed;
		if(cub->map[(int)cub->posx][y] == '0')
			cub->posy -= cub->diry * cub->movespeed;
	}
}

int	moves(int keycode, t_cub3d *cub)
{
	if (keycode == 53)
		destroy(cub);
	if (keycode == 124)
	{
		rotation_right(cub);
		free_image(cub);
		raycasting(cub);
		ceils(cub);
	}
	if (keycode == 123)
	{
		rotation_left(cub);
		free_image(cub);
		raycasting(cub);
		ceils(cub);
	}
	if (keycode == 126 || keycode == 125)
	{
		forward_back(cub, keycode);
		free_image(cub);
		raycasting(cub);
		ceils(cub);
	}
	return 1;
}
