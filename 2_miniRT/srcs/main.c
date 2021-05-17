/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:28:48 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/05/17 18:33:49 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int		key_press(int key, t_data *data)
{
	if (key == 53)
		exit(0);
	else if (key == 124)
	{
		if (!data->mlx.cam->next)
			data->mlx.cam = data->mlx.first_cam;
		else
			data->mlx.cam = data->mlx.cam->next;
		make_picture(data);
		mlx_put_image_to_window(data->mlx.mlx_ptr,
				data->mlx.win_ptr, data->mlx.img_ptr, 0, 0);
	}
	return (0);
}

void	parse(t_data *data, char *rt_file)
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
		parse_(data, str);
		free(str);
	}
	parse_(data, str);
	free(str);
	if (!data->scene.res_ex || !data->scene.amb_ex || !data->mlx.cam)
		error_check(4, "Empty R or A or Camera");
	data->mlx.first_cam = data->mlx.cam;
	data->scene.amb_color = vscalarmul(data->scene.amb_color,
												data->scene.amb_ratio);
}

void	mlx_init(t_data *data)
{
	data->mlx.mlx_ptr = mlx_init();
	data->mlx.win_ptr = mlx_new_window(data->mlx.mlx_ptr,
			data->scene.res_x, data->scene.res_y, "miniRT");
	data->mlx.img_ptr = mlx_new_image(data->mlx.mlx_ptr,
			data->scene.res_x, data->scene.res_y);
	data->mlx.data = (int *)mlx_get_data_addr(data->mlx.img_ptr,
			&data->mlx.bpp, &data->mlx.size_l, &data->mlx.endian);
}

int		main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2 || argc > 3)
		error_check(1, "");
	if (argc == 2 && ft_strncmp(argv[1] + ft_strlen(argv[1]) - 3, ".rt", 3))
		error_check(2, "");
	if (argc == 3 && ft_strncmp(argv[2], "--save", 6))
		error_check(3, "");
	parse(&data, argv[1]);
	if (argc == 3)
	{
		while (data.mlx.cam)
		{
			make_picture(&data);
			make_bmp(&data);
			data.mlx.cam = data.mlx.cam->next;
		}
		exit(0);
	}
	make_picture(&data);
	mlx_put_image_to_window(data.mlx.mlx_ptr, data.mlx.win_ptr,
			data.mlx.img_ptr, 0, 0);
	mlx_hook(data.mlx.win_ptr, 02, 1L << 0, key_press, &data);
	mlx_loop(data.mlx.mlx_ptr);
	return (0);
}
