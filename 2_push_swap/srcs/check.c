/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:30:35 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/05/27 21:21:36 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_bool	check_duplicates(t_dlist *lst)
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

t_bool	check_ascending(t_dlist *lst, int n)
{
	while (--n)
	{
		if (lst->num > lst->next->num)
			return (FALSE);
		lst = lst->next;
	}
	return (TRUE);
}

t_bool	check_descending(t_dlist *lst, int n)
{
	while (--n)
	{
		if (lst->num < lst->next->num)
			return (FALSE);
		lst = lst->next;
	}
	return (TRUE);
}
