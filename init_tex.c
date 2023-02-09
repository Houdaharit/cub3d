#include "cub3d.h"

void	load_img(void *mlx, t_texture *texture, char *file)
{
	texture->img = mlx_xpm_file_to_image(mlx, file,
			&texture->width, &texture->height);
	texture->addr_ = mlx_get_data_addr(texture->img,
			&texture->bits_per_pixel, &texture->line_length, &texture->endian);

}

void	init_tex(t_cub3d *cub, t_data map)
{
	load_img(cub->mlx, &cub->tex[0], map.north[1]);
	load_img(cub->mlx, &cub->tex[1], map.south[1]);
	load_img(cub->mlx, &cub->tex[2], map.east[1]);
	load_img(cub->mlx, &cub->tex[3], map.west[1]);
}
