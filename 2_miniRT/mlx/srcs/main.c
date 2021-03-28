/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 10:32:15 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/03/28 10:32:17 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "../includes/ray.h"
#include "../includes/vec3.h"

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		*data;
	int		bpp;
	int		size_l;
	int		endian;
}				t_mlx;

t_mlx	app;

int		main(void)
{
	// window size
	float		aspect_ratio = 16.0 / 9.0; // 1.777778
	const int	image_width = 1000;
	const int	image_height = (int)(image_width / aspect_ratio);

	// camera location
	float		viewport_height = 2.0;
	float		viewport_width = aspect_ratio * viewport_height;
	float		focal_length = 1.0;

	// lower_left_corner fixed
	t_p3		origin = vdefine(0, 0, 0); // camera position
	t_p3		horizontal = vdefine(viewport_width, 0, 0);
	t_p3		vertical = vdefine(0, viewport_height, 0);
	t_p3		lower_left_corner;
	lower_left_corner.x = origin.x - horizontal.x / 2;
	lower_left_corner.y = origin.y - vertical.y / 2;
	lower_left_corner.z = origin.z - horizontal.z / 2 - vertical.z / 2 - focal_length;
	t_p3		pixel_color;
	// lower_left_corner's value = -1.777778, -1.00000, -1.00000


	// mlx
	app.mlx_ptr = mlx_init();
	app.win_ptr = mlx_new_window(app.mlx_ptr, image_width, image_height, "Linear interpolation");
	app.img_ptr = mlx_new_image(app.mlx_ptr, image_width, image_height);
	app.data = (int *)mlx_get_data_addr(app.img_ptr, &app.bpp, &app.size_l, &app.endian);

	int		j = 0;
	while (j < image_height)
	{
		int		i = 0;
		while (i < image_width)
		{
			float	u = (double)i / (image_width - 1); // 0.0 -> 1.0
			float	v = (image_height - (double)j - 1) / (image_height - 1); // 1.0 -> 0.0

			t_ray	ray; // 방향 벡터
			ray.origin = origin;
			ray.dir = lower_left_corner; // -1.777778, -1.00000, -1.00000
			// x axis, y axis 변화
			ray.dir = vadd(ray.dir, vscalarmul(horizontal, u));
			ray.dir = vadd(ray.dir, vscalarmul(vertical, v));
			// 중점 계산
			ray.dir = vsubstract(ray.dir, origin);
			// z축 1.0 고정 = ray.z 1.0 고정
			ray.dir = ray_color(ray);
			
			int		ir = 255.999 * ray.dir.x;
			int		ig = 255.999 * ray.dir.y;
			int		ib = 255.999 * ray.dir.z;

//			printf("%d, %d, %d\n", ir, ig, ib);

			pixel_color.x = ir * 256 * 256;
			pixel_color.y = ig * 256;
			pixel_color.z = ib;

			int		color = pixel_color.x + pixel_color.y + pixel_color.z;
			app.data[j * image_width + i] = mlx_get_color_value(app.mlx_ptr, color);

			i++;
		}
		j++;
	}

	// image를 window로 보냄
	mlx_put_image_to_window(app.mlx_ptr, app.win_ptr, app.img_ptr, 0, 0);
	mlx_loop(app.mlx_ptr);
	return (0);
}
