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
	i = -1;
	while(s[++i])
		if(s[i] == c)
			count ++;
	return (count+1);
}

static char **ft_the_mallocator(char const *s,char c)
{
	int count;
	char **array;
	int i;

	i = 0;
	count = ft_split_count(s,c);
	array = (char**)malloc((count + 1) * sizeof(char*));
	while(i<count)
	{
		array[i] = (char*)malloc(ft_strlen(s) + 1 * sizeof(char));
		i++;
	}
	if(!array)
		return (NULL);
	return (array);
}

// char **ft_split(char const *s, char c)
// {
// 	char **array;
// 	int i;
// 	int j;
// 	int k;

// 	i = 0;
// 	k = 0;
// 	j = 0;
// 	array = ft_the_mallocator(s,c);
// 	while(s[i])
// 	{
// 		if(s[i] == c)
// 		{
// 			j++;
// 			i++;
// 			k = 0;
// 			continue;
// 		}
// 		else
// 		{
// 			array[j][k] = s[i];
// 			k++;
// 			i++;
// 		}
// 		array[j][k] = 0;
// 	}
// 	array[j+1] = 0;
// 	return array;
// }

// char **ft_split(char const *s, char c)
// {
// 	char **array = ft_the_mallocator(s, c);
// 	int i = 0, j = 0, k = 0;

// 	while (s[i])
// 	{
// 		if (s[i] == c)
// 		{
// 			array[j][k] = 0;
// 			j++;
// 			k = 0;
// 		}
// 		else
// 			array[j][k++] = s[i];
// 		i++;
// 	}
// 	array[j + 1] = 0;
// 	return array;
// }

char **ft_split(char const *s, char c)
{
	char **array = ft_the_mallocator(s, c);
	int i = 0, j = 0, k = 0;

	while (s[i])
	{
		if (s[i] == c)
		{
			if (k > 0) 
				array[j++][k] = 0;
			k = 0;
		}
		else
			array[j][k++] = s[i];
		i++;
	}
	if (k > 0) 
		array[j++][k] = 0;
	array[j] = 0;
	return array;
}

int main(void)
{
	
	char **array = ft_split("sa/dd/kdsj/bou//aa/ds/aakdldaskjl",'/');
	int i = 0;
	while(array[i])
	{
		printf("%s\n",array[i]);
		i++;
	}
	free(array);
	return(1);
}