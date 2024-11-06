/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:54:36 by vanfossi          #+#    #+#             */
/*   Updated: 2024/11/05 21:54:36 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTH
# define LIBFTH

#include <stdlib.h>
#include <unistd.h>

typedef typeof(sizeof(0)) size_t; 

size_t ft_strlen(const char *s);

#endif