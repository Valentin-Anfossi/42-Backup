/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 22:57:16 by vanfossi          #+#    #+#             */
/*   Updated: 2024/11/14 22:57:16 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlcat(char *dst, const char *src, int size)
{
	int	i;
	int	j;
	char	*charsrc;

	charsrc = (char *)src;
	i = ft_strlen(dst);
	j = 0;
	if (size <= i)
		return (size + ft_strlen(src));
	while (charsrc[j] && i + j < (size - 1))
	{
		dst[i + j] = charsrc[j];
		j++;
	}
	dst[i + j] = 0;
	return (i + ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc((sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1)));
	if (!str)
		return (0);
	if (s1)
	{
		while (s1[i])
			str[j++] = s1[i++];
		i = 0;
	}
	if (s2)
	{
		while (s2[i])
			str[j++] = s2[i++];
	}
	str[j] = 0;
	return (str);
}

char	*ft_strdup(const char *s)
{
	size_t		i;
	char		*dup;

	i = 0;
	dup = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!dup || !s)
		return (0);
	while (i < ft_strlen(s))
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	d;

	d = c;
	i = 0;
	while (s[i])
	{
		if (s[i] == d)
			return ((char *)s + i);
		i++;
	}
	if (d == '\0')
	{
		return ((char *)s + i);
	}
	return (0);
}