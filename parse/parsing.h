/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:09:39 by ahakam            #+#    #+#             */
/*   Updated: 2022/12/27 16:14:32 by ahakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef parsing_H
#define parsing_H

#include "get_next_line/get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

typedef struct s_data
{
    int colors;
    int player_pos;
    int closed;
    int valid;
    int path;
    int textures;
    int spaces;
    char **map;
    char **file;
    int map_lenght;
    int data_lenght;
    char **north;
    char **west;
    char **east;
    char **south;
    char **floor;
    char *filename;
    char **ceilling;
    int Farr[3];
    int Carr[3];
    char **arrayF;
    char **arrayC;
} t_data;

char    **ft_split(const char *str, char c);
void    ft_free(char **strs, int p);
void    valid_map(char *av, t_data *data);
char    **read_fd(char *file);
void    check_color_and_textures(t_data *data);
int     player_position(char **str);
int     closed_map(char **str, int n_line);
int     count_lines(const char *str);
int     check_spaces(char **str, int c_lines);
void    storecolores(t_data *data);
char	*strnstr(const char*, const char*, size_t);
#endif
