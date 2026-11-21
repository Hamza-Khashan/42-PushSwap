/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhashan <hkhashan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 14:08:37 by hkhashan          #+#    #+#             */
/*   Updated: 2026/11/21 15:31:30 by hkhashan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_data(t_data *data)
{
	data->a = NULL;
	data->b = NULL;
	data->size_a = 0;
	data->size_b = 0;
	data->bench.enabled = 0;
	data->bench.mode = STRAT_ADAPTIVE;
	data->bench.complexity = C_SIMPLE;
	data->bench.disorder = 0.0;
	data->bench.total_ops = 0;
	data->bench.sa = 0;
	data->bench.sb = 0;
	data->bench.ss = 0;
	data->bench.pa = 0;
	data->bench.pb = 0;
	data->bench.ra = 0;
	data->bench.rb = 0;
	data->bench.rr = 0;
	data->bench.rra = 0;
	data->bench.rrb = 0;
	data->bench.rrr = 0;
}

int	ft_atoi(const char *nptr, int *error)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	sign = 1;
	num = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	if (!nptr[i] || nptr[i] < '0' || nptr[i] > '9')
		return (*error = 1, 0);
	while (nptr[i])
	{
		if (nptr[i] < '0' || nptr[i] > '9')
			return (*error = 1, 0);
		num = (num * 10) + (nptr[i] - '0');
		if ((num * sign) > INT_MAX || (num * sign) < INT_MIN)
			return (*error = 1, 0);
		i++;
	}
	return ((int)num * sign);
}

void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_stack(t_list **stack)
{
	t_list	*temp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

int	has_duplicate(t_list *stack, int num)
{
	while (stack)
	{
		if (stack->content == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static void	create_list(char **args, t_data *data, int i, int *error)
{
	int		val;
	t_list	*node;

	if (!args || !args[i])
	{
		*error = 1;
		return ;
	}
	while (args[i])
	{
		val = ft_atoi(args[i], error);
		if (*error || has_duplicate(data->a, val))
		{
			*error = 1;
			return ;
		}
		node = ft_lstnew(val);
		if (!node)
		{
			*error = 1;
			return ;
		}
		ft_lstadd_back(&data->a, node);
		data->size_a++;
		i++;
	}
}

double	compute_disorder(t_list *stack)
{
	double	mistakes;
	double	total_pairs;
	t_list	*j;

	mistakes = 0;
	total_pairs = 0;
	while (stack)
	{
		j = stack->next;
		while (j)
		{
			total_pairs += 1;
			if (stack->content > j->content)
				mistakes += 1;
			j = j->next;
		}
		stack = stack->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return (mistakes / total_pairs);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_list	*temp;
	char	**arr;
	int		error;

	if (argc < 2)
		return (0);
	init_data(&data);
	arr = NULL;
	error = 0;
	if (argc == 2)
	{
		arr = ft_split(argv[1], ' ');
		create_list(arr, &data, 0, &error);
		free_split(arr);
	}
	else
		create_list(argv, &data, 1, &error);
	if (error)
	{
		free_stack(&data.a);
		write(2, "Error\n", 6);
		return (1);
	}
	data.bench.disorder = compute_disorder(data.a);
	simple_sort(&data);
	temp = data.a;
	while (temp)
	{
		printf("%d ", temp->content);
		temp = temp->next;
	}
	free_stack(&data.a);
	free_stack(&data.b);
	return (0);
}
