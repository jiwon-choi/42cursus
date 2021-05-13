#ifndef _MINIRT_H
# define _MINIRT_H

# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include "mlx.h"
# include "structures.h"
# include "get_next_line.h"
# include "../libft/libft.h"

# define TRUE 1
# define FALSE 0
# define EPSILON 1e-6

// convert.c
void	comma(char **str);
int		rt_atoi(char **str);
double	rt_atof(char **str);
t_p3	rt_ato3(char **str);
t_p3	rt_albedo(char **str);

// error.c
void    error_check(t_flag flag, char *err_msg);
void	check_null(char **str);
void    check_values(double num, double min, double max, char *err_msg);

// main.c
void	parse(t_data *data, char *rt_file);

// parse.c
void	parse_resolution(t_scene *scene, char *str);
void	parse_ambient(t_scene *scene, char *str);
void	parse_camera(t_mlx *mlx, char *str);
void	parse_light(t_scene *scene, char *str);
void	parse_(t_data *data, char *str);

// parse_figures.c
void	parse_sphere(t_fig **lst, char *str);
void	parse_plane(t_fig **lst, char *str);
void	parse_square(t_fig **lst, char *str);
void	parse_cylinder(t_fig **lst, char *str);
void	parse_triangle(t_fig **lst, char *str);

#endif
