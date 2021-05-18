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
	camera_init(data);
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
