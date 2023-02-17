/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <hharit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:05:59 by ahakam            #+#    #+#             */
/*   Updated: 2023/02/17 18:00:27 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	count_lines(const char *str)
{
	char	*line;
	char	*tmp;
	int		i;
	int		fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error!\n", 8);
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
	return (i);
}

void	check_color_and_textures(t_data *data, int i)
{
	if (i > 6)
	{
		write(2, "Error !\n", 8);
		write(2, "duplicated texture or color!\n", 30);
		exit(1);
	}
	if (!strcmp(data->north[0], "NO"))
		data->textures += 1;
	if (!strcmp(data->south[0], "SO"))
		data->textures += 1;
	if (!strcmp(data->west[0], "WE"))
		data->textures += 1;
	if (!strcmp(data->east[0], "EA"))
		data->textures += 1;
	if (data->floor)
		data->colors += 1;
	if (data->ceilling)
		data->colors += 1;
}

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

int	ft_atoi(const char *str)
{
	int	signe;
	int	res;
	int	i;

	signe = 1;
	res = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10;
		res += str[i] - 48;
		i++;
	}
	return (res * signe);
}

int	is_num(char *str)
{
	int	i;

	i = 0;
	if (!str || *str == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (ft_atoi(str) > 255 || ft_atoi(str) < 0)
	{
		write(2, "Error! \n", 8);
		write(2, "The RBG values must not depass 255 or below 0", 46);
		exit(1);
	}
	return (1);
}
