/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <hharit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 22:42:42 by ahakam            #+#    #+#             */
/*   Updated: 2023/02/17 18:47:45 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	free_2d(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	num_comm(char *str)
{
	int	nu;
	int	i;

	nu = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			nu++;
		i++;
	}
	return (nu);
}

void	floor_color(t_data *data)
{
	char	**str;
	char	*floor;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (data->floor)
	{
		str = ft_split(data->floor, ",");
		while (str[i])
		{
			floor = ft_strtrim(str[i], " ");
			if (is_num(floor))
				data->farr[j++] = atoi(floor);
			i++;
			free(floor);
		}
		free_2d(str);
	}
	if (j != 3 || num_comm(data->floor) != 2)
	{
		write(2, "Error!\nwrong floor colors !", 28);
		exit(1);
	}
}

void	ceilling_color(t_data *data)
{
	char	**str;
	char	*ceil;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (data->ceilling)
	{
		str = ft_split(data->ceilling, ",");
		while (str[i])
		{
			ceil = ft_strtrim(str[i], " ");
			if (is_num(ceil))
				data->carr[j++] = atoi(ceil);
			i++;
			free(ceil);
		}
		free_2d(str);
	}
	if (j != 3 || num_comm(data->ceilling) != 2)
	{
		write(2, "Error!\nwrong ceilling colors !", 31);
		exit(1);
	}
}

void	storecolores(t_data *data)
{
	floor_color(data);
	ceilling_color(data);
}
