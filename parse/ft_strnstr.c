#include "parsing.h"

char	*strnstr(const char *haystack, const char *needle, size_t len)
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
