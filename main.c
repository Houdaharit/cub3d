#include "cub3d.h"

int main()
{
	t_cub3d *cub = NULL;

	cub = (t_cub3d*)malloc(sizeof(t_cub3d));
	cub->mlx = mlx_init();
	cub->win = mlx_new_window(cub, 800, 800, "cub3d");
	mlx_hook(cub->win, 2, 1L >> 0, ft_close, (void *)cub);
	mlx_hook(cub->win, 17, 0, destroy, (void *)cub);
	mlx_loop(cub->mlx);
}
