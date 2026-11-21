/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhashan <hkhashan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 14:05:01 by hkhashan          #+#    #+#             */
/*   Updated: 2026/11/21 15:08:01 by hkhashan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_strategy
{
	STRAT_ADAPTIVE,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX
}					t_strategy;

typedef enum e_complexity
{
	C_SIMPLE,
	C_MEDIUM,
	C_COMPLEX
}					t_complexity;

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}					t_list;

typedef struct s_bench
{
	int				enabled;
	t_strategy		mode;
	t_complexity	complexity;
	double			disorder;
	int				total_ops;
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
}					t_bench;

typedef struct s_data
{
	t_list			*a;
	t_list			*b;
	int				size_a;
	int				size_b;
	t_bench			bench;
}					t_data;

t_list				*ft_lstnew(int content);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				swap(t_list **lst);
void				rotate(t_list **lst);
void				rev_rotate(t_list **lst);
char				**ft_split(char const *s, char c);
int					ft_lstsize(t_list *lst);
int					is_sorted(t_list *stack);
int					get_min_pos(t_list *stack);
void				move_min_to_top(t_data *data);
void				simple_sort(t_data *data);
void				sort_three(t_data *data);
void				sort_five(t_data *data);
void				op_pa(t_data *ps, int print);
void				op_pb(t_data *ps, int print);
void				op_sb(t_data *ps, int print);
void				op_sa(t_data *ps, int print);
void				op_ss(t_data *ps, int print);
void				op_ra(t_data *ps, int print);
void				op_rb(t_data *ps, int print);
void				op_rr(t_data *ps, int print);
void				op_rra(t_data *ps, int print);
void				op_rrb(t_data *ps, int print);
void				op_rrr(t_data *ps, int print);

#endif