/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhashan <hkhashan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 21:12:39 by hkhashan          #+#    #+#             */
/*   Updated: 2026/11/21 12:51:01 by hkhashan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_sa(t_data *ps, int print)
{
	if (!ps || !ps->a || !ps->a->next)
		return ;
	swap(&ps->a);
	ps->bench.sa++;
	ps->bench.total_ops++;
	if (print)
		write(1, "sa\n", 3);
}

void	op_sb(t_data *ps, int print)
{
	if (!ps || !ps->b || !ps->b->next)
		return ;
	swap(&ps->b);
	ps->bench.sb++;
	ps->bench.total_ops++;
	if (print)
		write(1, "sb\n", 3);
}

void	op_ss(t_data *ps, int print)
{
	if (!ps)
		return ;
	if ((!ps->a || !ps->a->next) && (!ps->b || !ps->b->next))
		return ;
	swap(&ps->a);
	swap(&ps->b);
	ps->bench.ss++;
	ps->bench.total_ops++;
	if (print)
		write(1, "ss\n", 3);
}
