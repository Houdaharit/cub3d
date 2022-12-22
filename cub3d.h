#ifndef CUB3D_H
#define CUB3D_H
#include <mlx.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct s_cub3d
{
	void* mlx;
	void* win;
}t_cub3d;

int destroy(t_cub3d*);
int ft_close(int, t_cub3d*);

#endif
