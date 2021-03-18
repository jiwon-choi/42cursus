#include "../includes/vec3.h"
#include "../includes/ray.h"

t_p3	ray_color(t_p3 dir)
{
	t_p3	unit_dir;
	t_p3	color;
	float	t;

	unit_dir = vunit(dir);
	t = 0.5 * (unit_dir.y + 1.0);
	color = vdefine(1.0, 1.0, 1.0);
	color.x *= 1.0 - (t * 0.5);
	color.y *= 1.0 - (t * 0.3);
	return (color);
}
