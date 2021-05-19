/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_lighting2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:49:00 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/05/19 14:49:02 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_p3	diffuse(t_light *light, t_hit_record *rec)
{
	t_p3	diffuse;
	t_p3	light_dir;
	double	d_weight;

	light_dir = vunit(vsubstract(light->position, rec->p));
	d_weight = fmax(vdot(rec->normal, light_dir), 0.0);
	diffuse = vscalarmul(rec->albedo, d_weight);
	return (diffuse);
}

t_p3	reflect(t_p3 v, t_p3 n)
{
	return (vsubstract(v, vscalarmul(n, vdot(v, n) * 2)));
}

t_p3	specular(t_light *light, t_ray *r, t_hit_record *rec)
{
	t_specular s;

	s.light_dir = vunit(vsubstract(light->position, rec->p));
	s.view_dir = vunit(vscalarmul(r->dir, -1));
	s.reflect_dir = reflect(vscalarmul(s.light_dir, -1), rec->normal);
	s.shine = 128;
	s.s_weight = 0.5;
	s.spec = pow(fmax(vdot(s.view_dir, s.reflect_dir), 0.0), s.shine);
	s.specular = vscalarmul(vscalarmul(rec->albedo, s.s_weight), s.spec);
	return (s.specular);
}
