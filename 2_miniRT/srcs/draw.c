/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:11:14 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/05/17 18:26:33 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	scene_init(t_data *data)
{
	double	theta;
	double	h;

	theta = degrees_to_radians(data->mlx.cam->fov);
	h = tan(theta / 2);
	data->scene.aspect_ratio =
			(double)data->scene.res_x / (double)data->scene.res_y;
	data->scene.viewport_h = 2.0 * h;
	data->scene.viewport_w = data->scene.aspect_ratio * data->scene.viewport_h;
	data->scene.focal_length = 1.0;
	data->scene.origin = data->mlx.cam->look_from;
}

void	camera_create(t_data *data)
{
	t_p3	w;
	t_p3	u;
	t_p3	v;

	w.x = -(data->mlx.cam->look_at.x);
	w.y = -(data->mlx.cam->look_at.y);
	w.z = -(data->mlx.cam->look_at.z);
	if ((w.x == 0 && w.y == 1 && w.z == 0)
			|| (w.x == 0 && w.y == -1 && w.z == 0))
		w = vadd(w, vdefine(EPSILON, EPSILON, EPSILON));
	u = vunit(vcross(vdefine(0, 1, 0), w));
	v = vcross(w, u);
	data->scene.horizontal = vscalarmul(u, data->scene.viewport_w);
	data->scene.vertical = vscalarmul(v, data->scene.viewport_h);
	data->scene.l_l_corner.x = data->scene.origin.x
		- (data->scene.horizontal.x / 2) - (data->scene.vertical.x / 2) - w.x;
	data->scene.l_l_corner.y = data->scene.origin.y
		- (data->scene.horizontal.y / 2) - (data->scene.vertical.y / 2) - w.y;
	data->scene.l_l_corner.z = data->scene.origin.z
		- (data->scene.horizontal.z / 2) - (data->scene.vertical.z / 2) - w.z;
}

t_p3	scale_color(t_p3 color)
{
	color.x = (int)(color.x * 255);
	color.y = (int)(color.y * 255);
	color.z = (int)(color.z * 255);
	return (color);
}

void	make_picture(t_data *data)
{
	t_ray		ray;
	t_p3		color;
	t_matrix	m;

	scene_init(data);
	camera_create(data);
	m.y = 0;
	while (m.y < data->scene.res_y)
	{
		m.x = 0;
		while (m.x < data->scene.res_x)
		{
			m.u = (double)m.x / (data->scene.res_x - 1);
			m.v = (data->scene.res_y - (double)m.y - 1)
					/ (data->scene.res_y - 1);
			ray = ray_primary(&data->scene, m.u, m.v);
			color = ray_color(data, &ray);
			color = scale_color(color);
			data->mlx.data[m.y * data->scene.res_x + m.x] =
					mlx_get_color_value(data->mlx.mlx_ptr,
					color.x * 256 * 256 + color.y * 256 + color.z);
			m.x++;
		}
		m.y++;
	}
}
