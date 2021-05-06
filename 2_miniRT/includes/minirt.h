/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:57:58 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/05/05 20:57:41 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MINIRT_H
# define _MINIRT_H

# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# include "mlx.h"
# include "../libft/libft.h"
# include "get_next_line.h"
# include "ray.h"
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

typedef struct	s_camera
{
	t_p3			p;
	t_p3			v;
	int				fov;
	struct s_camera	*next;
}				t_cam;

typedef struct	s_light
{
	t_p3			p;
	double			brightness;
	int				color;
	struct s_light	*next;
}				t_light;

typedef struct	s_scene
{
	int		x_res;
	int		y_res;
	double	ambient_lightning;
	int		ambient_color;

	double	aspect_ratio;
	double	viewport_height;
	double	viewport_width;
	double	focal_length;

	t_light	*light;
	t_cam	*cam;
}				t_scene;

/* convert.c */
void	comma(char **str);
int		rt_atoi(char **str);
double	rt_atof(char **str);
t_p3	rt_ato3(char **str);
int		rt_color(char **str);

/* hit.c */
double	hit_sphere(t_p3 center, double radius, t_ray ray);

/* parse.c */
void	parse_resolution(t_scene *scene, char *str);
void	parse_ambient(t_scene *scene, char *str);
void	parse_camera(t_scene *scene, char *str);
void	parse_light(t_scene *scene, char *str);
void	parse(t_scene *scene, t_fig **lst, char *str);

/* parse_figures.c */
void	parse_sphere(t_fig **lst, char *str);
void	parse_plane(t_fig **lst, char *str);
void	parse_square(t_fig **lst, char *str);
void	parse_cylinder(t_fig **lst, char *str);
void	parse_triangle(t_fig **lst, char *str);

/* ray.c */
t_p3	ray_at(t_ray r);
t_p3	ray_color(t_fig *lst, t_ray r);

/* vec3.c */
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
