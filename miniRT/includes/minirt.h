#ifndef _MINIRT_H
# define _MINIRT_H

# define SP 0
# define PL 1
# define SQ 2
# define CY 3
# define TR 4

typedef int		t_bool;

typedef struct	s_p3
{
	double	x;
	double	y;
	double	z;
}				t_p3;

typedef struct	s_sphere
{
	t_p3	c;
	double	diameter;
}				t_sp;

typedef struct	s_plane
{
	t_p3	p;
	t_p3	v;
}				t_pl;
