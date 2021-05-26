/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:40:29 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/05/26 19:21:22 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	op_sa(t_dlist *stack_a)
{
	int		tmp;

	if (!stack_a)
		return ;
	tmp = stack_a->num;
	stack_a->num = stack_a->next->num;
	stack_a->next->num = tmp;
}

void	op_sb(t_dlist *stack_b)
{
	int		tmp;

	if (!stack_b)
		return ;
	tmp = stack_b->num;
	stack_b->num = stack_b->next->num;
	stack_b->next->num = tmp;
}

void	op_ss(t_dlist *stack_a, t_dlist *stack_b)
{
	op_sa(stack_a);
	op_sb(stack_b);
}
