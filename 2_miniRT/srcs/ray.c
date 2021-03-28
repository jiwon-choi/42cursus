/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 10:32:37 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/03/28 10:32:38 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vec3.h"
#include "../includes/ray.h"

t_p3	ray_at(t_ray r)
{
	t_p3	half_line;

	half_line = vscalarmul(r.dir, r.t);
	half_line = vadd(half_line, r.origin);
	return (half_line);
}

t_p3	ray_color(t_ray r)
{
	t_p3	unit_dir;
	t_p3	color;
	t_p3	N;
	float	t;

	r.t = hit_sphere(vdefine(0.0, 0.0, -1.0), 0.5, r);
	if (r.t > 0.0)
	{
		N = ray_at(r);
		N = vsubstract(N, vdefine(0, 0, -1));
		N = vunit(N);
		N = vdefine(0.5 * (N.x + 1), 0.5 * (N.y + 1), 0.5 * (N.z + 1));
		return (N);
	}
	unit_dir = vunit(r.dir);
	t = 0.5 * (unit_dir.y + 1.0);
	color = vdefine(1.0, 1.0, 1.0);
	color.x *= 1.0 - (t * 0.5);
	color.y *= 1.0 - (t * 0.3);
	return (color);
}
