#include "mlx.h"
#include "vec3.h"

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

int		main()
{
	const int	image_width = 256;
	const int	image_height = 256;
	t_p3		pixel_color;

	// mlx 초기화
	app.mlx_ptr = mlx_init();

	// window 초기설정
	app.win_ptr = mlx_new_window(app.mlx_ptr, 400, 400, "PPM image");
	
	// 새로운 image
	app.img_ptr = mlx_new_image(app.mlx_ptr, image_width, image_height);

	// 새로운 image의 pixel당 배열 한 칸 설정
	app.data = (int *)mlx_get_data_addr(app.img_ptr, &app.bpp, &app.size_l, &app.endian);

	int		j = 0;
	while (j < image_height)
	{
		int		i = 0;
		while (i < image_width)
		{
			app.data[j * 256 + i] = mlx_get_color_value(app.mlx_ptr, 0x00ffffff);
			i++;
		}
		j++;
	}

	// image를 window로 보냄
	mlx_put_image_to_window(app.mlx_ptr, app.win_ptr, app.img_ptr, 0, 0);
	mlx_loop(app.mlx_ptr);
	return (0);
}
