#include "cub3d.h"

void	ceils(t_cub3d *cub)
{
	int i = 0;
	int j = 0;
	int x = 0;
	int y = 0;

	while (cub->map[j] != NULL)
	{
		i= 0;
		x = 0;
		while (cub->map[j][i])
		{
			if (cub->map[j][i] == '1')
				mlx_put_image_to_window(cub->mlx, cub->win, cub->walls, x , y );
			if (j == (int)cub->posx && i == (int)cub->posy)
				mlx_put_image_to_window(cub->mlx, cub->win, cub->player, x, y);
			x += cub->img_width;
			i++;
		}
		j++;
		y += cub->img_height;
	}
}
