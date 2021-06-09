/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 18:35:11 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/06/09 18:35:26 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_max(t_dlist *stack)
{
	int		max;

	max = stack->num;
	if (max < stack->next->num)
		max = stack->next->num;
	if (max < stack->next->next->num)
		max = stack->next->next->num;
	return (max);
}

int		ft_min(t_dlist *stack)
{
	int		min;

	min = stack->num;
	if (min > stack->next->num)
		min = stack->next->num;
	if (min > stack->next->next->num)
		min = stack->next->next->num;
	return (min);
}
