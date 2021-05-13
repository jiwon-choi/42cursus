#include "../includes/minirt.h"

t_p3	vscalarmul(t_p3 a, double t)
{
	t_p3	v;

	v.x = a.x * t;
	v.y = a.y * t;
	v.z = a.z * t;
	return (v);
}

t_p3	vscalardiv(t_p3 a, double t)
{
	return (vscalarmul(a, (1 / t)));
}
