/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:28:58 by vanfossi          #+#    #+#             */
/*   Updated: 2024/11/05 19:28:58 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char *ft_strdup(const char *s)
{
	int slen;
	int i;
	char *dup;
	
	slen = 0;
	i = 0;
	while(s[slen])
		slen++;
	dup = malloc(sizeof(char)*slen+1);
	while(i<slen+1)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return dup;
}

// int main(void)
// {
// 	char *src = "bonjour    sa";
// 	char* test = strdup(src);

// 	printf("%s",test);
// 	free(test);
// }