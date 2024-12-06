/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stackgenerator.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 11:28:03 by vanfossi          #+#    #+#             */
/*   Updated: 2024/11/25 13:10:54 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_duplicate(int n, int *a);

void print_stack(int *a) {
    int i;

	i = 0;
	while(i < STACKSIZE)
	{
        printf("%d ", a[i]);
		i ++;
    }
}

// int main(void) {
//     srand(time(NULL));
//     int i;
//     int r;
//     int *a;

// 	i = 0;
//     a = malloc(sizeof(int) * STACKSIZE);
//     while (i < STACKSIZE) {
//         a[i] = -1;
// 		i ++;
//     }
// 	i = 0;
//     while (i < STACKSIZE) {
//         r = rand() % STACKSIZE;
//         if (!check_duplicate(r, a)) {
//             a[i] = r;
//             i++;
//         }
//     }
//     print_stack(a);
//     free(a);
//     return 0;
// }

int check_duplicate(int n, int *a) {
    int i = 0;
    while (i < STACKSIZE) {
        if (a[i] == n) {
            return 1;
        }
        i++;
    }
    return 0;
}