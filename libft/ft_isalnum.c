/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:28:17 by vanfossi          #+#    #+#             */
/*   Updated: 2024/11/04 11:40:32 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int isalnum(int c)
{
    if((c >= 'a' && c <= 'z')||(c >= 'A' && c <= 'Z'))
        return 1;
    else if(c >= '0' && c <= '9')
        return 1;
    else
        return 0;
}