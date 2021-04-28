#ifndef _MINIRT_H
# define _MINIRT_H

# include <fcntl.h>
# include <math.h>

# include "mlx.h"
# include "libft/libft.h"
# include "get_next_line.h"
# include "figures.h"

/* convert.c */
void	comma(char **str);
int		rt_atoi(char **nptr);
double	rt_atof(char **nptr);
t_p3	rt_ato3(char **str);

/* parse.c */
void	parse_resolution(t_scene *data, char *str);
void	parse_ambient(t_scene *data, char *str);
void	parse(t_scene *data, char *str);

#endif
