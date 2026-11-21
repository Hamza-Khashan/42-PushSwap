/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhashan <hkhashan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 21:12:32 by hkhashan          #+#    #+#             */
/*   Updated: 2026/11/21 12:53:33 by hkhashan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rra(t_data *ps, int print)
{
	if (!ps || !ps->a || !ps->a->next)
		return ;
	rev_rotate(&ps->a);
	ps->bench.rra++;
	ps->bench.total_ops++;
	if (print)
		write(1, "rra\n", 4);
}

void	op_rrb(t_data *ps, int print)
{
	if (!ps || !ps->b || !ps->b->next)
		return ;
	rev_rotate(&ps->b);
	ps->bench.rrb++;
	ps->bench.total_ops++;
	if (print)
		write(1, "rrb\n", 4);
}

void	op_rrr(t_data *ps, int print)
{
	if (!ps)
		return ;
	if ((!ps->a || !ps->a->next) && (!ps->b || !ps->b->next))
		return ;
	rev_rotate(&ps->a);
	rev_rotate(&ps->b);
	ps->bench.rrr++;
	ps->bench.total_ops++;
	if (print)
		write(1, "rrr\n", 4);
}
