/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:48:26 by vanfossi          #+#    #+#             */
/*   Updated: 2024/11/05 15:48:26 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
	size_t i;
	char *r;
	char *chars;
	
	chars = (char *)s;
	r = 0;
	i = 0;
	while (chars[i] && i < n)
	{
		if(chars[i] == c)
			r = (void *)s+i;
	i++;
	}
	return (r);
}

// int main(void)
// {
// 	printf("%s", (char *)ft_memchr("bonjour",'j',4));
// }