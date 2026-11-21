/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhashan <hkhashan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 21:12:24 by hkhashan          #+#    #+#             */
/*   Updated: 2026/11/21 12:50:34 by hkhashan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_pa(t_data *ps, int print)
{
	t_list	*temp;

	if (!ps || !ps->b)
		return ;
	temp = ps->b;
	ps->b = ps->b->next;
	temp->next = ps->a;
	ps->a = temp;
	ps->size_b--;
	ps->size_a++;
	ps->bench.pa++;
	ps->bench.total_ops++;
	if (print)
		write(1, "pa\n", 3);
}

void	op_pb(t_data *ps, int print)
{
	t_list	*temp;

	if (!ps || !ps->a)
		return ;
	temp = ps->a;
	ps->a = ps->a->next;
	temp->next = ps->b;
	ps->b = temp;
	ps->size_a--;
	ps->size_b++;
	ps->bench.pb++;
	ps->bench.total_ops++;
	if (print)
		write(1, "pb\n", 3);
}
