/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 13:29:58 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/06/10 15:15:58 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void		only_3(t_dlist **stack_a)
{
	if (check_ascending(*stack_a, 3))
		return ;
	if ((*stack_a)->num == ft_min(*stack_a))
	{
		op_ra(stack_a);
		op_sa(*stack_a);
		op_rra(stack_a);
	}
	else if ((*stack_a)->num == ft_max(*stack_a))
	{
		op_ra(stack_a);
		if ((*stack_a)->next->num == ft_min(*stack_a))
		{
			op_sa(*stack_a);
		}
	}
	else
	{
		if ((*stack_a)->next->num == ft_min(*stack_a))
			op_sa(*stack_a);
		else
			op_rra(stack_a);
	}
}

static void	descend_to_ascend(t_dlist **stack_a, t_dlist **stack_b, int length)
{
	int		i;

	if (length == 2)
	{
		op_sa(*stack_a);
		return ;
	}
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

static void	init_stack(t_dlist **lst, t_dlist *node)
{
	if (!lst || !node)
		return ;
	if (!*lst)
		*lst = node;
	else
	{
		(*lst)->prev->next = node;
		node->prev = (*lst)->prev;
		(*lst)->prev = node;
		node->next = *lst;
	}
	if (check_duplicates(*lst))
	{
		dlist_clear(*lst);
		ft_error();
	}
}

int			main(int argc, char **argv)
{
	t_dlist	*stack_a;
	t_dlist	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	while (*(++argv))
		init_stack(&stack_a, create_node(ft_atoi(*argv)));
	if (argc - 1 == 3)
		only_3(&stack_a);
	if (check_descending(stack_a, argc - 1))
		descend_to_ascend(&stack_a, &stack_b, argc - 1);
	if (!check_ascending(stack_a, argc - 1))
		ft_a_to_b(&stack_a, &stack_b, argc - 1);
	dlist_clear(stack_a);
	return (0);
}
