/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhashan <hkhashan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 14:40:38 by hkhashan          #+#    #+#             */
/*   Updated: 2026/11/21 13:29:22 by hkhashan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	get_min_pos(t_list *stack)
{
	int	min;
	int	min_pos;
	int	i;

	min = stack->content;
	min_pos = 0;
	i = 0;
	while (stack)
	{
		if (stack->content < min)
		{
			min = stack->content;
			min_pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (min_pos);
}

void	move_min_to_top(t_data *data)
{
	int	pos;
	int	moves;

	pos = get_min_pos(data->a);
	if (pos <= data->size_a / 2)
	{
		while (pos-- > 0)
			op_ra(data, 1);
	}
	else
	{
		moves = data->size_a - pos;
		while (moves-- > 0)
			op_rra(data, 1);
	}
}

void	simple_sort(t_data *data)
{
	if (!data || data->size_a < 2 || is_sorted(data->a))
		return ;
	if (data->size_a == 2)
	{
		op_sa(data, 1);
		return ;
	}
	while (data->size_a > 3 && !is_sorted(data->a))
	{
		move_min_to_top(data);
		op_pb(data, 1);
	}
	if (!is_sorted(data->a))
		sort_three(data);
	while (data->size_b > 0)
		op_pa(data, 1);
}
