/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:58:45 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/05/27 21:14:56 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

extern int	result;

void	op_pa(t_dlist **stack_a, t_dlist **stack_b)
{
	push_node(stack_a, pop_node(stack_b));
	printf("pa\n");
	result++;
}

void	op_pb(t_dlist **stack_a, t_dlist **stack_b)
{
	push_node(stack_b, pop_node(stack_a));
	printf("pb\n");
	result++;
}
