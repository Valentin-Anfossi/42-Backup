/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:09:00 by vanfossi          #+#    #+#             */
/*   Updated: 2024/11/05 10:09:00 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef typeof(sizeof(0)) size_t;

size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
	int i;
	char *charsrc;

	charsrc = (char *)src;
	i = 0;
	if(size == 0)
		return (0);
	while(i < size-1)
	{
		dst[i] = charsrc[i];
		i++;
	}
	dst[i] = '\0';
	i = 0;
	while(src[i])
	{
		i++;
	}
	return (i);
}

int main(void)
{
		char dst[10];
		char *src = "0123456789";

		printf("%d\n",ft_strlcpy(dst,src,11));

		printf("%s",dst);
}