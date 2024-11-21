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
#define BUFFERSIZE 5
#include <stdio.h>

char *get_next_line(int fd)
{
	static int nline;
	char *buffer;
	char *line;
	int count;
	int lcount;
	int i;
	int j;

	i = 0;
	j = 0;
	line = malloc(5);
	buffer = malloc(BUFFERSIZE);
	read(fd,buffer,BUFFERSIZE);

	j = 0;
	while(buffer[j] != '\n' && buffer[j])
	{
		//printf("%c",buffer[j]);
		line[i] = buffer[j];
		j ++;
		i ++;
		if(j == BUFFERSIZE)
		{
			read(fd,buffer,BUFFERSIZE);
			j = 0;
			continue;
		}
	}
	nline++;
	return (line);
}

int main(void)
{
	int fd;
	fd = open("./01", O_RDONLY);
	char *result;

	//result = malloc(500);
	result = get_next_line(fd);
	printf("%s\n",result);
	result = get_next_line(fd);
	printf("%s\n",result);
		result = get_next_line(fd);
	printf("%s\n",result);
		result = get_next_line(fd);
	printf("%s\n",result);
}