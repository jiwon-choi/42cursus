#ifndef _VEC3_H_
# define _VEC3_H_

# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_p3
{
	double	x;
	double	y;
	double	z;
}				t_p3;

t_p3	vdefine(double x, double y, double z);
t_p3	vadd(t_p3 a, t_p3 b);
t_p3	vsubstract(t_p3 a, t_p3 b);
double	vdot(t_p3 a, t_p3 b);
t_p3	vcross(t_p3 a, t_p3 b);
t_p3	vscalarmul(t_p3 a, double t);
t_p3	vscalardiv(t_p3 a, double t);
double	vlen(t_p3 a);
t_p3	vunit(t_p3 a);

#endif
