#include "../includes/minirt.h"

void	camera_create(t_data *data)
{
	double aspect_ratio;
	double theta = degrees_to_radians(data->mlx.cam->fov);
	double h = tan(theta / 2);

	aspect_ratio = (double)data->scene.res_x / (double)data->scene.res_y;
	data->scene.viewport_h = 2.0 * h;
	data->scene.viewport_w = aspect_ratio * data->scene.viewport_h;
	data->scene.focal_length = 1.0;
	data->scene.origin = data->mlx.cam->look_from;

	t_p3 w;
	w.x = -(data->mlx.cam->look_at.x);
	w.y = -(data->mlx.cam->look_at.y);
	w.z = -(data->mlx.cam->look_at.z);
	// t_p3	w = vunit(vsubstract(data->scene.origin, data->mlx.cam->look_at));
	if ((w.x == 0 && w.y == 1 && w.z == 0)
			|| (w.x == 0 && w.y == -1 && w.z == 0))
		w = vadd(w, vdefine(EPSILON, EPSILON, EPSILON));
	t_p3	u = vunit(vcross(vdefine(0, 1, 0), w));
	t_p3	v = vcross(w, u);

	data->scene.horizontal = vscalarmul(u, data->scene.viewport_w);
	data->scene.vertical = vscalarmul(v, data->scene.viewport_h);
	data->scene.l_l_corner.x = data->scene.origin.x
		- (data->scene.horizontal.x / 2) - (data->scene.vertical.x / 2) - w.x;
	data->scene.l_l_corner.y = data->scene.origin.y
		- (data->scene.horizontal.y / 2) - (data->scene.vertical.y / 2) - w.y;
	data->scene.l_l_corner.z = data->scene.origin.z
		- (data->scene.horizontal.z / 2) - (data->scene.vertical.z / 2) - w.z;
}

void	make_picture(t_data *data)
{
	t_ray		ray;
	t_p3		color;
	t_matrix	m;

	camera_create(data);
	m.y = 0;
	while (m.y < data->scene.res_y)
	{
		m.x = 0;
		while (m.x < data->scene.res_x)
		{
			m.u = (double)m.x / (data->scene.res_x - 1);
			m.v = (data->scene.res_y - (double)m.y - 1) / (data->scene.res_y - 1);
			ray = ray_primary(&data->scene, m.u, m.v);
			color = ray_color(data, &ray);
			color.x = (int)(color.x * 255);
			color.y = (int)(color.y * 255);
			color.z = (int)(color.z * 255);
			data->mlx.data[m.y * data->scene.res_x + m.x] = 
				mlx_get_color_value(data->mlx.mlx_ptr, color.x * 256 * 256 + color.y * 256 + color.z);
			m.x++;
		}
		m.y++;
	}
}