/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 22:56:44 by vanfossi          #+#    #+#             */
/*   Updated: 2024/11/14 22:56:44 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*get_rest(char *line)
{
	char	*rest;
	int		i;

	i = 0;
	while (line[i] != '\n' && line[i] != 0)
		i++;
	if (line[i] == 0)
		return (0);
	rest = ft_substr(line, i + 1, ft_strlen(line) - i - 1);
	if (!rest || *rest == 0)
	{
		free(rest);
		return (0);
	}
	line[i + 1] = 0;
	return (rest);
}

char	*get_line_from_buffer(int fd, char *rest, char *buffer)
{
	int		i;
	char	*temp;

	i = 1;
	while (i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
			return (rest);
		else if (i == 0)
			break ;
		buffer[i] = 0;
		if (!rest)
			rest = ft_strdup("");
		temp = rest;
		rest = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*buffer;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	line = get_line_from_buffer(fd, rest, buffer);
	free(buffer);
	if (!line || *line == 0)
	{
		free(line);
		return (0);
	}
	rest = get_rest(line);
	return (line);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i ++;
	return (i);
}

// int	main(void)
// {
// 	int fd;
// 	fd = open("./01",O_RDONLY);
// 	char *result = get_next_line(fd);

// 	printf("%s",result);
// 	result = get_next_line(fd);

// 	printf("%s",result);
// 	result = get_next_line(fd);

// 	printf("%s",result);
// }