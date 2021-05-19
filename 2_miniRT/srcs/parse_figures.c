/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_figures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:34:25 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/05/17 18:34:28 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	parse_sphere(t_fig **lst, char *str)
{
	t_fig	*new;
	t_fig	*p;

	if (!(new = (t_fig *)malloc(sizeof(t_fig))))
		error_check(5, "Figure");
	new->flag = SP;
	new->fig.sp.c = rt_ato3(&str);
	new->fig.sp.r = rt_atof(&str) / 2;
	check_values(new->fig.sp.r, 0, INFINITY, "Sphere r");
	new->albedo = rt_albedo(&str);
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
	check_null(&str);
}

void	parse_plane(t_fig **lst, char *str)
{
	t_fig	*new;
	t_fig	*p;

	if (!(new = (t_fig *)malloc(sizeof(t_fig))))
		error_check(5, "Figure");
	new->flag = PL;
	new->fig.pl.p = rt_ato3(&str);
	new->fig.pl.n = vunit(rt_ato3(&str));
	new->albedo = rt_albedo(&str);
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
	check_null(&str);
}

void	parse_square(t_fig **lst, char *str)
{
	t_fig	*new;
	t_fig	*p;

	if (!(new = (t_fig *)malloc(sizeof(t_fig))))
		error_check(5, "Figure");
	new->flag = SQ;
	new->fig.sq.c = rt_ato3(&str);
	new->fig.sq.n = vunit(rt_ato3(&str));
	new->fig.sq.side = rt_atof(&str);
	check_values(new->fig.sq.side, 0, INFINITY, "Square side");
	new->albedo = rt_albedo(&str);
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
	check_null(&str);
}

void	parse_cylinder(t_fig **lst, char *str)
{
	t_fig	*new;
	t_fig	*p;

	if (!(new = (t_fig *)malloc(sizeof(t_fig))))
		error_check(5, "Figure");
	new->flag = CY;
	new->fig.cy.c = rt_ato3(&str);
	new->fig.cy.n = vunit(rt_ato3(&str));
	new->fig.cy.r = rt_atof(&str) / 2;
	check_values(new->fig.cy.r, 0, INFINITY, "Cylinder r");
	new->fig.cy.height = rt_atof(&str);
	check_values(new->fig.cy.height, 0, INFINITY, "Cylinder h");
	new->albedo = rt_albedo(&str);
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
	check_null(&str);
}

void	parse_triangle(t_fig **lst, char *str)
{
	t_fig	*new;
	t_fig	*p;

	if (!(new = (t_fig *)malloc(sizeof(t_fig))))
		error_check(5, "Figure");
	new->flag = TR;
	new->fig.tr.p1 = rt_ato3(&str);
	new->fig.tr.p2 = rt_ato3(&str);
	new->fig.tr.p3 = rt_ato3(&str);
	new->albedo = rt_albedo(&str);
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
	check_null(&str);
}
