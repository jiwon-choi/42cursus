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

void	ft_select(double *t1, double *t2, int flag)
{
	double	tmp;

	if (flag == 1)
	{
		if (*t1 > *t2)
		{
			tmp = *t1;
			*t1 = *t2;
			*t2 = tmp;
		}
	}
	else
	{
		if (*t1 < *t2)
		{
			tmp = *t1;
			*t1 = *t2;
			*t2 = tmp;
		}
	}
}

double	cy_calc(t_cy_data var, t_hit_record *rec, int flag)
{
	double	t;

	var.a = vdot(var.v, var.v) - pow(vdot(var.v, var.h), 2);
	var.b = (vdot(var.v, var.w)
			- (vdot(var.v, var.h) * vdot(var.w, var.h))) * 2;
	var.c = vdot(var.w, var.w) - pow(vdot(var.w, var.h), 2) - var.r2;
	if (!(intersect_check(var, &var.t1, &var.t2, flag)))
		return (0);
	if ((var.t1 < 0 && var.t2 < 0)
			|| (var.t1 > rec->t_max && var.t2 > rec->t_max))
		return (0);
	if (var.t2 < 0)
		return (0);
	if (var.t1 > 0)
		t = var.t1;
	else
		t = var.t2;
	return (t);
}

double	intersect_check(t_cy_data var, double *t1, double *t2, int flag)
{
	double	root;
	double	t;

	root = (var.b * var.b) - (4 * var.a * var.c);
	if (root < 0)
		return (0);
	if (root > 0)
	{
		t = (var.b > 0) ? -0.5 * (var.b + sqrt(root))
						: -0.5 * (var.b - sqrt(root));
		*t1 = t / var.a;
		*t2 = var.c / t;
		ft_select(t1, t2, flag);
	}
	else if (root == 0)
	{
		if (fabs(vdot(var.v, var.h)) != 1)
		{
			*t1 = -var.b / (2 * var.a);
			*t2 = -var.b / (2 * var.a);
		}
	}
	return (1);
}

int		cy_boundary(t_fig *lst, t_ray *r, t_cy_data var)
{
	double	len;

	var.p = ray_at(r, var.t);
	len = sqrt(pow(lst->fig.cy.r, 2.0) + pow(lst->fig.cy.height, 2.0));
	if (ft_vec_dist(lst->fig.cy.c, var.p) > len)
		return (0);
	return (1);
}
