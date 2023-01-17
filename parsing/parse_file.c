#include "parsing.h"

void    check_path(t_data *data)
{
    if(access(data->north[1],F_OK) || access(data->south[1],F_OK) \
    || access(data->west[1], F_OK) || access(data->east[1],F_OK))
    {
        write(2, "invalide path\n", 15);
        exit(1);
    }
}

int texturesandcolors(t_data *data)
{
    int i;

    i = 0;
    while (data->file[i])
    {
        if(strnstr(data->file[i],"NO",ft_strlen(data->file[i])))
            data->north = ft_split(data->file[i], ' ');
        else if (strnstr(data->file[i],"SO",ft_strlen(data->file[i])))
            data->south = ft_split(data->file[i], ' ');
        else if (strnstr(data->file[i],"WE",ft_strlen(data->file[i])))
            data->west = ft_split(data->file[i], ' ');
        else if (strnstr(data->file[i],"EA",ft_strlen(data->file[i])))
            data->east = ft_split(data->file[i], ' ');
        else if (strnstr(data->file[i],"C",ft_strlen(data->file[i])))
            data->ceilling = ft_split(data->file[i], ' ');
        else if (strnstr(data->file[i],"F",ft_strlen(data->file[i])))
            data->floor = ft_split(data->file[i], ' ');
        else
            break;
        i++;
    }
    check_path(data);
    check_color_and_textures(data);
    return (i);
}

void    get_map(t_data *data, int data_lenght)
{
    int i;
    int j;

    i = texturesandcolors(data);
    data->colors = 0;
    data->textures = 0;
    check_color_and_textures(data);
    if (data->colors == 2 && data->textures == 4)
    {
        j = 0;
        data->map = malloc(sizeof(char*) *(data_lenght - i));
        while (data->file[i])
        { 
            data->map[j] = data->file[i];
            i++;
            j++;
        }
        data->map[j] = NULL;
    }
}

void    valid_map(char *av, t_data *data)
{
    data->map_lenght = 0;
    data->file = read_fd(av);
    data->filename = strchr(av, '.');
    get_map(data, count_lines(av));
    if (data->map)
    {
        while(data->map[data->map_lenght])
            data->map_lenght++;
        data->closed = closed_map(data->map,data->map_lenght);
        data->spaces = check_spaces(data->map);
    }
    if (strcmp(data->filename, ".cub") || !player_position(data)\
    || !data->spaces || !data->closed)
    {
        write(2,"invalid file or map !\n", 23);
        exit(1);
    }
}
