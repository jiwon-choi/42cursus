/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 13:30:57 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/05/25 16:55:38 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PUSH_SWAP_H
# define _PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_dlist
{
	int				num;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}				t_dlist;

int			ft_atoi(char *str);

void		ft_error(void);

void		op_pa(t_dlist **stack_a, t_dlist **stack_b);
void		op_pb(t_dlist **stack_a, t_dlist **stack_b);

void		op_rra(t_dlist **stack_a);
void		op_rrb(t_dlist **stack_b);
void		op_rrr(t_dlist **stack_a, t_dlist **stack_b);

void		op_ra(t_dlist **stack_a);
void		op_rb(t_dlist **stack_b);
void		op_rr(t_dlist **stack_a, t_dlist **stack_b);

t_dlist		*create_node(int input);
void		push_node(t_dlist **lst, t_dlist *node);
t_dlist		*pop_node(t_dlist **lst);

void		op_sa(t_dlist *stack_a);
void		op_sb(t_dlist *stack_b);
void		op_ss(t_dlist *stack_a, t_dlist *stack_b);

#endif
