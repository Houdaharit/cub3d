/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <hharit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:09:45 by ahakam            #+#    #+#             */
/*   Updated: 2023/02/17 18:57:39 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

static int	tab_aloc(char *str, char *m)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (str[i] != '\0')
	{
		if (ft_strchr(m, str[i]))
			i++;
		else
		{
			c++;
			while (str[i] != '\0')
			{
				if (ft_strchr(m, str[i]))
					break ;
				i++;
			}
		}
	}
	return (c);
}

static int	string(char *str, int *k, char *m)
{
	int	c;

	c = 0;
	while (str[*k] != '\0')
	{
		if (ft_strchr(m, str[*k]))
			*k += 1;
		else
		{
			while (str[*k] != '\0' && !ft_strchr(m, str[*k]))
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

static char	**ft_append(char **tab, char *str, int i, char *m)
{
	int	j;
	int	r;

	j = 0;
	while (str[i] != '\0')
	{
		r = 0;
		while (ft_strchr(m, str[i]))
			i++;
		if (str[i] == '\0')
			break ;
		while (!ft_strchr(m, str[i]) && str[i] != '\0')
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

char	**ft_split(char const *str, char *c)
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
			free_2d(tab);
			return (0);
		}
	}
	ft_append(tab, (char *)str, i, c);
	return (tab);
}
