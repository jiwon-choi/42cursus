#include "../includes/minirt.h"

static void		create_header(t_scene scene, t_bmp_header *bmp_h, t_dib_header *dib_h)
{
	bmp_h->type[0] = 0x42;
	bmp_h->type[1] = 0x4D;
	bmp_h->size = (scene.res_x * scene.res_y * 4) + 54;
	bmp_h->reserved = 0x00000000;
	bmp_h->offset = 0x36;
	dib_h->size = 40;
	dib_h->width = scene.res_x;
	dib_h->height = -scene.res_y;
	dib_h->colplanes = 1;
	dib_h->bpp = 32;
	dib_h->compression = 0;
	dib_h->img_size = (scene.res_x * scene.res_y * 4);
	dib_h->x_ppm = 2835;
	dib_h->y_ppm = 2835;
	dib_h->color_number = 0;
	dib_h->important_color = 0;
}

static void		write_header(int fd, t_bmp_header bmp_h, t_dib_header dib_h)
{
	write(fd, &bmp_h.type, 2);
	write(fd, &bmp_h.size, 4);
	write(fd, &bmp_h.reserved, 4);
	write(fd, &bmp_h.offset, 4);
	write(fd, &dib_h.size, 4);
	write(fd, &dib_h.width, 4);
	write(fd, &dib_h.height, 4);
	write(fd, &dib_h.colplanes, 2);
	write(fd, &dib_h.bpp, 2);
	write(fd, &dib_h.compression, 4);
	write(fd, &dib_h.img_size, 4);
	write(fd, &dib_h.x_ppm, 4);
	write(fd, &dib_h.y_ppm, 4);
	write(fd, &dib_h.color_number, 4);
	write(fd, &dib_h.important_color, 4);
}

static void		write_file(int fd, t_scene scene, t_mlx mlx)
{
	char	*pixel_array;
	int		image_size;
	int		i;
	int		j;

	if (!(pixel_array = (char *)malloc(mlx.size_l * scene.res_y)))
		error_check(5, "write file");
	image_size = scene.res_x * scene.res_y;
	i = 0;
	j = 0;
	while (i < image_size)
	{
		pixel_array[j++] = mlx.data[i] & 255;
		pixel_array[j++] = (mlx.data[i] & 255 << 8) >> 8;
		pixel_array[j++] = (mlx.data[i] & 255 << 16) >> 16;
		pixel_array[j++] = 0;
		i++;
	}
	write(fd, pixel_array, mlx.size_l * scene.res_y);
	free(pixel_array);
}

static int		create_file(void)
{
	int			fd;
	static int	i;
	char *img_num;
	char *tmp;
	char *bmpname;
	
	img_num = ft_itoa(i);
	tmp = ft_strjoin("img", img_num);
	bmpname = ft_strjoin(tmp, ".bmp");
	if (!((fd = open(bmpname, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU)) > 0))
		error_check(7, "bmp file can not open");
	printf("%s\n", bmpname);
	free(img_num);
	free(tmp);
	free(bmpname);
	i++;
	return (fd);
}

void	make_bmp(t_data *data)
{
	t_bmp_header	bmp_h;
	t_dib_header	dib_h;
	int				fd;

	fd = create_file();
	create_header(data->scene, &bmp_h, &dib_h);
	write_header(fd, bmp_h, dib_h);
	write_file(fd, data->scene, data->mlx);
	close(fd);
}