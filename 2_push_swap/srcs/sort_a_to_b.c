/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 19:49:20 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/06/10 15:07:04 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		length_3(t_dlist **stack_a, t_dlist **stack_b)
{
	if (check_ascending(*stack_a, 3))
		return ;
	if ((*stack_a)->next->next->num == ft_max(*stack_a))
	{
		op_sa(*stack_a);
		return ;
	}
	if ((*stack_a)->num == ft_max(*stack_a))
		op_sa(*stack_a);
	if ((*stack_a)->num == ft_min(*stack_a))
	{
		op_ra(stack_a);
		op_sa(*stack_a);
		op_rra(stack_a);
	}
	else
	{
		op_pb(stack_a, stack_b);
		op_sa(*stack_a);
		op_ra(stack_a);
		op_pa(stack_a, stack_b);
		op_rra(stack_a);
	}
}

static t_bool	except_case(t_dlist **stack_a, t_dlist **stack_b, int length)
{
	if (length == 2 && check_descending(*stack_a, length))
		op_sa(*stack_a);
	if (length == 3 && stack_size(*stack_a) == 3)
		only_3(stack_a);
	else if (length == 3)
		length_3(stack_a, stack_b);
	if (check_ascending(*stack_a, length))
		return (TRUE);
	return (FALSE);
}

void			ft_a_to_b(t_dlist **stack_a, t_dlist **stack_b, int length)
{
	int			pivot;
	int			ra_cnt;
	int			pb_cnt;
	int			i;
	static int	first;

	if (except_case(stack_a, stack_b, length))
		return ;
	pivot = ft_setup_pivot(*stack_a, length);
	ra_cnt = 0;
	pb_cnt = 0;
	while (length--)
	{
		if ((*stack_a)->num >= pivot && ++ra_cnt)
			op_ra(stack_a);
		else if ((*stack_a)->num < pivot && ++pb_cnt)
			op_pb(stack_a, stack_b);
	}
	i = 0;
	if (first++ != 0)
		while (i++ < ra_cnt)
			op_rra(stack_a);
	ft_a_to_b(stack_a, stack_b, ra_cnt);
	ft_b_to_a(stack_a, stack_b, pb_cnt);
}
