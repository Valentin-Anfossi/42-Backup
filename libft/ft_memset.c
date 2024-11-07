/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:50:41 by vanfossi          #+#    #+#             */
/*   Updated: 2024/11/04 11:56:59 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void ft_memset(void *s, int c, size_t n)
{
	int i;
	unsigned char *p;
	
	p = s;
	i = 0;
	while(i < n)
	{
		*p = c;
		p++;
		i++;
	}
	return s;
}