/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 11:39:58 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/03/28 11:50:07 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FIGURES_H_
# define _FIGURES_H_

typedef struct	s_sp
{
	t_p3	c;
	double	r;
}				t_sp;

typedef struct	s_pl
{
	t_p3	p;
}				t_pl;

typedef struct	s_sq
{
	t_p3	c;
	double	side;
}				t_sq;

typedef struct	s_cy
{
}				t_cy;
