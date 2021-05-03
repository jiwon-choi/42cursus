/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 15:05:41 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/05/03 20:57:36 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int		main(int argc, char **argv)
{
	char	*str;
	int		fd;
	t_scene		data;
	t_fig		*lst;

	lst = 0;
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (-1);

	while (get_next_line(fd, &str))
		parse(&data, &lst, str);
	free(str);


	t_mlx	app;
	app.mlx_ptr = mlx_init();
	app.win_ptr = mlx_new_window(app.mlx_ptr, data.x_res, data.y_res, "miniRT");
	app.img_ptr = mlx_new_image(app.mlx_ptr, data.x_res, data.y_res);
	app.data = (int *)mlx_get_data_addr(app.img_ptr, &app.bpp, &app.size_l, &app.endian);

	float	viewport_height = 2.0;
	float	viewport_width = (data.x_res / data.y_res) * viewport_height;

	// lower_left_corner fixed
	t_p3		origin = vdefine(0, 0, 0); // camera position
	t_p3		horizontal = vdefine(viewport_width, 0, 0);
	t_p3		vertical = vdefine(0, viewport_height, 0);
	t_p3		lower_left_corner;
	lower_left_corner.x = origin.x - horizontal.x / 2;
	lower_left_corner.y = origin.y - vertical.y / 2;
	lower_left_corner.z = origin.z - horizontal.z / 2 - vertical.z / 2 - 1;

	int		j = 0;
	while (j < data.y_res)
	{
		int		i = 0;
		while (i < data.x_res)
		{
			float	u = (double)i / (data.x_res - 1); // 0.0 -> 1.0
			float	v = (data.y_res - (double)j - 1) / (data.y_res - 1); // 1.0 -> 0.0

			t_ray	ray; // 방향 벡터
			ray.origin = origin;
			ray.dir = lower_left_corner; // -1.777778, -1.00000, -1.00000
			// x axis, y axis 변화
			ray.dir = vadd(ray.dir, vscalarmul(horizontal, u));
			ray.dir = vadd(ray.dir, vscalarmul(vertical, v));
			// 중점 계산
			ray.dir = vsubstract(ray.dir, origin);
			// z축 1.0 고정 = ray.z 1.0 고정
			int color = 0;
			if(ray_color(ray))
				color = lst->fig.sp.color;

			app.data[j * data.x_res + i] = mlx_get_color_value(app.mlx_ptr, color);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(app.mlx_ptr, app.win_ptr, app.img_ptr, 0, 0);
	mlx_loop(app.mlx_ptr);
	return (0);
}
