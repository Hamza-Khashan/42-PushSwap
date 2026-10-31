/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhashan <hkhashan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 14:18:28 by hkhashan          #+#    #+#             */
/*   Updated: 2026/10/31 17:14:40 by hkhashan         ###   ########.fr       */
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

void	push_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
    new->next = *lst;
	*lst = new;
}

void pop_back(t_list **lst)
{
	t_list *temp;
    if (!(*lst))
		return (NULL);
	temp = (*lst);
	lst = lst->next;
	// while ((*lst)->next != NULL)
	// 	*lst = (*lst)->next;
	// free((*lst)->content);
    // free(*lst);
}
