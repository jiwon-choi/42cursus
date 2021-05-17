/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_triangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:56:25 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/05/17 19:56:35 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_bool	hit_triangle(t_fig *lst, t_ray *r, t_hit_record *rec)
{
	t_tr_data	var;

	var.n = vunit(vcross(vsubstract(lst->fig.tr.p2, lst->fig.tr.p1),
				vsubstract(lst->fig.tr.p3, lst->fig.tr.p1)));
	var.denominator = vdot(r->dir, var.n);
	if (!var.denominator)
		return (FALSE);
	var.nom = vdot(vsubstract(lst->fig.tr.p1, r->origin), var.n);
	var.t = var.nom / var.denominator;
	if (var.t < rec->t_min || var.t > rec->t_max)
		return (FALSE);
	var.p = vadd(r->origin, vscalarmul(r->dir, var.t));
	var.un = vcross(var.n, vsubstract(lst->fig.tr.p2, lst->fig.tr.p1));
	var.vn = vcross(var.n, vsubstract(lst->fig.tr.p3, lst->fig.tr.p1));
	var.denominator = vdot(vsubstract(lst->fig.tr.p2, lst->fig.tr.p1), var.vn);
	if (fabs(var.denominator) < 0.001)
		return (FALSE);
	var.s = vdot(vsubstract(var.p, lst->fig.tr.p1), var.vn) / var.denominator;
	if (var.s < 0 || var.s > 1)
		return (FALSE);
	var.tt = vdot(vsubstract(var.p, lst->fig.tr.p1), var.un) / -var.denominator;
	if (!(var.tt >= 0 && (var.s + var.tt) <= 1))
		return (FALSE);
	rec->t = var.t;
	rec->normal = var.n;
	rec->p = ray_at(r, var.t);
	rec->albedo = lst->albedo;
	set_face_normal(r, rec);
	return (TRUE);
}
