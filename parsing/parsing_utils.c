/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <hharit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:05:39 by ahakam            #+#    #+#             */
/*   Updated: 2023/02/17 18:50:49 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	**read_fd(char *file)
{
	char	*line;
	char	*str;
	char	*tmp;
	char	**tmp2;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(1);
	str = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		tmp = str;
		str = ft_strjoin2(str, line);
		free(line);
		line = get_next_line(fd);
		free(tmp);
	}
	close(fd);
	tmp2 = ft_split(str, "\n");
	free(str);
	return (tmp2);
}

int	wall_search(char *line, int n_line, int count)
{
	int	j;
	int	i;

	j = 0;
	while (line [j] == ' ' || line [j] == '\t')
		j++;
	if (!count || count == n_line - 1)
	{
		i = 0;
		while ((unsigned long)(i + j) < ft_strlen(line) - 1)
		{
			if (line[i + j] != '1' && line[i + j] != ' ')
				return (0);
			i++;
		}
	}
	else
		if (!(line[j] == '1' && line[ft_strlen(line) - 1] == '1'))
			return (0);
	return (1);
}

int	player_position(t_data *d)
{
	d->p_found = 0;
	d->i = 0;
	while (d->map[d->i])
	{
		d->j = 0;
		while ((unsigned long)d->j < ft_strlen(d->map[d->i]) - 1)
		{
			if (d->map[d->i][d->j] == 'N' || d->map[d->i][d->j] == 'S' \
					|| d->map[d->i][d->j] == 'E' || d->map[d->i][d->j] == 'W')
				d->p_found ++;
			if (d->map[d->i][d->j] != 'N' && d->map[d->i][d->j] != 'S'
					&& d->map[d->i][d->j] != 'E' && \
					d->map[d->i][d->j] != 'W' && d->map[d->i][d->j] != '0'
					&& d->map[d->i][d->j] != ' ' && \
					d->map[d->i][d->j] != '1' && d->map[d->i][d->j] != '\t')
				return (0);
			d->j++;
		}
		d->i++;
	}
	if (d->p_found == 1)
		return (1);
	return (0);
}

int	check_spaces(char **str, int map_len)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (i == map_len)
			{
				if (str[i][j] != '1' && str[i][j] != ' ' && str[i][j] != '\t')
					return (0);
			}
			else if (str[i][j] == '0' && i < map_len)
			{
				if ((str[i - 1][j] == 32 || str[i + 1][j] == 32) \
						|| (str[i][j - 1] == 32 || str[i][j + 1] == 32))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_player(char **str, int map_len)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (i < map_len && (str[i][j] == 'N' || str[i][j] == 'S' \
			|| str[i][j] == 'E' || str[i][j] == 'W'))
			{
				if ((str[i - 1][j] != 48 || str[i + 1][j] != 48) \
				|| (str[i][j - 1] != 48 || str[i][j + 1] != 48))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
