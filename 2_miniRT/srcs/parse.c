#include "../includes/minirt.h"

void	parse_resolution(t_scene *data, char *str)
{
	data->x_res = rt_atoi(&str);
	data->y_res = rt_atoi(&str);
}

void	parse_ambient(t_scene *data, char *str)
{
	data->ambient_lightning = rt_atof(&str);
	data->ambient_color = parse_color(&str);
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
	new->color = parse_color(&str);
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

void	parse_sphere(t_fig **lst, char *str)
{
	t_fig	*new;
	t_fig	*p;

	if (!(new = (t_fig *)malloc(sizeof(t_fig))))
		return ;
	new->flag = SP;
	new->fig.sp.c = rt_ato3(&str);
	new->fig.sp.diameter = rt_atof(&str);
	new->fig.sp.color = parse_color(&str);
	new->next = NULL;

	p = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		while (p->next)
			p = p->next;
		p->next = new;
	}
}

void	parse_plane(t_fig **lst, char *str)
{
	t_fig	*new;
	t_fig	*p;

	if (!(new = (t_fig *)malloc(sizeof(t_fig))))
		return ;
	new->flag = PL;
	new->fig.pl.p = rt_ato3(&str);
	new->fig.pl.v = rt_ato3(&str);
	new->fig.pl.color = parse_color(&str);
	new->next = NULL;

	p = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		while (p->next)
			p = p->next;
		p->next = new;
	}
}

void	parse_square(t_fig **lst, char *str)
{
	t_fig	*new;
	t_fig	*p;

	if (!(new = (t_fig *)malloc(sizeof(t_fig))))
		return ;
	new->flag = SQ;
	new->fig.sq.c = rt_ato3(&str);
	new->fig.sq.v = rt_ato3(&str);
	new->fig.sq.side = rt_atof(&str);
	new->fig.sq.color = parse_color(&str);
	new->next = NULL;

	p = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		while (p->next)
			p = p->next;
		p->next = new;
	}
}

void	parse_cylinder(t_fig **lst, char *str)
{
	t_fig	*new;
	t_fig	*p;

	if (!(new = (t_fig *)malloc(sizeof(t_fig))))
		return ;
	new->flag = CY;
	new->fig.cy.p = rt_ato3(&str);
	new->fig.cy.v = rt_ato3(&str);
	new->fig.cy.diameter = rt_atof(&str);
	new->fig.cy.height = rt_atof(&str);
	new->fig.cy.color = parse_color(&str);
	new->next = NULL;

	p = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		while (p->next)
			p = p->next;
		p->next = new;
	}
}

void	parse_triangle(t_fig **lst, char *str)
{
	t_fig	*new;
	t_fig	*p;

	if (!(new = (t_fig *)malloc(sizeof(t_fig))))
		return ;
	new->flag = TR;
	new->fig.tr.p1 = rt_ato3(&str);
	new->fig.tr.p2 = rt_ato3(&str);
	new->fig.tr.p3 = rt_ato3(&str);
	new->fig.tr.color = parse_color(&str);
	new->next = NULL;

	p = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		while (p->next)
			p = p->next;
		p->next = new;
	}
}

void	parse(t_scene *data, t_fig **lst, char *str)
{
	if (*str == '#' || *str == 0)
		return ;

	if (*str == 'R')
		parse_resolution(data, str + 1);
	else if (*str == 'A')
		parse_ambient(data, str + 1);
	/*
	else if (*str == 'c')
		parse_camera();
	*/
	else if (*str == 'l')
		parse_light(data, str + 1);
	else if (*str == 's' && *(str + 1) == 'p')
		parse_sphere(lst, str + 2);
	else if (*str == 'p' && *(str + 1) == 'l')
		parse_plane(lst, str + 2);
	else if (*str == 's' && *(str + 1) == 'q')
		parse_square(lst, str + 2);
	else if (*str == 'c' && *(str + 1) == 'y')
		parse_cylinder(lst, str + 2);
	else if (*str == 't' && *(str + 1) == 'r')
		parse_triangle(lst, str + 2);
}
