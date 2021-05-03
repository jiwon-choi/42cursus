#ifndef _RAY_H_
# define _RAY_H_

# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "vec3.h"

typedef struct	s_ray {
	t_p3	origin;
	t_p3	dir;
	float	t;
}				t_ray;

t_p3	ray_at(t_ray r);
double	hit_sphere(t_p3 center, double radius, t_ray ray);
int		ray_color(t_ray r);

#endif
