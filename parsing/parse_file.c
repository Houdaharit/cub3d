/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <hharit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 06:00:15 by ahakam            #+#    #+#             */
/*   Updated: 2023/02/17 18:58:03 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!(*needle))
		return ((char *)haystack);
	if (!ft_strlen(haystack) && !ft_strlen(needle))
		return ("");
	while (haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (needle[j] && haystack[i + j] == needle[j] && i + j < len)
				j ++;
			if (!needle[j])
				return ((char *)(haystack + i));
		}
		i ++;
	}
	return (NULL);
}

void	check_path(t_data *data)
{
	if (!data->north || !data->south || !data->west \
			|| !data->east || !data->floor || !data->ceilling)
	{
		write(2, "Error !\n", 8);
		write(2, "wrong colors or textures !\n", 28);
		exit(1);
	}
	if (access(data->north[1], F_OK) || access(data->south[1], F_OK) \
			|| access(data->west[1], F_OK) || access(data->east[1], F_OK))
	{
		write(2, "Error!\n", 8);
		write(2, "invalide path\n", 15);
		exit(1);
	}
}

int	texturesandcolors(t_data *data)
{
	int		i;
	char	*spaces;

	i = 0;
	spaces = "\t\v\r\n\f ";
	while (data->file[i])
	{
		if (ft_strnstr(data->file[i], "NO", 2))
			data->north = ft_split(data->file[i], spaces);
		else if (ft_strnstr(data->file[i], "SO", 2))
			data->south = ft_split(data->file[i], spaces);
		else if (ft_strnstr(data->file[i], "WE", 2))
			data->west = ft_split(data->file[i], spaces);
		else if (ft_strnstr(data->file[i], "EA", 2))
			data->east = ft_split(data->file[i], spaces);
		else if (ft_strnstr(data->file[i], "C", 1))
			data->ceilling = ft_strnstr(data->file[i], "C", 1) + 1;
		else if (ft_strnstr(data->file[i], "F", 1))
			data->floor = ft_strnstr(data->file[i], "F", 1) + 1;
		else
			break ;
		i++;
	}
	check_path(data);
	return (i);
}

void	get_map(t_data *data, int data_lenght)
{
	int	i;
	int	j;

	i = texturesandcolors(data);
	data->colors = 0;
	data->textures = 0;
	check_color_and_textures(data, i);
	if (data->colors == 2 && data->textures == 4)
	{
		j = 0;
		data->map = malloc(sizeof(char *) * (data_lenght - i));
		while (data->file[i])
		{
			data->map[j] = data->file[i];
			i++;
			j++;
		}
		data->map[j] = NULL;
	}
	else
	{
		write(2, "Error! \n", 8);
		write(2, "wrong colors or texutures !\n", 28);
		exit(1);
	}
}

t_data	*valid_map(char *av, t_data *data)
{
	data = malloc(sizeof(t_data));
	data->map_lenght = 1;
	data->file = read_fd(av);
	get_map(data, count_lines(av));
	if (data->map)
	{
		data->data_lenght = ft_strlen(data->map[0]);
		while (data->map[data->map_lenght])
		{
			if (ft_strlen(data->map[data->map_lenght])
				> (size_t)data->data_lenght)
				data->data_lenght = ft_strlen(data->map[data->map_lenght]);
			data->map_lenght++;
		}
		if (!player_position(data) \
			|| !check_spaces(data->map, data->map_lenght - 1) \
				|| !check_player(data->map, data->map_lenght - 1))
		{
			write(2, "Error!\n", 8);
			write(2, "invalid map!\n", 14);
			exit(1);
		}
	}
	return (data);
}
