/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 20:29:31 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/05/18 14:40:10 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

double	caps_intersection(t_fig *lst, t_ray *r)
{
	double	id1;
	double	id2;
	t_p3	ip1;
	t_p3	ip2;
	t_p3	c2;

	c2 = vadd(lst->fig.cy.c, vscalarmul(lst->fig.cy.n, lst->fig.cy.height));
	id1 = plane_inter(r, lst->fig.cy.c, lst->fig.cy.n);
	id2 = plane_inter(r, c2, lst->fig.cy.n);
	if (id1 < INFINITY || id2 < INFINITY)
	{
		ip1 = vadd(r->origin, vscalarmul(r->dir, id1));
		ip2 = vadd(r->origin, vscalarmul(r->dir, id2));
		if ((id1 < INFINITY && vdist(ip1, lst->fig.cy.c) <= lst->fig.cy.r)
				&& (id2 < INFINITY && vdist(ip2, c2) <= lst->fig.cy.r))
			return (id1 < id2 ? id1 : id2);
		else if (id1 < INFINITY && vdist(ip1, lst->fig.cy.c) <= lst->fig.cy.r)
			return (id1);
		else if (id2 < INFINITY && vdist(ip2, c2) <= lst->fig.cy.r)
			return (id2);
	}
	return (INFINITY);
}

t_bool	hit_cylinder(t_fig *lst, t_ray *r, t_hit_record *rec)
{
	double	cy_inter;
	double	caps_inter;
	t_p3	cy_normal;

	cy_inter = cy_intersection(lst, r, &cy_normal);
	caps_inter = caps_intersection(lst, r);
	if (cy_inter < INFINITY || caps_inter < INFINITY)
	{
		if (cy_inter < caps_inter)
		{
			rec->t = cy_inter;
			rec->p = ray_at(r, cy_inter);
			rec->normal = lst->fig.cy.n;
		}
		else
		{
			rec->t = caps_inter;
			rec->p = ray_at(r, caps_inter);
			rec->normal = lst->fig.cy.n;
		}
		rec->albedo = lst->albedo;
		return (TRUE);
	}
	return (FALSE);
}
