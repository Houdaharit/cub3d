/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 06:28:38 by hharit            #+#    #+#             */
/*   Updated: 2023/01/25 07:20:54 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init_buffer(t_cub3d *cub)
{
    int j;
    int i;
    int max;

    max = cub->height * cub->width;
    //cub->buffer = (int**)malloc(sizeof(int*) * cub->height);
    i = 0;
    while (i < cub->height)
    {
        //  cub->buffer[i] = (int*)malloc(sizeof(int) * cub->height * cub->width);
        j = 0;
        while (j < cub->width)
        {
            cub->buffer[i][j] = 0;
            j++;
        }
        i++;
    }
}

void    init_textures(t_cub3d *cub)
{
    int j;
    int i;
    int max;

    cub->tex_width = 64;
    cub->tex_height = 64;
    max = cub->tex_width * cub->tex_height;
    init_buffer(cub);
    cub->textures = (int**)malloc(sizeof(int*) * 4);
    i = 0;
    while (i < 4)
        cub->textures[i++] = (int*)malloc(sizeof(int) * cub->tex_width * cub->tex_height);
    i = 0;
    while (i < 4)
    {
        j = 0;
        while(j < max)
        {
            cub->textures[i][j] = 0;
            j++;
        }
        i++;
    }
}

void	get_textures(t_cub3d *cub, int *texture, char *path)
{
	int	i;
	int	j;

	cub->img = mlx_xpm_file_to_image(cub->mlx, path, (int*)&cub->img_width, (int*)&cub->img_height);
    cub->addr = (int *)mlx_get_data_addr(cub->img, &(cub->bits_per_pixel),
            &(cub->line_length), &(cub->endian));
	j = 0;
	while (j < cub->img_height)
	{
		i = 0;
		while (i < cub->img_width)
		{
			texture[cub->img_width * j + i] = cub->addr[cub->img_width * j + i];
			i++;
		}
		j++;
	}
	mlx_destroy_image(cub->mlx, cub->img);
}

void	load_image(t_cub3d *cub, t_data map)
{
	init_textures(cub);
	get_textures(cub, cub->textures[0], "./textures1/wall.xpm");
	get_textures(cub, cub->textures[1], "./textures1/wall.xpm");
	get_textures(cub, cub->textures[2], "./textures1/wall.xpm");
	get_textures(cub, cub->textures[3], "./textures1/wall.xpm");
}
