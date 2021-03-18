#include "../includes/vec3.h"

t_p3	vdefine(double x, double y, double z)
{
	t_p3	v;
	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_p3	vadd(t_p3 a, t_p3 b)
{
	t_p3	v;
	v.x = a.x + b.x;
	v.y = a.y + b.y;
	v.z = a.z + b.z;
	return (v);
}

t_p3	vsubstract(t_p3 a, t_p3 b)
{
	t_p3	v;
	v.x = a.x - b.x;
	v.y = a.y - b.y;
	v.z = a.z - b.z;
	return (v);
}

double	vdot(t_p3 a, t_p3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_p3	vcross(t_p3 a, t_p3 b)
{
	t_p3	v;
	v.x = a.y * b.z - a.z * b.y;
	v.y = a.z * b.x - a.x * b.z;
	v.z = a.x * b.y - a.y * b.x;
	return (v);
}

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

double	vlen(t_p3 a)
{
	double	len;

	len = a.x * a.x + a.y * a.y + a.z * a.z;
	len = sqrt(len);
	return (len);
}

t_p3	vunit(t_p3 a)
{
	return (vscalardiv(a, vlen(a)));
}
