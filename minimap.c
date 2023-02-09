#include "cub3d.h"

void	minimap(t_cub3d *cub)
{
	int i = 0;
	int j = 0;
	int x = 0;
	int y = 0;
	int	img_width, img_height;

	cub->play_xpm = mlx_xpm_file_to_image(cub->mlx, "./red.xpm", (int*)&img_width, (int*)&img_height);
	cub->walls_xpm = mlx_xpm_file_to_image(cub->mlx, "./black.xpm", (int*)&img_width, (int*)&img_height);
	while (cub->map[j] != NULL)
	{
		i= 0;
		x = 0;
		while (cub->map[j][i])
		{
			if (cub->map[j][i] == '1')
				mlx_put_image_to_window(cub->mlx, cub->mlx_window, cub->walls_xpm, x , y);
			if (i == floor(cub->player_x / TILE) && j == floor(cub->player_y / TILE))
				mlx_put_image_to_window(cub->mlx, cub->mlx_window, cub->play_xpm, x, y);
			x += img_width;
			i++;
		}
		j++;
		y += img_height;
	}
}
