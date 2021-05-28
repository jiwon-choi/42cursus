/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:52:23 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/05/28 17:42:30 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

extern int	result;

void	op_rra(t_dlist **stack_a)
{
	if (!*stack_a)
		return ;
	*stack_a = (*stack_a)->prev;
	printf("rra\n");
	result++;
}

void	op_rrb(t_dlist **stack_b)
{
	if (!*stack_b)
		return ;
	*stack_b = (*stack_b)->prev;
	printf("rrb\n");
	result++;
}

void	op_rrr(t_dlist **stack_a, t_dlist **stack_b)
{
	op_rra(stack_a);
	op_rrb(stack_b);
}
