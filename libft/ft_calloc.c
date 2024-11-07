/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:11:29 by vanfossi          #+#    #+#             */
/*   Updated: 2024/11/05 19:11:29 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include"libft.h"

void *ft_calloc(size_t nmemb, size_t size)
{
	if(nmemb == 0 || size == 0)
		return (0);
	else
		return (malloc(nmemb * size));
}

int main (void)
{
	void *test = calloc(0,0);
	free(test);
}