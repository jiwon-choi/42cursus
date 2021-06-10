/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:01:31 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/06/10 15:12:04 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_dlist	*create_node(int input)
{
	t_dlist	*new;

	new = malloc(sizeof(t_dlist));
	if (!new)
		return (0);
	new->num = input;
	new->prev = new;
	new->next = new;
	return (new);
}

void	push_node(t_dlist **lst, t_dlist *node)
{
	if (!lst || !node)
		return ;
	if (*lst)
	{
		(*lst)->prev->next = node;
		node->prev = (*lst)->prev;
		(*lst)->prev = node;
		node->next = *lst;
	}
	*lst = node;
}

t_dlist	*pop_node(t_dlist **lst)
{
	t_dlist	*pop;

	if (!lst)
		return (0);
	pop = *lst;
	if (*lst == (*lst)->next)
		*lst = 0;
	else
	{
		(*lst)->prev->next = (*lst)->next;
		(*lst)->next->prev = (*lst)->prev;
		*lst = (*lst)->next;
		pop->prev = pop;
		pop->next = pop;
	}
	return (pop);
}

void	dlist_clear(t_dlist *lst)
{
	t_dlist	*tmp;

	lst->prev->next = NULL;
	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

int		stack_size(t_dlist *lst)
{
	int		last;
	int		cnt;

	if (!lst)
		return (0);
	cnt = 0;
	last = lst->prev->num;
	while (lst->num != last)
	{
		cnt++;
		lst = lst->next;
	}
	return (++cnt);
}
