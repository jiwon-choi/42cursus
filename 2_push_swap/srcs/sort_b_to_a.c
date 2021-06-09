/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:55:30 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/06/09 13:34:58 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_b_to_a(t_dlist **stack_a, t_dlist **stack_b, int length)
{
	int		pivot;
	int		rb_cnt;
	int		pa_cnt;
	int		i;

	if (length < 2)
	{
		op_pa(stack_a, stack_b);
		return ;
	}
	if (length == 2 && check_ascending(*stack_b, length))
		op_sb(*stack_b);
	if (check_descending(*stack_b, length))
	{
		while (length--)
			op_pa(stack_a, stack_b);
		return ;
	}
	pivot = ft_setup_pivot(*stack_b, length);
	rb_cnt = 0;
	pa_cnt = 0;
	while (length--)
	{
		if ((*stack_b)->num > pivot)
		{
			op_pa(stack_a, stack_b);
			pa_cnt++;
		}
		else
		{
			op_rb(stack_b);
			rb_cnt++;
		}
	}
	i = 0;
	while (i++ < rb_cnt)
		op_rrb(stack_b);
	if (pa_cnt == 0)
	{
		op_pa(stack_a, stack_b);
		pa_cnt++;
		rb_cnt--;
	}
	ft_a_to_b(stack_a, stack_b, pa_cnt);
	ft_b_to_a(stack_a, stack_b, rb_cnt);
}
