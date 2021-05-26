/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 13:29:58 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/05/26 21:16:04 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

t_bool	duplicates_check(t_dlist *lst)
{
	t_dlist	*new;

	new = lst->prev;
	while (lst != new)
	{
		if (new->num == lst->num)
			return (TRUE);
		lst = lst->next;
	}
	return (FALSE);
}

void	init_stack(t_dlist **lst, t_dlist *node)
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
	if (duplicates_check(*lst))
	{
		dlist_clear(*lst);
		ft_error();
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

	for (int i = 0; i < argc - 1; i++)
	{
		printf("%d ", stack_a->num);
		stack_a = stack_a->next;
	}

	dlist_clear(stack_a);
	return (0);
}
