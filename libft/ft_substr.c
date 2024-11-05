/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:37:43 by vanfossi          #+#    #+#             */
/*   Updated: 2024/11/05 19:37:43 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	int i;
	char *subst;

	i = 0;
	subst = malloc(len+1);
	if(subst == 0)
		return 0;
	while(s[start] && ((size_t)i < len))
	{
		subst[i] = s[start+i];
		i++;
	}
	subst[i] = 0;
	return subst;
}

int main(void)
{
	printf("%s",ft_substr("bonjourwooo",9,4));
}