/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:02:20 by vanfossi          #+#    #+#             */
/*   Updated: 2024/11/10 13:54:40 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	j;

	j = -1;
	i = 0;
	if (!ft_isascii(c))
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			j = i;
		i++;
	}
	if (c == '\0')
		return ((char *)s + i);
	if (j == -1)
		return (0);
	return ((char *)s + j);
}

// int main (void)
// {
// 	printf("%s", ft_strrchr("jorjorj",'d'));
// }