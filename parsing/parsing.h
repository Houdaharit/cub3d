/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <hharit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:09:39 by ahakam            #+#    #+#             */
/*   Updated: 2023/02/17 18:46:50 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>

typedef struct s_data
{
	int		colors;
	int		player_pos;
	int		closed;
	int		valid;
	int		path;
	int		textures;
	int		spaces;
	char	**map;
	char	**file;
	int		map_lenght;
	int		data_lenght;
	char	**north;
	char	**west;
	char	**east;
	char	**south;
	char	*floor;
	char	direction;
	char	*filename;
	char	*ceilling;
	int		farr[3];
	int		carr[3];
	char	**arrayf;
	char	**arrayc;
	int		i;
	int		j;
	int		p_found;
}	t_data;

char	**ft_split(const char *str, char *c);
void	ft_free(char **strs, int p);
t_data	*valid_map(char *av, t_data *cub);
char	**read_fd(char *file);
void	check_color_and_textures(t_data *data, int i);
int		player_position(t_data *data);
int		closed_map(char **str, int n_line);
int		count_lines(const char *str);
int		check_spaces(char **str, int map_len);
char	*remove_comma(char *str);
void	storecolores(t_data *data);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strtrim(char const *s1, char const *set);
int		is_num(char *str);
int		check_player(char **str, int map_len);
int		ft_atoi(const char *str);
void	free_2d(char **str);
#endif
