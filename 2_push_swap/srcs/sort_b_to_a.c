/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:55:30 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/06/10 15:05:16 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		length_3(t_dlist **stack_a, t_dlist **stack_b)
{
	int		min;

	min = ft_min(*stack_b);
	if ((*stack_b)->next->num == ft_max(*stack_b))
		op_sb(*stack_b);
	if ((*stack_b)->num == ft_max(*stack_b))
	{
		op_pa(stack_a, stack_b);
		if ((*stack_b)->num == min)
			op_sb(*stack_b);
		op_pa(stack_a, stack_b);
		op_pa(stack_a, stack_b);
	}
	else
	{
		op_pa(stack_a, stack_b);
		op_sb(*stack_b);
		op_pa(stack_a, stack_b);
		op_sa(*stack_a);
		op_pa(stack_a, stack_b);
		if ((*stack_a)->num != min)
			op_sa(*stack_a);
	}
}

static t_bool	except_case(t_dlist **stack_a, t_dlist **stack_b, int length)
{
	if (length == 3)
	{
		length_3(stack_a, stack_b);
		return (TRUE);
	}
	if (length == 2 && check_ascending(*stack_b, length))
	{
		op_sb(*stack_b);
		op_pa(stack_a, stack_b);
		op_pa(stack_a, stack_b);
		return (TRUE);
	}
	if (check_descending(*stack_b, length))
	{
		while (length--)
			op_pa(stack_a, stack_b);
		return (TRUE);
	}
	return (FALSE);
}

void			ft_b_to_a(t_dlist **stack_a, t_dlist **stack_b, int length)
{
	int		pivot;
	int		rb_cnt;
	int		pa_cnt;
	int		i;

	if (except_case(stack_a, stack_b, length))
		return ;
	pivot = ft_setup_pivot(*stack_b, length);
	rb_cnt = 0;
	pa_cnt = 0;
	while (length--)
	{
		if ((*stack_b)->num >= pivot && ++pa_cnt)
			op_pa(stack_a, stack_b);
		else if ((*stack_b)->num < pivot && ++rb_cnt)
			op_rb(stack_b);
	}
	i = 0;
	while (i++ < rb_cnt)
		op_rrb(stack_b);
	ft_a_to_b(stack_a, stack_b, pa_cnt);
	ft_b_to_a(stack_a, stack_b, rb_cnt);
}
