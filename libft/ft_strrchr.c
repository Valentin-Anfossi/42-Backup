/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:02:20 by vanfossi          #+#    #+#             */
/*   Updated: 2024/11/05 15:02:20 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char *ft_strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen(s)-1;
	c %= 256;
	if(!s)
		return (0);
	if(c == 0)
		return ((char *)s + ft_strlen(s));
	while (s[i])
	{
		if(s[i] == c)
			return((char *)s + i);
	i--;
	}
	return (0);
}

// int main (void)
// {
// 	printf("%s", ft_strrchr("jorjorj",'d'));
// }