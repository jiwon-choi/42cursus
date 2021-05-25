/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:46:47 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/05/25 16:57:31 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	op_ra(t_dlist **stack_a)
{
	*stack_a = (*stack_a)->next;
}

void	op_rb(t_dlist **stack_b)
{
	*stack_b = (*stack_b)->next;
}

void	op_rr(t_dlist **stack_a, t_dlist **stack_b)
{
	op_ra(stack_a);
	op_rb(stack_b);
}
