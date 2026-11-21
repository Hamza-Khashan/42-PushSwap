/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhashan <hkhashan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 21:12:36 by hkhashan          #+#    #+#             */
/*   Updated: 2026/11/21 12:53:17 by hkhashan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_ra(t_data *ps, int print)
{
	if (!ps || !ps->a || !ps->a->next)
		return ;
	rotate(&ps->a);
	ps->bench.ra++;
	ps->bench.total_ops++;
	if (print)
		write(1, "ra\n", 3);
}

void	op_rb(t_data *ps, int print)
{
	if (!ps || !ps->b || !ps->b->next)
		return ;
	rotate(&ps->b);
	ps->bench.rb++;
	ps->bench.total_ops++;
	if (print)
		write(1, "rb\n", 3);
}

void	op_rr(t_data *ps, int print)
{
	if (!ps)
		return ;
	if ((!ps->a || !ps->a->next) && (!ps->b || !ps->b->next))
		return ;
	rotate(&ps->a);
	rotate(&ps->b);
	ps->bench.rr++;
	ps->bench.total_ops++;
	if (print)
		write(1, "rr\n", 3);
}
