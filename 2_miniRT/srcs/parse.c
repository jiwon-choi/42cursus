/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:34:09 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/05/18 15:56:40 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	parse_resolution(t_scene *scene, char *str)
{
	if (scene->res_ex)
		error_check(4, "Double declaration Resolution");
	scene->res_ex = TRUE;
	scene->res_x = rt_atoi(&str);
	check_values(scene->res_x, 1, INFINITY, "Resolution x");
	scene->res_y = rt_atoi(&str);
	check_values(scene->res_y, 1, INFINITY, "Resolution y");
	check_null(&str);
}

void	parse_ambient(t_scene *scene, char *str)
{
	if (scene->amb_ex)
		error_check(4, "Double declaration Ambient");
	scene->amb_ex = TRUE;
	scene->amb_ratio = rt_atof(&str);
	check_values(scene->amb_ratio, 0, 1, "Ambient lightning ratio");
	scene->amb_color = rt_albedo(&str);
	check_null(&str);
}

void	parse_camera(t_mlx *mlx, char *str)
{
	t_cam	*new;
	t_cam	*ptr;

	if (!(new = (t_cam *)malloc(sizeof(t_cam))))
		error_check(5, "Camera");
	new->look_from = rt_ato3(&str);
	new->look_at = rt_ato3(&str);
	new->fov = rt_atoi(&str);
	check_values(new->fov, 0, 180, "FOV");
	new->next = NULL;
	ptr = mlx->cam;
	if (!mlx->cam)
		mlx->cam = new;
	else
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
	check_null(&str);
}

void	parse_light(t_scene *scene, char *str)
{
	t_light		*new;
	t_light		*p;

	if (!(new = (t_light *)malloc(sizeof(t_light))))
		error_check(5, "Light");
	new->position = rt_ato3(&str);
	new->br = rt_atof(&str);
	check_values(new->br, 0, 1, "Brightness");
	new->color = rt_albedo(&str);
	new->next = NULL;
	p = scene->light;
	if (!scene->light)
		scene->light = new;
	else
	{
		while (p->next)
			p = p->next;
		p->next = new;
	}
	check_null(&str);
}

void	parse(t_data *data, char *str)
{
	while (ft_isspace(*str))
		str += 1;
	if (*str == '#' || *str == 0)
		return ;
	else if (*str == 's' && *(str + 1) == 'p')
		parse_sphere(&data->lst, str + 2);
	else if (*str == 'p' && *(str + 1) == 'l')
		parse_plane(&data->lst, str + 2);
	else if (*str == 's' && *(str + 1) == 'q')
		parse_square(&data->lst, str + 2);
	else if (*str == 'c' && *(str + 1) == 'y')
		parse_cylinder(&data->lst, str + 2);
	else if (*str == 't' && *(str + 1) == 'r')
		parse_triangle(&data->lst, str + 2);
	else if (*str == 'R')
		parse_resolution(&data->scene, str + 1);
	else if (*str == 'A')
		parse_ambient(&data->scene, str + 1);
	else if (*str == 'c')
		parse_camera(&data->mlx, str + 1);
	else if (*str == 'l')
		parse_light(&data->scene, str + 1);
}
