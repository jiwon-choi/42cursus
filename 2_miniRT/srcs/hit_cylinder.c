/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:52:13 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/05/17 19:52:14 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"


t_p3	calc_cy_normal(t_fig *lst, t_ray *r, double x[2], t_cy_data var)
{
	double	dist;
	double	res;

	if ((var.dist1 >= 0 && var.dist1 <= lst->fig.cy.height)
			&& (var.dist2 >= 0 && var.dist2 <= lst->fig.cy.height))
	{
		dist = x[0] < x[1] ? var.dist1 : var.dist2;
		res = x[0] < x[1] ? x[0] : x[1];
	}
	else if (var.dist1 <= 0 && var.dist1 <= lst->fig.cy.height)
	{
		dist = var.dist1;
		res = x[0];
	}
	else
	{
		dist = var.dist2;
		res = x[1];
	}
	x[0] = res;
	return (vunit(vsubstract(vsubstract(vscalarmul(r->dir, res),
			vscalarmul(lst->fig.cy.n, dist)),
			vsubstract(lst->fig.cy.c, r->origin))));
}

int		solve_cylinder(t_fig *lst, t_ray *r, double x[2])
{
	t_p3	v;
	t_p3	u;
	double	a;
	double	b;
	double	c;

	v = vscalarmul(lst->fig.cy.n, vdot(r->dir, lst->fig.cy.n));
	v = vsubstract(r->dir, v);
	u = vscalarmul(lst->fig.cy.n, vdot(vsubstract(r->origin,
			lst->fig.cy.c), lst->fig.cy.n));
	u = vsubstract(vsubstract(r->origin, lst->fig.cy.c), u);
	a = vdot(v, v);
	b = 2 * vdot(v, u);
	c = vdot(u, u) - pow(lst->fig.cy.r, 2);
	x[0] = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
	x[1] = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
	if (x[0] < EPSILON && x[1] < EPSILON)
	{
		x[0] = INFINITY;
		x[1] = INFINITY;
		return (0);
	}
	return (1);
}

double	cy_intersection(t_fig *lst, t_ray *r, t_p3 *normal)
{
	double		x[2];
	t_cy_data	var;

	if (solve_cylinder(lst, r, x) == 0)
		return (INFINITY);
	var.dist1 = vdot(lst->fig.cy.n, vsubstract(vscalarmul(r->dir, x[0]),
			vsubstract(lst->fig.cy.c, r->origin)));
	var.dist2 = vdot(lst->fig.cy.n, vsubstract(vscalarmul(r->dir, x[1]),
			vsubstract(lst->fig.cy.c, r->origin)));
	if (!((var.dist1 >= 0 && var.dist1 <= lst->fig.cy.height && x[0] > EPSILON)
		|| (var.dist2 >= 0 && var.dist2 <= lst->fig.cy.height
		&& x[1] > EPSILON)))
		return (INFINITY);
	*normal = calc_cy_normal(lst, r, x, var);
	return (x[0]);
}

double	plane_inter(t_ray *r, t_p3 plane_p, t_p3 plane_nv)
{
	double	x;
	double	denom;

	denom = vdot(plane_nv, r->dir);
	if (!denom)
		return (INFINITY);
	x = (vdot(plane_nv, vsubstract(plane_p, r->origin))) / denom;
	return (x > 0 ? x : INFINITY);
}
