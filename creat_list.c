/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhashan <hkhashan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 14:18:28 by hkhashan          #+#    #+#             */
/*   Updated: 2026/11/02 17:12:17 by hkhashan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

void	push(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	pop(t_list **lst)
{
	t_list	*temp;

	if (!(*lst))
		return ;
	temp = (*lst);
	(*lst) = (*lst)->next;
	free((temp)->content);
	free(temp);
}

void	swap(t_list **lst)
{
	t_list	*first_node;
	t_list	*second_node;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	first_node = *lst;
	second_node = (*lst)->next;
	(*lst) = second_node;
	first_node->next = second_node->next;
	(*lst)->next = first_node;
}

void	rotate(t_list **lst)
{
	t_list	*last_node;
	t_list	*first_node;

	last_node = *lst;
	first_node = *lst;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->next = first_node;
	*lst = (*lst)->next;
	first_node->next = NULL;
}

void	rev_rotate(t_list **lst)
{
	t_list	*last_node;
	t_list	*prev_last;

	last_node = *lst;
	prev_last = *lst;
	while (prev_last->next->next != NULL)
		prev_last = prev_last->next;
	last_node = prev_last->next;
	last_node->next = (*lst);
	prev_last->next = NULL;
	(*lst) = last_node;
}
