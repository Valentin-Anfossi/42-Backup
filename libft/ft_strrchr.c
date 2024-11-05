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

#include<stdio.h>

char *ft_strrchr(const char *s, int c)
{
	int i;
	char *r;
	
	r = 0;
	i = 0;
	while (s[i])
	{
		if(s[i] == c)
			r = (char *)&s[i];
	i++;
	}
	return (r);
}

int main (void)
{
	printf("%s", ft_strrchr("jorjorj",'d'));
}