/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:43:59 by vanfossi          #+#    #+#             */
/*   Updated: 2024/11/05 13:43:59 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_toupper(int c)
{
	if((c >= 'a')&&(c <= 'z'))
		return (c - 32);
	else
		return (c);
}

// int main (void)
// {
// 	printf("test:%c",ft_toupper('c'));
// }