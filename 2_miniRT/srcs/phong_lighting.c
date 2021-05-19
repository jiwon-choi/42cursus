/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_lighting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:35:25 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/05/17 18:35:39 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_bool	in_shadow(t_fig *lst, t_ray light_ray, double light_len)
{
	t_hit_record rec;

	rec.t_min = 0;
	rec.t_max = light_len;
	if (hit(lst, &light_ray, &rec))
		return (TRUE);
	return (FALSE);
}

t_p3	point_light_get(t_data *data, t_light *light, t_ray *r,
														t_hit_record *rec)
{
	t_p3	light_dir;
	double	light_len;
	t_ray	light_ray;

	light_dir = vsubstract(light->position, rec->p);
	light_len = vlen(light_dir);
	light_ray = ray(vadd(rec->p, vscalarmul(rec->normal, EPSILON)), light_dir);
	if (in_shadow(data->lst, light_ray, light_len))
		return (vdefine(0, 0, 0));
	light_dir = vunit(light_dir);
	return (vscalarmul(vadd(diffuse(light, rec),
					specular(light, r, rec)), light->br * LUMEN));
}

t_p3	phong_lighting(t_data *data, t_ray *r, t_hit_record *rec)
{
	t_p3	light_color;
	t_light	*lights;

	light_color = vdefine(0, 0, 0);
	lights = data->scene.light;
	while (lights)
	{
		light_color = vadd(light_color, point_light_get(data, lights, r, rec));
		lights = lights->next;
	}
	light_color = vadd(light_color, data->scene.amb_color);
	return (vmin(vmul(light_color, rec->albedo), vdefine(1, 1, 1)));
}
