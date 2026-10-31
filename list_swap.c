/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhashan <hkhashan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 14:26:36 by hkhashan          #+#    #+#             */
/*   Updated: 2026/10/31 15:29:09 by hkhashan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_list **lst)
{
    t_list *temp;

    temp = (*lst)->next;
    (*lst)->next = *lst;
    lst = temp;
}

void shift(t_list **)
{
    
}