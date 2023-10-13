/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:28:23 by yliew             #+#    #+#             */
/*   Updated: 2023/09/22 16:00:26 by yliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = 0;
	while (str[i])
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return (&str[i]);
		i++;
	}
	if ((unsigned char)c == 0)
		return (&str[i]);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	unsigned int	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		sub = malloc(1 * sizeof(char));
	else if (start + len <= s_len)
		sub = malloc((len + 1) * sizeof(char));
	else
		sub = malloc((s_len - start + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while ((start + i) < s_len && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	d;
	size_t	i;

	if (!s1 && !s2)
		return (NULL);
	d = ft_strlen(s1);
	dst = malloc((d + ft_strlen(s2) + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		dst[d + i] = s2[i];
		i++;
	}
	dst[d + i] = '\0';
	return (dst);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*dest;
	size_t	n;
	size_t	i;

	if (nmemb > SIZE_MAX / size)
		return (NULL);
	n = nmemb * size;
	dest = malloc(n);
	if (!dest)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
