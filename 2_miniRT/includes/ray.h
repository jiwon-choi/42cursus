#ifndef _RAY_H_
# define _RAY_H_

# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "vec3.h"

t_p3	raydefine(t_p3 origin, t_p3 dir, float t);
t_p3	ray_color(t_p3 dir);

#endif
