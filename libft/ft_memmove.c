/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:33:03 by vanfossi          #+#    #+#             */
/*   Updated: 2024/11/08 13:44:49 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*charsrc;
	char	*chardest;
	char	*temp;
	size_t	i;

	charsrc = (char *)src;
	chardest = (char *)dest;
	i = 0;
	while (i < n)
	{
		temp[i] = charsrc[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		chardest[i] = temp[i];
		i++;
	}
	return (chardest);
}
