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

char *get_next_line(int fd)
{
	static int nline;
	char *buffer;

	buffer = malloc(20);
	read(fd,buffer,20);
	return (buffer);
}

int main(void)
{
	int fd;
	fd = open("./01", O_RDONLY);
	char *result;

	result = malloc(20);
	result = get_next_line(fd);
	printf("%s",result);
}