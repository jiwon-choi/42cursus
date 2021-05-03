#ifndef _FIGURES_H
# define _FIGURES_H

# include "vec3.h"

# define SP 0
# define PL 1
# define SQ 2
# define CY 3
# define TR 4

typedef struct	s_sphere
{
	t_p3	c;
	double	diameter;
	int		color;
}				t_sp;

typedef struct	s_plane
{
	t_p3	p;
	t_p3	v;
	int		color;
}				t_pl;

typedef struct	s_square
{
	t_p3	c;
	t_p3	v;
	double	side;
	int		color;
}				t_sq;

typedef struct	s_cylinder
{
	t_p3	p;
	t_p3	v;
	double	diameter;
	double	height;
	int		color;
}				t_cy;

typedef struct	s_triangle
{
	t_p3	p1;
	t_p3	p2;
	t_p3	p3;
	int		color;
}				t_tr;

union			u_fig
{
	t_sp	sp;
	t_pl	pl;
	t_sq	sq;
	t_cy	cy;
	t_tr	tr;
};

typedef struct	s_fig
{
	int				flag;
	union u_fig		fig;	
	struct s_fig	*next;
}				t_fig;

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
	t_light	*light;
	t_cam	*cam;
}				t_scene;

#endif
