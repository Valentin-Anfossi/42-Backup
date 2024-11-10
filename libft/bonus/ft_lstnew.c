/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 01:27:05 by vanfossi          #+#    #+#             */
/*   Updated: 2024/11/10 01:27:06 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"
#include <stdio.h>

typedef struct s_list
{
void *content;
struct s_list *next;
} t_list;

t_list *ft_lstnew(void *content)
{
	t_list * newlst = (t_list *)malloc(sizeof(t_list));
	newlst->content = malloc(sizeof(content));
	newlst->content = content;
	newlst->next = NULL;
	return (newlst);
}