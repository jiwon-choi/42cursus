#include <mlx.h>

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		*data;
	int		bpp;
	int		size_l;
	int		endian;

	int		color[3];
}				t_mlx;

t_mlx	app;

int		main(void)
{
	const int	img_width = 256;
	const int	img_height = 256;

	app.mlx_ptr = mlx_init();
	app.win_ptr = mlx_new_window(app.mlx_ptr, 400, 400, "rainbow");
	app.img_ptr = mlx_new_image(app.mlx_ptr, img_width, img_height);
	app.data = (int *)mlx_get_data_addr(app.img_ptr, &app.bpp, &app.size_l, &app.endian);

	int		j = 0;
	while (j < img_height)
	{
		int		i = 0;
		while (i < img_width)
		{
			app.data[j * 256 + i] = mlx_get_color_value(app.mlx_ptr, 0x00ffffff);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(app.mlx_ptr, app.win_ptr, app.img_ptr, 0, 0);
	mlx_loop(app.mlx_ptr);
	return (0);
}
