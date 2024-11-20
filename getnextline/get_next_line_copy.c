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

char *ft_linefrombuffer(int fd, char *rest, char *buffer)
{
	char *temp;
	int i;

	i = 1;
	while (i > 0)
	{
		i = read(fd,buffer,BUFFER_SIZE);
		if(i == -1) /*ERREUR*/
			return (0);
		else if (i == 0) /*FIN DU FICHIER*/
			break;
		buffer[i] = 0;
		if(!rest)
			rest = ft_strdup("");
		temp = rest;
		rest = ft_strjoin(temp, buffer);
		temp = 0;

	}
	
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