#include "minirt.h"

void	parse_resolution(t_scene *data, char *str)
{
	data->x_res = rt_atoi(&str);
	data->y_res = rt_atoi(&str);
}

void	parse_ambient(t_scene *data, char *str)
{
	data->ambient_lightning = rt_atof(&str);
}

//void	parse_camera();

void	parse_light(t_scene *data, char *str)
{
	t_light		*new;
	t_light		*p;

	if (!(new = (t_light *)malloc(sizeof(t_light))))
		return ;
	new->p = rt_ato3(&str);
	new->brightness = rt_atof(&str);
	new->color = rt_ato3(&str);
	new->next = NULL;

	p = data->light;
	if (!data->light)
		data->light = new;
	else
	{
		while (p->next)
			p = p->next;
		p->next = new;
	}
}

void	parse(t_scene *data, char *str)
{
	if (*str == '#' || *str == 0)
		return ;

	if (*str == 'R')
		parse_resolution(data, ++str);
	else if (*str == 'A')
		parse_ambient(data, ++str);
	/*
	else if (*str == 'c')
		parse_camera();
	*/
	else if (*str == 'l')
		parse_light(data, ++str);
}
