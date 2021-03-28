/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 10:32:33 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/03/28 10:32:34 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ray.h"
#include "../includes/vec3.h"

double	hit_sphere(t_p3 center, double radius, t_ray r)
{
	t_p3	oc;

	oc = vsubstract(r.origin, center);
	float	a = vdot(r.dir, r.dir);
	float	b = 2.0 * vdot(oc, r.dir);
	float	c = vdot(oc, oc) - radius * radius;
	float	discriminant = b * b - 4 * a * c;

	if (discriminant < 0)
		return (-1.0);
	else
		return ((-b - sqrt(discriminant)) / (2.0 * a)); // sqrt substracted
}


