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
	int			i;
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

char	*ft_substr(char const *s, int start, int len)
{
	int		i;
	int		j;
	char	*str;

	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i ++;
	return (i);
}
