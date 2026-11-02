/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhashan <hkhashan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 14:08:37 by hkhashan          #+#    #+#             */
/*   Updated: 2026/11/02 17:13:41 by hkhashan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc,char **argv)
{
    int i = 0;
    char **arr = ft_split(argv[1], ' ');
    t_list *stack_a;
    t_list *stack_b;

    stack_b = NULL;
    stack_a = NULL;
    while (arr[i])
    {
        push(&stack_a, ft_lstnew(arr[i]));
        i++;
    }
    t_list *temp1 = stack_a;
    while (temp1)
    {
        printf("%s\n", (char *)temp1->content);
        temp1 = temp1->next;
    }
    write(1, "\n\n\n",3);
    // pop(&stack_a);
    // swap(&stack_a);
    // rotate(&stack_a);
    rev_rotate(&stack_a);
    rev_rotate(&stack_a);
    temp1 = stack_a;
    while (temp1)
    {
        printf("%s\n", (char *)temp1->content);
        temp1 = temp1->next;
    }

}