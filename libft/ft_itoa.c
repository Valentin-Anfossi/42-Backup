/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:33:10 by vanfossi          #+#    #+#             */
/*   Updated: 2024/11/06 15:33:10 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdio.h>
#include"ft_strlen.c"

static int ft_itoa_size(int n)
{
	int count;
	
	count = 1;
	while (n > 9)
	{
		count ++;
		n /= 10;
		continue;
	}
	if(n < 0)
		count ++;
	return count;
}

static char *ft_itoa_mallocu(int n)
{
	char *string;
	if(n < 0)
	{
		string = malloc ((ft_itoa_size(n) + 2) * sizeof(char));
		string[0] = '-';
	}
	else
		string = malloc ((ft_itoa_size(n) + 1) * sizeof(char));
	if (!string)
		return (0);
	return (string);
}

static char* ft_itoa_helper(int n, int n2, char *s)
{
	if(s[0] == '-')
	{
		s[1] = n + 48;
		s[ft_itoa_size(n2)+1] = 0;
	}
	else
	{
		s[0] = n + 48;
		s[ft_itoa_size(n2)] = 0;
	}
	return (s);
}

char *ft_itoa(int n)
{
	char *string;
	int i;
	int n2;
	
	i = 0;
	string = ft_itoa_mallocu(n);
	if(n < 0)
	{	
		n *= -1;
		i = -1;
	}
	n2 = n;
	while(n>9)
	{
		string[ft_itoa_size(n2)-i++-1] = (n % 10) + 48;
		n /= 10;
	}
	string = ft_itoa_helper(n, n2, string);
	return (string);
}

int main(void)
{
	printf("%s",ft_itoa(0));
}