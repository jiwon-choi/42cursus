/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 10:32:33 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/05/04 14:33:16 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

double	hit_sphere(t_p3 center, double radius, t_ray ray)
{
	t_p3	oc;

	oc = vsubstract(ray.origin, center);
	float	a = vdot(ray.dir, ray.dir);
	float	b = 2.0 * vdot(oc, ray.dir);
	float	c = vdot(oc, oc) - radius * radius;
	float	discriminant = b * b - 4 * a * c;

	if (discriminant < 0)
		return (-1.0);
	else
		return ((-b - sqrt(discriminant)) / (2.0 * a)); // sqrt substracted
}


