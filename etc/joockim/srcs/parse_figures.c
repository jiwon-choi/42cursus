/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_figures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:06:30 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/04/15 16:11:06 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/figures.h"

void	parse_cylinder(t_fig **elem, char *str)
{
	t_fig	*lst;

	ft_addnewlst_back(elem);
	lst = *elem;
	while (lst->next)
		lst = lst->next;
	lst->flag = CY;
	lst->fig.cy.c = parse_p3(&str);
	lst->fig.cy.nv = normalize(parse_p3(&str));
	lst->fig.cy.r = rt_atof(&str) / 2;
	check_values(lst->fig.cy.r, 0, INFINITY, "Cylinder radius");
	lst->fig.cy.h = rt_atof(&str);
	check_values(lst->fig.cy.h, 0, INFINITY, "Cylinder height");
	lst->specular = rt_atof(&str);
	check_values(lst->specular, 0, INFINITY, "Cylinder specular");
	list->refl_idx = rt_atof(&str);
	check_values(lst->refl_idx, 0, 1, "Cylinder reflection");
	list->refr_idx = rt_atof(&str);
	check_values(lst->refr_idx, 0, INFINITY, "Cylinder refraction");
	lst->texture = rt_atoi(&str);
	check_values(lst=>texture, 0, 5, "Cylinder texture");
	if (lst->texture == 2)
		lst->wavelength = rt_atof(&str);
	lst->color = parse_color(&str);
}

void	parse_sphere(t_fig **elem, char *str)
{
	t_fig	*lst;

	ft_addnewlst_back(elem);
	lst = *elem;
	while (lst->next)
		lst = lst->next;
	lst->flag = SP;
	lst->fig.sp.c = parse_p3(&str);
	lst->fig.sp.r = rt_atof(&str) / 2;
	check_values(lst->fig.sp.r, 0, INFINITY, "Sphere radius");
	lst->specular = rt_atof(&str);
	check_values(lst->specular, 0, INFINITY, "Sphere specular");
	lst->refl_idx = rt_atof(&str);
	check_values(lst->refl_idx, 0, INFINITY, "Sphere reflection");
	lst->refr_idx = rt_atof(&str);
	check_values(lst->refr_idx, 0, INFINITY, "Sphere refraction");
	lst->texture = rt_atoi(&str);
	check_values(lst->texture, 0, 5, "Sphere texture");
	if (lst->texture == 2)
		lst->wavelength = rt_atof(&str);
	lst->color = parse_color(&str);
}

void	parse_square(t_fig **elem, char *str)
{
	t_fig	*lst;

	ft_addnewlst_back(elem);
	lst = *elem;
	while (lst->next)
		lst = lst->next;
	lst->flag = SQ;
	lst->fig.sq.c = parse_p3(&str);
	lst->normal = normalize(parse_p3(&str));
	lst->fig.sq.side = rt_atof(&str);
	check_values(lst->fig.sq.side, 0, INFINITY, "Square side");
	lst->specular = rt_atof(&str);
	check_values(lst->specular, 0, INFINITY, "Square specular");
	lst->refl_idx = rt_atof(&str);
	check_values(lst->refl_idx, 0, INFINITY, "Square reflection");
	lst->refr_idx = rt_atof(&str);
	check_values(lst->refr_idx, 0, INFINITY, "Square refraction");
	lst->texture = rt_atoi(&str);
	check_values(lst->texture, 0, 5, "Square texture");
	if (lst->texture == 2)
		lst->wavelength = rt_atof(&str);
	lst->color = parse_color(&str);
}

