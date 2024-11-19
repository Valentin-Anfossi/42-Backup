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
#include <stdio.h>
#include <fcntl.h>
#define BUFFER_SIZE 8

static char *ft_getline(int fd, char *rest, char *buffer)
{
	char *line;
	
	read(fd, buffer, BUFFER_SIZE);
	
}

char *get_next_line(int fd)
{
	static char	*rest;
	char *buffer;
	char *line;

	buffer = malloc(BUFFER_SIZE + 1);
	if(!buffer)
		return (0);
	if (BUFFER_SIZE <= 0 || fd < 0)
		{
			free(buffer);
			return(0);
		}
	line = ft_getline(fd, rest, buffer);

	if(!line)
		return (0);
	rest = ft_getrest(line);
	free(buffer);
	return (line);
}

int	main(void)
{
	int fd;
	fd = open("./01",O_RDONLY);
	char *result = get_next_line(fd);

	printf("%s",result);
	result = get_next_line(fd);

	printf("%s",result);
	// while(result[i])
	// {
	// 	write(1,&result[i],1);
	// 	i++;
	// }
}