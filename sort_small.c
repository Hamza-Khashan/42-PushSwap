/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhashan <hkhashan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 13:30:18 by hkhashan          #+#    #+#             */
/*   Updated: 2026/11/21 13:30:22 by hkhashan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_data *data)
{
	int	a;
	int	b;
	int	c;

	if (!data || data->size_a != 3)
		return ;
	a = data->a->content;
	b = data->a->next->content;
	c = data->a->next->next->content;
	if (a > b && b < c && a < c)
		op_sa(data, 1);
	else if (a > b && b > c)
	{
		op_sa(data, 1);
		op_rra(data, 1);
	}
	else if (a > b && b < c && a > c)
		op_ra(data, 1);
	else if (a < b && b > c && a < c)
	{
		op_sa(data, 1);
		op_ra(data, 1);
	}
	else if (a < b && b > c && a > c)
		op_rra(data, 1);
}

void	sort_five(t_data *data)
{
	if (!data || data->size_a < 4 || data->size_a > 5)
		return ;
	while (data->size_a > 3)
	{
		move_min_to_top(data);
		op_pb(data, 1);
	}
	sort_three(data);
	while (data->size_b > 0)
		op_pa(data, 1);
}
