/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <hharit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:54:21 by ahakam            #+#    #+#             */
/*   Updated: 2023/02/17 18:52:45 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

static char	*ft_trimappend(char const *s1, char *str, int start, int end)
{
	int	i;

	i = 0;
	while (start < (end + 1))
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

static int	find_first_index(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;

	end = ft_strlen(s1);
	start = 0;
	while (start < end)
	{
		if (!ft_strchr(set, s1[start]))
			break ;
		start++;
	}
	return (start);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*str;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	end = ft_strlen(s1);
	start = find_first_index(s1, set);
	while (s1[end] != s1[start])
	{
		if (!ft_strchr(set, s1[end]))
			break ;
		end--;
	}
	str = malloc(sizeof(char) * ((end - start) + 2));
	if (!str)
		return (NULL);
	ft_trimappend(s1, str, start, end);
	return (str);
}
