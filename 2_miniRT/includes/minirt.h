#ifndef _MINIRT_H
# define _MINIRT_H

# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# include "mlx.h"
# include "../libft/libft.h"
# include "get_next_line.h"
# include "figures.h"

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		*data;
	int		bpp;
	int		size_l;
	int		endian;
}				t_mlx;

/* convert.c */
void	comma(char **str);
int		rt_atoi(char **nptr);
double	rt_atof(char **nptr);
t_p3	rt_ato3(char **str);
int		parse_color(char **str);

/* parse.c */
void	parse_resolution(t_scene *data, char *str);
void	parse_ambient(t_scene *data, char *str);
void	parse_light(t_scene *data, char *str);
void	parse(t_scene *data, t_fig **lst, char *str);

/* parse_figures.c */
void	parse_sphere(t_fig **lst, char *str);
void	parse_plane(t_fig **lst, char *str);
void	parse_square(t_fig **lst, char *str);
void	parse_cylinder(t_fig **lst, char *str);
void	parse_triangle(t_fig **lst, char *str);

#endif
