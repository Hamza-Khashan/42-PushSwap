/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhashan <hkhashan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 14:05:01 by hkhashan          #+#    #+#             */
/*   Updated: 2026/11/11 20:48:33 by hkhashan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

t_list			*ft_lstnew(int content);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			push(t_list **lst, t_list *new);
void			pop(t_list **lst);
void			swap(t_list **lst);
void			rotate(t_list **lst);
void			rev_rotate(t_list **lst);
char			**ft_split(char const *s, char c);

#endif