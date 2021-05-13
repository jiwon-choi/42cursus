/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:49:19 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/05/04 14:52:13 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _RAY_H
# define _RAY_H

typedef struct	s_p3
{
	double	x;
	double	y;
	double	z;
}				t_p3;

typedef struct	s_ray {
	t_p3	origin;
	t_p3	dir;
	float	t;
}				t_ray;

#endif
