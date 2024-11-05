/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:53:58 by vanfossi          #+#    #+#             */
/*   Updated: 2024/11/05 13:53:58 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_tolower(int c)
{
	if((c >= 'a')&&(c <= 'z'))
		return (c - 32);
	else
		return (c);
}

int main (void)
{
	printf("test:%c",ft_tolower('c'));
}