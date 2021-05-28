/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:52:23 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/05/28 19:17:41 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	op_rra(t_dlist **stack_a)
{
	if (!*stack_a)
		return ;
	*stack_a = (*stack_a)->prev;
	write(1, "rra\n", 4);
}

void	op_rrb(t_dlist **stack_b)
{
	if (!*stack_b)
		return ;
	*stack_b = (*stack_b)->prev;
	write(1, "rrb\n", 4);
}

void	op_rrr(t_dlist **stack_a, t_dlist **stack_b)
{
	op_rra(stack_a);
	op_rrb(stack_b);
}
