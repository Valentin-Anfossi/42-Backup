/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:57:17 by vanfossi          #+#    #+#             */
/*   Updated: 2024/11/04 13:21:30 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

typedef typeof(sizeof(0)) size_t; 

void    ft_bzero(void *s, size_t n)
{
    size_t i;
    unsigned char *c;

    c = s;
    i = 0;
    while (i < n)
    {
        *c = '\0';
        c++;
        i++;
    }
}