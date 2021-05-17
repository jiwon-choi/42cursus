/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:38:06 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/05/17 18:38:07 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_p3	vmul(t_p3 a, t_p3 b)
{
	t_p3	v;

	v.x = a.x * b.x;
	v.y = a.y * b.y;
	v.z = a.z * b.z;
	return (v);
}

double	vlen(t_p3 a)
{
	double len;

	len = a.x * a.x + a.y * a.y + a.z * a.z;
	len = sqrt(len);
	return (len);
}

t_p3	vunit(t_p3 a)
{
	return (vscalardiv(a, vlen(a)));
}

t_p3	vmin(t_p3 a, t_p3 b)
{
	if (a.x > b.x)
		a.x = b.x;
	if (a.y > b.y)
		a.y = b.y;
	if (a.z > b.z)
		a.z = b.z;
	return (a);
}
