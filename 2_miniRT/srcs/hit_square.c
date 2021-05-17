/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:56:08 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/05/17 19:56:19 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_bool	hit_square(t_fig *lst, t_ray *ray, t_hit_record *rec)
{
	t_sq_data	var;

	var.denominator = vdot(ray->dir, lst->fig.sq.n);
	if (!var.denominator)
		return (FALSE);
	var.nom = vdot(vsubstract(lst->fig.sq.c, ray->origin), lst->fig.sq.n);
	var.t = var.nom / var.denominator;
	if (var.t < rec->t_min || var.t > rec->t_max)
		return (FALSE);
	var.r = vdefine(0, 1, 0);
	if (fabs(lst->fig.sq.n.y) == 1)
		var.r = vdefine(1, 0, 0);
	var.side_v = vcross(lst->fig.sq.n, var.r);
	var.p = vadd(ray->origin, vscalarmul(ray->dir, var.t));
	var.v = vsubstract(var.p, lst->fig.sq.c);
	var.cosine = fabs(vdot(var.side_v, var.v) / (vlen(var.side_v) * vlen(var.v)));
	if (var.cosine < sqrt(2) / 2)
		var.cosine = cos(M_PI_2 - acos(var.cosine));
	var.limit = (lst->fig.sq.side / 2) / var.cosine;
	if (vlen(var.v) > var.limit)
		return (FALSE);
	if (var.t >= 0)
	{
		rec->t = var.t;
		rec->normal = lst->fig.sq.n;
		rec->p = ray_at(ray, var.t);
		rec->albedo = lst->albedo;
		set_face_normal(ray, rec);
		return (TRUE);
	}
	return (FALSE);
}
