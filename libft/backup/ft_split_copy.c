/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:30:42 by vanfossi          #+#    #+#             */
/*   Updated: 2024/11/06 12:30:42 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include"ft_strlen.c"
#include<stdio.h>

static int ft_split_count(char const *s, char c)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while(s[i])
	{
		if(s[i] == c)
			count ++;
		i++;
	}
	printf("flag");
	return (count+1);
}

// static char **ft_the_mallocator(char const *s,char c)
// {
// 	int count;
// 	char **array;
// 	int i;

// 	i = 0;
// 	count = ft_split_count(s,c);
// 	array = (char**)malloc(count * sizeof(char));
// 	while(i<count)
// 	{
// 		array[i] = (char*)malloc(ft_strlen(s) + 1 * sizeof(char));
// 		i++;
// 	}
// 	return (array);
// }

char **ft_split(char const *s, char c)
{
	char **array;
	int i;
	int j;
	int k;
	int count;

	i = 0;
	k = 0;
	j = 0;
	//array = ft_the_mallocator(s,c);
	count = ft_split_count(s,c);
	array = (char**)malloc(count * sizeof(char*));
	while(i<count)
	{
		array[i] = (char*)malloc((ft_strlen(s) + 1) * sizeof(char));
		i++;
	}
	i = 0;
	while(s[i])
	{
		if(s[i] == c)
		{
			j++;
			i++;
			k = 0;
			continue;
		}
		else
		{
			array[j][k] = s[i];
			k++;
			i++;
		}
		array[j][k] = 0;
	}
	array[j+1] = 0;
	return array;
}

int main(void)
{
	
	char **array = ft_split("sa/dd/kdsj/bousaads/aakdldaskjl",'/');
	int i = 0;
	while(array[i])
	{
		printf("%s/",array[i]);
		i++;
	}
	//free(array);
	return(1);
}