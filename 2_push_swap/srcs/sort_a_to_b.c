/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 19:49:20 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/05/28 20:02:42 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_a_to_b(t_dlist **stack_a, t_dlist **stack_b, int length)
{
	int		pivot;
	int		ra_cnt;
	int		pb_cnt;
	int		i;

	if (length < 2)
		return ;
	if (length == 2 && check_descending(*stack_a, length))
		op_sa(*stack_a);
	if (check_ascending(*stack_a, length))
		return ;
	pivot = ft_setup_pivot(*stack_a, length);
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
	ft_a_to_b(stack_a, stack_b, ra_cnt);
	ft_b_to_a(stack_a, stack_b, pb_cnt);
}

