/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:05:39 by ahakam            #+#    #+#             */
/*   Updated: 2022/12/26 21:05:50 by ahakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char **read_fd(char *file)
{
    char *line;
    char *str;
    char *tmp;
    char **tmp2;
    int fd;

    fd = open(file,O_RDONLY);
    if (fd == -1)
    {
        write(2, "bad file descriptor !\n", 23);
        exit (1);
    }
    str = ft_strdup("");
    line = get_next_line(fd);
    while(line)
    {
        tmp = str;
        str  = ft_strjoin2(str, line);
        free(line);
        line = get_next_line(fd); 
        free(tmp);
    }
    close(fd);
    tmp2 = ft_split(str,'\n');
    free(str);
    return (tmp2);
}

int wall_search(char *line , int n_line, int count)
{
    int j;
    int i;

    j = 0;
    while (line [j] == ' ' || line [j] == '\t')
        j++;
    if (!count || count == n_line - 1)
    {
        i = 0;
        while(i + j < ft_strlen(line) - 1)
        {
            if (line[i + j] != '1' && line[i + j] != ' ')
                return 0;
            i++;
        }
    } 
    else
        if(!(line[j] == '1' && line[ft_strlen(line) - 1] == '1'))
            return (0);    
    return 1;
}

int player_position(char **str)
{
    int j;
    int p_found;
    int i;

    p_found = 0;
    i = 0;
    while (str[i])
    {
        j = 0;
        while (j < ft_strlen(str[i]) - 1)
        {
            if (str[i][j] == 'N' || str[i][j] == 'S' || str[i][j] == 'E' || str[i][j] == 'W')
                p_found ++;
            if (str[i][j] != 'N' && str[i][j] != 'S' && str[i][j] != 'E' && \
            str[i][j] != 'W' && str[i][j] != '0' && str[i][j] != ' ' && \
            str[i][j] != '1' && str[i][j] != '\t')
                return(0);                
            j++;
        }
        i++;
    }
    if (p_found == 1)
        return (1);
    return (0);
}

int closed_map(char **str, int n_line)
{
    int line_counter;
    int i;
    int j;

    i = 0;
    line_counter = 0;
    
    while (str[i])
    {
        if (!(wall_search(str[i],n_line, line_counter)))
            return (0);
        line_counter++;
         i++;
    }
    return(1);
}

int check_spaces(char **str, int c_lines)
{
    int i;
    int j;

    i = 0;
    while(str[i])
    {
        j = 0;
        while(str[i][j])
        {
            if (str[i][j] == '0')
            {
               if((str[i - 1][j] == 32 || str[i + 1][j] == 32) \
               || (str[i][j - 1] == 32 || str[i][j + 1] == 32))
                 return 0;
            }
            j++;
        }
        i++;
    }
    return 1;
}