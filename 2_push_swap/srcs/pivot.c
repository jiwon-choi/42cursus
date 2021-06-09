/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:34:37 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/06/09 18:44:11 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_setup_pivot(t_dlist *stack, int length)
{
	int		arr[length];
	int		i;
	int		j;
	int		cnt;

	i = 0;
	while (i < length)
	{
		arr[i++] = stack->num;
		stack = stack->next;
	}
	i = 0;
	while (i < length)
	{
		j = 0;
		cnt = 0;
		while (j < length)
			if (arr[i] > arr[j++])
				cnt++;
		if (cnt == length / 2)
			return (arr[i]);
		i++;
	}
	return (arr[0]);
}
