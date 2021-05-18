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

int		main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2 || argc > 3)
		error_check(1, "");
	if (argc == 2 && ft_strncmp(argv[1] + ft_strlen(argv[1]) - 3, ".rt", 3))
		error_check(2, "");
	if (argc == 3 && ft_strncmp(argv[2], "--save", 6))
		error_check(3, "");
	data_init(&data, argv[1]);
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
