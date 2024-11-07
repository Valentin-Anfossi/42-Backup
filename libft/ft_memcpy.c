/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:21:46 by vanfossi          #+#    #+#             */
/*   Updated: 2024/11/04 13:27:53 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	char *charsrc;
	char *chardest;
	int i;

	charsrc = (char *)src;
	chardest = (char *)dest;
	i = 0;
	while(i < n)
	{
		chardest[i] = charsrc[i];
		i++;
	}
}