/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:32:46 by vanfossi          #+#    #+#             */
/*   Updated: 2024/11/05 16:32:46 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

typedef typeof(sizeof(0)) size_t; 

int ft_memcmp(const void *s1, const void *s2,  size_t n)
{
	size_t i;
	char *cs1;
	char *cs2;

	cs1 = (char *)s1;
	cs2 = (char *)s2;
	i = 0;
	while((cs1[i] || cs2[i]) & (i < n))
	{
		if(cs1[i] != cs2[i])
			return (cs1[i] - cs2[i]);
		i++;
	}
	return (0);
}

// int main(void)
// {
// 	printf("%d",ft_memcmp("bba","bbba",3));
// }