/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:55:30 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/05/27 21:22:56 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_a_to_b(t_dlist **stack_a, t_dlist **stack_b, int length)
{
	int		pivot;
	int		ra_cnt;
	int		pb_cnt;
	int		i;

//	printf("atob\n");
	if (length < 2)
		return ;
	if (check_ascending(*stack_a, length))
		return ;
	pivot = (*stack_a)->num;
	ra_cnt = 0;
	pb_cnt = 0;
	while (length--)
	{
		if ((*stack_a)->num > pivot)
		{
			op_ra(stack_a);
			ra_cnt++;
		}
		else
		{
			op_pb(stack_a, stack_b);
			pb_cnt++;
		}
	}
	i = 0;
	while (i++ < ra_cnt)
		op_rra(stack_a);
/*
	printf("A : ");
	print_stack(*stack_a);
	printf("\nB : ");
	print_stack(*stack_b);
	printf("\n");
*/

	ft_a_to_b(stack_a, stack_b, ra_cnt);
	ft_b_to_a(stack_a, stack_b, pb_cnt);
}

void	ft_b_to_a(t_dlist **stack_a, t_dlist **stack_b, int length)
{
	int		pivot;
	int		rb_cnt;
	int		pa_cnt;
	int		i;

//	printf("btoa\n");
	if (length < 2)
	{
		op_pa(stack_a, stack_b);
		return ;
	}
	if (check_descending(*stack_b, length))
	{
		while (length--)
			op_pa(stack_a, stack_b);
		return ;
	}
	pivot = (*stack_b)->num;
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
/*
	printf("A : ");
	print_stack(*stack_a);
	printf("\nB : ");
	print_stack(*stack_b);
	printf("\n");
*/

	ft_a_to_b(stack_a, stack_b, pa_cnt);
	ft_b_to_a(stack_a, stack_b, rb_cnt);
}
