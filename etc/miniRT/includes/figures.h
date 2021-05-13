/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:52:27 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/05/04 16:32:40 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FIGURES_H
# define _FIGURES_H

# include "ray.h"

# define SP 0
# define PL 1
# define SQ 2
# define CY 3
# define TR 4

typedef struct	s_sphere
{
	t_p3	c;
	double	diameter;
	int		color;
}				t_sp;

typedef struct	s_plane
{
	t_p3	p;
	t_p3	v;
	int		color;
}				t_pl;

typedef struct	s_square
{
	t_p3	c;
	t_p3	v;
	double	side;
	int		color;
}				t_sq;

typedef struct	s_cylinder
{
	t_p3	p;
	t_p3	v;
	double	diameter;
	double	height;
	int		color;
}				t_cy;

typedef struct	s_triangle
{
	t_p3	p1;
	t_p3	p2;
	t_p3	p3;
	int		color;
}				t_tr;

union			u_fig
{
	t_sp	sp;
	t_pl	pl;
	t_sq	sq;
	t_cy	cy;
	t_tr	tr;
};

typedef struct	s_fig
{
	int				flag;
	union u_fig		fig;	
	struct s_fig	*next;
}				t_fig;

#endif
