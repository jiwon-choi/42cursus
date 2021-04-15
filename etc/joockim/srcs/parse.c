/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 14:20:12 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/04/15 15:05:29 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
#include "../get_next_line/get_next_line.h"

void	parse(t_mlx *mlx, t_scene *data, t_fig **lst, char **av)
{
	char	*str;
	int		fd;

	*lst = NULL;
	data->l = NULL;
	mlx->cam = NULL;
	data->res_init = 0;
	data->al_init = 0;
	if ((fd = open(av[1], 0)) == -1)
		exit(1);
	while (get_next_line(fd, &str))
		parsing(mlx, data, lst, str);
	if (data->res_init == 0 || data->al_init == 0 || mlx->cam == NULL)
		error_check(4, "Not enough elements in rt file to render a scene");
	free(str);
	str = 0;
}

void	parsing(t_mlx *mlx, t_scene *data, t_fig **lst, char *str)
{
	if (*str == "#" || *str == 0)
		return ;
	else
		save_args(mlx, data, lst, str);
}

void	save_args2(t_fig **lst, char *str)
{
	if (*str == 'p' && *(str + 1) == 'y' && *(str++) && *(str++))
		parse_pyramid(lst, str);
	else if (*str == 't' && *(str + 1) == 'r' && *(str++) && *(str++))
		parse_triangle(lst, str);
}

void	save_args(t_mlx *mlx, t_scene *data, t_fig **lst, char *str)
{
	if (*str == 'R')
		parse_resolution(data, ++str);
	else if (*str == 'A')
		parse_ambient(data, ++str);
	else if (*str == 'c' && (*(str + 1) == 32 || *(str + 1) == 9))
		parse_camera(mlx, data, ++str);
	else if (*str == 'c' && *(str + 1) == 'y' && *(str++) && *(str++))
		parse_cylinder(lst, str);
	else if (*str == 'c' && *(str + 1) == 'u' && *(str++) && *(str++))
		parse_cube(lst, str);
	else if (*str == 'l' && (*(str + 1) == 32 || *(str + 1) == 9))
		parse_light(&data, ++str);
	else if (*str == 's' && *(str + 1) == 'p' && *(str++) && *(str++))
		parse_sphere(lst, str);
	else if (*str == 's' && *(str + 1) == 'q' && *(str++) && *(str++))
		parse_square(lst, str);
	else if (*str == 'p' && *(str + 1) == 'l' && *(str++) && *(str++))
		parse_plane(lst, str);
	save_args2(lst, str);
}

void	parse_resolution(t_scene *data, char *str)
{
	if (data->res_init > 0)
		error_check(4, "Double declaration Resolution");
	data->res_init += 1;
	data->xres = rt_atoi(&str);
	skip_space(&str);
	data->yres = rt_atoi(&str);
}

void	parse_ambient(t_scene *data, char *str)
{
	if (data->al_init > 0)
		error_check(4, "Double declaration Ambient lightning");
	data->al_init += 1;
	skip_space(&str);
	data->ambient_light = rt_atof(&str);
	check_values(data->ambient_light, 0, 1, "ambient lightning");
	data->al_color = parse_color(&str);
}

void	parse_camera(t_mlx *mlx, t_scene *data, char *str)
{
	t_cam	*elem;
	t_cam	*begin;
	int		idx;

	idx = 0;
	begin = mlx->cam;
	elem = err_malloc(sizeof(t_cam));
	elem->next = NULL;
	if (mlx->cam)
	{
		while (mlx->cam->next)
			mlx->cam = mlx->cam->next;
		idx = mlx->cam->idx;
		mlx->cam->next = elem;
	}
	else
		mlx->cam = elem;
	elem->idx = idx + 1;
	data->cam_nb = elem->idx;
	elem->o = parse_p3(&str);
	elem->nv = normalize(parse_p3(&str));
	elem->fov = rt_atoi(&str);
	check_values(elem->fov, 0, 180, "Camera FOV");
	mlx->cam = begin ? begin : elem;
}

void	parse_light(t_scene **data, char *str)
{
	t_light		*elem;
	t_light		*list;
	t_light		*begin;

	begin = (*data)->l;
	list = (*data)->l;
	elem = err_malloc(sizeof(t_light));
	elem->next = NULL;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = elem;
		list = list->next;
	}
	else
		list = elem;
	list->o = parse_p3(&str);
	list->br = rt_atof(&str);
	check_values(list->br, 0, 1, "Light bright");
	list->color = parse_color(&str);
	(*data)->l = begin ? begin : list;
}
