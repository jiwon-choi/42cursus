/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_figures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 15:05:57 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/04/30 15:06:36 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	parse_sphere(t_fig **lst, char *str)
{
	t_fig	*new;
	t_fig	*p;

	if (!(new = (t_fig *)malloc(sizeof(t_fig))))
		return ;
	new->flag = SP;
	new->fig.sp.c = rt_ato3(&str);
	new->fig.sp.diameter = rt_atof(&str);
	new->fig.sp.color = parse_color(&str);
	new->next = NULL;
	p = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		while (p->next)
			p = p->next;
		p->next = new;
	}
}

void	parse_plane(t_fig **lst, char *str)
{
	t_fig	*new;
	t_fig	*p;

	if (!(new = (t_fig *)malloc(sizeof(t_fig))))
		return ;
	new->flag = PL;
	new->fig.pl.p = rt_ato3(&str);
	new->fig.pl.v = rt_ato3(&str);
	new->fig.pl.color = parse_color(&str);
	new->next = NULL;
	p = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		while (p->next)
			p = p->next;
		p->next = new;
	}
}

void	parse_square(t_fig **lst, char *str)
{
	t_fig	*new;
	t_fig	*p;

	if (!(new = (t_fig *)malloc(sizeof(t_fig))))
		return ;
	new->flag = SQ;
	new->fig.sq.c = rt_ato3(&str);
	new->fig.sq.v = rt_ato3(&str);
	new->fig.sq.side = rt_atof(&str);
	new->fig.sq.color = parse_color(&str);
	new->next = NULL;
	p = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		while (p->next)
			p = p->next;
		p->next = new;
	}
}

void	parse_cylinder(t_fig **lst, char *str)
{
	t_fig	*new;
	t_fig	*p;

	if (!(new = (t_fig *)malloc(sizeof(t_fig))))
		return ;
	new->flag = CY;
	new->fig.cy.p = rt_ato3(&str);
	new->fig.cy.v = rt_ato3(&str);
	new->fig.cy.diameter = rt_atof(&str);
	new->fig.cy.height = rt_atof(&str);
	new->fig.cy.color = parse_color(&str);
	new->next = NULL;
	p = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		while (p->next)
			p = p->next;
		p->next = new;
	}
}

void	parse_triangle(t_fig **lst, char *str)
{
	t_fig	*new;
	t_fig	*p;

	if (!(new = (t_fig *)malloc(sizeof(t_fig))))
		return ;
	new->flag = TR;
	new->fig.tr.p1 = rt_ato3(&str);
	new->fig.tr.p2 = rt_ato3(&str);
	new->fig.tr.p3 = rt_ato3(&str);
	new->fig.tr.color = parse_color(&str);
	new->next = NULL;
	p = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		while (p->next)
			p = p->next;
		p->next = new;
	}
}
