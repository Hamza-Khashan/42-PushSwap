/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhashan <hkhashan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 14:08:37 by hkhashan          #+#    #+#             */
/*   Updated: 2026/11/17 14:58:46 by hkhashan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	print_stack(t_list *stack, char name)
{
	printf("Stack %c: ", name);
	while (stack)
	{
		printf("%d ", stack->content);
		stack = stack->next;
	}
	printf("\n");
}

void	create_list(char **args, t_list **stack, int i, int *error)
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
		if (*error || has_duplicate(*stack, val))
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
		ft_lstadd_back(stack, node);
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
	return (mistakes / total_pairs);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*temp;
	char	**arr;
	int		error;
	double	disorder;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	arr = NULL;
	error = 0;
	if (argc == 2)
	{
		arr = ft_split(argv[1], ' ');
		create_list(arr, &stack_a, 0, &error);
	}
	else
		create_list(argv, &stack_a, 1, &error);
	if (error)
	{
		free_stack(&stack_a);
		write(2, "Error\n", 6);
		return (1);
	}
	temp = stack_a;
	disorder = compute_disorder(temp);
	temp = stack_a;
	print_stack(temp, 'a');
	temp = stack_a;
	bubble_sort(&temp);
	print_stack(temp, 'a');
	free_stack(&stack_a);
	printf("disorder: %f", disorder);
	return (0);
}
