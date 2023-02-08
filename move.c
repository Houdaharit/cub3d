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
	cub->img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	cub->addr = (int *)mlx_get_data_addr(cub->img, &(cub->bits_per_pixel),
			&(cub->line_length), &(cub->endian));
}

void	rotation_right(t_cub3d *cub)
{
	double	old_dirx;
	double	old_planex;
	double	sin_angle;
	double	cos_angle;

	sin_angle =  sin(-1 * cub->rotspeed);
	cos_angle  =  cos(-1 * cub->rotspeed);
	old_dirx = cub->dirx;
	cub->dirx = cub->dirx * cos_angle - cub->diry * sin_angle;
	cub->diry = old_dirx * sin_angle + cub->diry * cos_angle;
	old_planex = cub->planex;
	cub->planex = cub->planex * cos_angle - cub->planey * sin_angle;
	cub->planey = old_planex * sin_angle + cub->planey * cos_angle;
}

void	rotation_left(t_cub3d *cub)
{
	double	old_dirx;
	double	old_planex;
	double	sin_angle;
	double	cos_angle;

	sin_angle =  sin(cub->rotspeed);
	cos_angle  =  cos(cub->rotspeed);
	old_dirx = cub->dirx;
	cub->dirx = cub->dirx * cos_angle - cub->diry * sin_angle;
	cub->diry = old_dirx * sin_angle + cub->diry * cos_angle;
	old_planex = cub->planex;
	cub->planex = cub->planex * cos_angle - cub->planey * sin_angle;
	cub->planey = old_planex * sin_angle + cub->planey * cos_angle;
}

void	forward_back(t_cub3d *cub, int keycode)
{
	int	x;
	int	y;
	double	x_movespeed;
	double	y_movespeed;
	
	x_movespeed = cub->dirx * cub->movespeed;
	y_movespeed = cub->diry * cub->movespeed;
	if (keycode == 13)
	{
		x = (int)(cub->posx + x_movespeed);
		y = (int)(cub->posy + y_movespeed);
		if(cub->map[x][(int)cub->posy] == '0')
			cub->posx += x_movespeed;
		if(cub->map[(int)cub->posx][y] == '0')
			cub->posy += y_movespeed;
	}
	else
	{
		x = (int)(cub->posx - x_movespeed);
		y = (int)(cub->posy - y_movespeed);
		if(cub->map[x][(int)cub->posy] == '0')
			cub->posx -= x_movespeed;
		if(cub->map[(int)cub->posx][y] == '0')
			cub->posy -= y_movespeed;
	}
}

int	moves(int keycode, t_cub3d *cub)
{
	if (keycode == 53)
		destroy(cub);
	if (keycode == 124 || keycode == 2)
	{
		rotation_right(cub);
		free_image(cub);
		raycasting(cub);
		ceils(cub);
	}
	if (keycode == 123 || keycode == 0)
	{
		rotation_left(cub);
		free_image(cub);
		raycasting(cub);
		ceils(cub);
	}
	if (keycode == 13 || keycode == 1)
	{
		forward_back(cub, keycode);
		free_image(cub);
		raycasting(cub);
		ceils(cub);
	}
	return 1;
}
