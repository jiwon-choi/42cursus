/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   descend_to_ascend.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:17:53 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/06/09 14:39:56 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	descend_to_ascend(t_dlist **stack_a, t_dlist **stack_b, int length)
{
	int		i;

	i = length - 1;
	while (i--)
		op_pb(stack_a, stack_b);
	i = length - 1;
	while (i--)
	{
		op_pa(stack_a, stack_b);
		op_ra(stack_a);
	}
}
