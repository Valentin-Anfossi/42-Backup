/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:43:32 by vanfossi          #+#    #+#             */
/*   Updated: 2024/11/05 16:43:32 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char *ft_strnstr(const char *big, const char *little, int len)
{
	int i;
	int j;
	int littlestart;
	int littlelen;
	char *ptr;

	i = 0;
	j = 0;
	littlelen = 0;
	littlestart = 0;
	while(little[littlelen])
		littlelen++;
	if(littlelen == 0)
		return ((char *)big);
	while(big[i] && ++i < len-2)
	{
		littlestart = i;
		while(big[i] == little[j])
		{
			i++;
			j++;
			if(j == littlelen)
			{
				ptr = (char*)big + littlestart;
				return(ptr);
			}
		}
	}
	return 0;
}

// int main (void)
// {
// 	printf("%s\n",ft_strnstr("abcdabcdabcd","ef",9));
// 	printf("%s\n",ft_strnstr("abcdabcdabcd","da",4));
// }