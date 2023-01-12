/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:05:59 by ahakam            #+#    #+#             */
/*   Updated: 2023/01/13 00:04:15 by ahakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int count_lines(const char *str)
{
    char *line;
    char *tmp;
    int i;
    int fd;

    fd = open(str,O_RDONLY);
    if (fd == -1)
    {
        write(2, "bad file descriptor !\n", 23);
        exit (1);
    }
    line = get_next_line(fd);
    i = 0;
    while (line)
    {
        i++;
        tmp = line;
        line = get_next_line(fd);
        free(tmp);
    }
    close(fd);
    return(i);
}

void    check_color_and_textures(t_data *data)
{
    if (!strcmp(data->north[0], "NO"))
        data->textures += 1;
    if (!strcmp(data->south[0], "SO"))
        data->textures += 1;
    if (!strcmp(data->west[0], "WE"))
        data->textures += 1;
    if (!strcmp(data->east[0], "EA"))
        data->textures += 1;
    if (!strcmp(data->floor[0], "F"))
        data->colors += 1;
    if (!strcmp(data->ceilling[0], "C"))
        data->colors += 1;
}

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

int is_num(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        if(!ft_isdigit(str[i]))
            return 0;
        i++;
    }
    return 1;
}
void    storecolores(t_data *data)
{
    int i;

    i = 0;
    data->arrayF = ft_split(data->floor[1], ',');
    data->arrayC = ft_split(data->ceilling[1], ',');
    while(data->arrayF[i])
    {
        if(!is_num(data->arrayF[i]) || i > 3 || !is_num(data->arrayC[i]))
        {
            write(2, "wrong colors!\n", 15);
            exit(1);
        }
        else
        {
            data->Farr[i] = atoi(data->arrayF[i]);
            data->Carr[i] = atoi(data->arrayC[i]);
        }
        i++;
    }
}