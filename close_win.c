#include "cub3d.h"

int destroy(t_cub3d *cub)
{
    mlx_destroy_window(cub->mlx, cub->win);
    free(cub->mlx);
    exit(0);
    return (0);
}

int ft_close(int keycode, t_cub3d* cub)
{
    if (keycode == 53)
    {
        destroy(cub);
        free(cub->win);
    }
    return (0);
}