void	parse_plane(t_fig **elem, char *str)
{
	t_fig	*lst;

	ft_addnewlst_back(elem);
	lst = *elem;
	while (lst->next)
		lst = lst->next;
	lst->flag = PL;
	lst->fig.pl.p = parse_p3(&str);
	lst->normal = normalize(parse_p3(&str));
	lst->specular = rt_atof(&str);
	check_values(lst->specular, 0, INFINITY, "Square specular");
	lst->refl_idx = rt_atof(&str);
	check_values(lst->refl_idx, 0, INFINITY, "Square reflection");
	lst->refr_idx = rt_atof(&str);
	check_values(lst->refr_idx, 0, INFINITY, "Square refraction");
	lst->texture = rt_atoi(&str);
	check_values(lst->texture, 0, 5, "Square texture");
	if (lst->texture == 2)
		lst->wavelength = rt_atof(&str);
	lst->color = parse_color(&str);
}

void	parse_triangle(t_fig **elem, char *str)
{
	t_fig	*lst;

	ft_addnewlst_back(elem);
	lst = *elem;
	while (lst->next)
		lst = lst->next;
	lst->flag = TR;
	lst->fig.tr.p1 = parse_p3(&str);
	lst->fig.tr.p2 = parse_p3(&str);
	lst->fig.tr.p3 = parse_p3(&str);
	lst->normal = vcross(vsubstract(lst->fig.tr.p3, lst->fig.tr.p1), vsubstract(lst->fig.tr.p2, lst->fig.tr.p1));
	lst->specular = rt_atof(&str);
	check_values(lst->specular, 0, INFINITY, "Triangle specular");
	lst->refl_idx = rt_atof(&str);
	check_values(lst->refl_idx, 0, INFINITY, "Triangle reflection");
	lst->refr_idx = rt_atof(&str);
	check_values(lst->refr_idx, 0, INFINITY, "Triangle refraction");
	lst->texture = rt_atoi(&str);
	check_values(lst->texture, 0, 5, "Triangle texture");
	if (lst->texture == 2)
		lst->wavelength = rt_atof(&str);
	lst->color = parse_color(&str);
}

void	parse_cube(t_fig **elem, char *str)
{
	t_fig	*lst;

	ft_addnewlst_back(elem);
	lst = *elem;
	while (lst->next)
		lst = lst->next;
	lst->flag = CU;
	lst->fig.sq.c = parse_p3(&str);
	lst->fig.sq.side = rt_atof(&str);
	check_values(lst->fig.sq.side, 0, INFINITY, "Square side");
	lst->specular = rt_atof(&str);
	check_values(lst->specular, 0, INFINITY, "Square specular");
	lst->refl_idx = rt_atof(&str);
	check_values(lst->refl_idx, 0, INFINITY, "Square reflection");
	lst->refr_idx = rt_atof(&str);
	check_values(lst->refr_idx, 0, INFINITY, "Square refraction");
	lst->texture = rt_atoi(&str);
	check_values(lst->texture, 0, 5, "Square texture");
	if (lst->texture == 2)
		lst->wavelength = rt_atof(&str);
	lst->color = parse_color(&str);
}

void	parse_pyramid(t_fig **elem, char *str)
{
	t_fig	*lst;

	ft_addnewlst_back(elem);
	lst = *elem;
	while (lst->next)
		lst = lst->next;
	lst->flag = PY;
	lst->fig.sq.c = parse_p3(&str);
	lst->fig.sq.side = rt_atof(&str);
	check_values(lst->fig.sq.side, 0, INFINITY, "Pyramid side");
	lst->specular = rt_atof(&str);
	check_values(lst->specular, 0, INFINITY, "Pyramid specular");
	lst->refl_idx = rt_atof(&str);
	check_values(lst->refl_idx, 0, INFINITY, "Pyramid reflection");
	lst->refr_idx = rt_atof(&str);
	check_values(lst->refr_idx, 0, INFINITY, "Pyramid refraction");
	lst->texture = rt_atoi(&str);
	check_values(lst->texture, 0, 5, "Pyramid texture");
	if (lst->texture == 2)
		lst->wavelength = rt_atof(&str);
	lst->color = parse_color(&str);
}
