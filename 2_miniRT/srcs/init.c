/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 00:04:16 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/05/19 00:04:37 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	ft_mlx_init(t_data *data)
{
	data->mlx.mlx_ptr = mlx_init();
	data->mlx.win_ptr = mlx_new_window(data->mlx.mlx_ptr,
			data->scene.res_x, data->scene.res_y, "miniRT");
	data->mlx.img_ptr = mlx_new_image(data->mlx.mlx_ptr,
			data->scene.res_x, data->scene.res_y);
	data->mlx.data = (int *)mlx_get_data_addr(data->mlx.img_ptr,
			&data->mlx.bpp, &data->mlx.size_l, &data->mlx.endian);
}

void	data_init(t_data *data, char *rt_file)
{
	char	*str;
	int		fd;

	data->lst = NULL;
	data->scene.light = NULL;
	data->mlx.cam = NULL;
	data->scene.res_ex = FALSE;
	data->scene.amb_ex = FALSE;
	if ((fd = open(rt_file, O_RDONLY)) == -1)
		exit(1);
	while (get_next_line(fd, &str))
	{
		parse(data, str);
		free(str);
	}
	parse(data, str);
	free(str);
	if (!data->scene.res_ex || !data->scene.amb_ex || !data->mlx.cam)
		error_check(4, "Empty R or A or Camera");
	data->mlx.first_cam = data->mlx.cam;
	data->scene.amb_color = vscalarmul(data->scene.amb_color,
												data->scene.amb_ratio);
	ft_mlx_init(data);
}

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

void	view_init(t_data *data)
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
