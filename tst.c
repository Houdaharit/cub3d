#include "cub3d.h"

int main()
{
	t_cub3d cub;

	cub.mlx = mlx_init();
	cub.win = mlx_new_window(cub.mlx, 800, 800, "test");
	cub.img = mlx_xpm_file_to_image(cub.mlx, "./textures1/white.xpm", (int*)&cub.img_width,(int*)&cub.img_height);
	mlx_put_image_to_window(cub.mlx, cub.win, cub.img , 0 , 0);
	mlx_loop(cub.mlx);
}
