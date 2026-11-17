/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhashan <hkhashan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 14:40:38 by hkhashan          #+#    #+#             */
/*   Updated: 2026/11/17 16:01:30 by hkhashan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    bubble_sort(t_list **stack_a)
{
    int end;
    int i;

    end = ft_lstsize(*stack_a);
    while (end > 1)
    {
        i = 0;
        while (i < end - 1)
        {
            if ((*stack_a)->content > (*stack_a)->next->content)
            {
                swap(stack_a);
                printf("sa\n");
            }
            rotate(stack_a);
            printf("ra\n");
            i++;
        }
        i = 0;
        while (i < end - 1)
        {
            rev_rotate(stack_a);
            printf("rra\n");
            i++;
        }
        end--;
    }
}