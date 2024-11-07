/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:44:39 by vanfossi          #+#    #+#             */
/*   Updated: 2024/11/05 11:44:39 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
	int i;
	int j;
	char *charsrc;

	charsrc = (char *)src;
	i = 0;
	j = 0;
	if(size == 0)
		return (0);
	while(dst[i] != 0)
		i++;
	printf("%d\n",i);
	while(i < (int)size)
	{
		dst[i] = charsrc[j];
		i++;
		j++;
	}
	if(dst[i])
		dst[i] = '\0';
	return (i);
}

// int main(void)
// {
// 		char dst[6];
// 		dst[0] = 'a';
// 		dst[1] = 'b';
// 		dst[2] = '\0';
// 		char *src = "012345";

// 		printf("%d\n",(int)ft_strlcat(dst,src,6));

// 		printf("%s",dst);
// }