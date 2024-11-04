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

typedef typeof(sizeof(0)) size_t; 

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    int i;
    unsigned char *d;
    unsigned char *s;
    
    i = 0;
    while(i < n)
    {
        *d = *s;
        d++;
        s++;
    }

    return (dest);
}