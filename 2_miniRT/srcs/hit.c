/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:28:12 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/05/17 18:28:19 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_bool	hit_figures(t_fig *lst, t_ray *r, t_hit_record *rec)
{
	t_bool	hit;

	hit = FALSE;
	if (lst->flag == SP)
		hit = hit_sphere(lst, r, rec);
	else if (lst->flag == PL)
		hit = hit_plane(lst, r, rec);
	else if (lst->flag == SQ)
		hit = hit_square(lst, r, rec);
	else if (lst->flag == TR)
		hit = hit_triangle(lst, r, rec);
	else if (lst->flag == CY)
		hit = hit_cylinder(lst, r, rec);
	return (hit);
}

t_bool	hit(t_fig *lst, t_ray *r, t_hit_record *rec)
{
	t_bool			hit;
	t_hit_record	tmp;

	tmp = *rec;
	hit = FALSE;
	while (lst)
	{
		if (hit_figures(lst, r, &tmp))
		{
			hit = TRUE;
			tmp.t_max = tmp.t;
			*rec = tmp;
		}
		lst = lst->next;
	}
	return (hit);
}
