#ifndef _FIGURES_H
# define _FIGURES_H

typedef struct	s_p3
{
	double	x;
	double	y;
	double	z;
}				t_p3;

typedef struct	s_sphere
{
	t_p3	c;
	double	diameter;
	t_p3	color;
}				t_sp;

typedef struct	s_plane
{
	t_p3	p;
	t_p3	v;
	t_p3	color;
}				t_pl;

typedef struct	s_square
{
	t_p3	c;
	t_p3	v;
	double	side;
	t_p3	color;
}				t_sq;

typedef struct	s_cylinder
{
	t_p3	p;
	t_p3	v;
	double	diameter;
	double	height;
	t_p3	color;
}				t_cy;

typedef struct	s_triangle
{
	t_p3	p1;
	t_p3	p2;
	t_p3	p3;
	t_p3	color;
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
	struct s_cam	*next;
}				t_cam;

typedef struct	s_light
{
	t_p3			p;
	double			brightness;
	t_p3			color;
	struct s_light	*next;
}				t_light;

typedef struct	s_scene
{
	int		x_res;
	int		y_res;
	double	ambient_lightning;
	t_p3	color;
	t_light	*light;
	t_cam	*cam;
}				t_scene;

#endif
