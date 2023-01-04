/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:09:45 by ahakam            #+#    #+#             */
/*   Updated: 2022/12/26 21:09:46 by ahakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	tab_aloc(char *str, char m)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (str[i] != '\0')
	{
		if (str[i] == m)
			i++;
		else
		{
			c++;
			while (str[i] != '\0')
			{
				if (str[i] == m)
					break ;
				i++;
			}
		}
	}
	return (c);
}

static int	string(char *str, int *k, char m)
{
	int	c;

	c = 0;
	while (str[*k] != '\0')
	{
		if (str[*k] == m)
			*k += 1;
		else
		{
			while (str[*k] != '\0' && str[*k] != m)
			{
				c++;
				*k += 1;
			}
			*k += 1;
			return (c);
		}
	}
	return (0);
}

static char	**ft_append(char **tab, char *str, int i, char m)
{
	int	j;
	int	r;

	j = 0;
	while (str[i] != '\0')
	{
		r = 0;
		while (str[i] == m)
			i++;
		if (str[i] == '\0')
			break ;
		while (str[i] != m && str[i] != '\0')
		{
			tab[j][r] = str[i];
			i++;
			r++;
		}
		tab[j][r] = '\0';
		j++;
	}
	tab[j] = 0;
	return (tab);
}

void	ft_free(char **tab, int r)
{
    int i;

    i = 0;
	while (i < r)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**ft_split(char const *str, char c)
{
	char	**tab;
	int		i;
	int		p;
	int		r;

	r = -1;
	i = 0;
	p = 0;
	if (!str)
		return (0);
	tab = malloc(sizeof(char *) * (tab_aloc((char *)str, c) + 1));
	if (!tab)
		return (0);
	while (++r < tab_aloc((char *)str, c))
	{
		tab[r] = malloc(sizeof(char) * (string((char *)str, &p, c) + 1));
		if (!tab[r])
		{
			ft_free(tab, r);
			return (0);
		}
	}
	ft_append(tab, (char *)str, i, c);
	return (tab);
}