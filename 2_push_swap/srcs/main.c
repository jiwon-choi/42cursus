/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 13:29:58 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/05/28 17:43:07 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int		result = 0;

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	print_stack(t_dlist *stack)
{
	t_dlist	*head;

	if (!stack)
		return ;
	head = stack;
	printf("%d ", stack->num);
	stack = stack->next;
	while (stack != head)
	{
		printf("%d ", stack->num);
		stack = stack->next;
	}
}

int		main(int argc, char **argv)
{
	t_dlist	*stack_a;
	t_dlist	*stack_b;

	if (argc < 2)
		ft_error();
	stack_a = NULL;
	stack_b = NULL;
	while (*(++argv))
		init_stack(&stack_a, create_node(ft_atoi(*argv)));
	if (!check_ascending(stack_a, argc - 1))
		ft_a_to_b(&stack_a, &stack_b, argc - 1);
	dlist_clear(stack_a);
	printf("\nresult %d\n", result);
	return (0);
}
