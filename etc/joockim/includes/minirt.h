#ifndef _MINIRT_H
# define _MINIRT_H

# define SP 0
# define PL 1
# define SQ 2
# define TR 3
# define CY 4
# define CU 5
# define PY 6

typedef struct	s_fig
{
	int				flag;
	union u_fig		fig;
	int				color;
	t_p3			normal;
	int				specular;
	double			refl_idx;
	double			refr_idx;
	int				texture;
	double			wavelength;
	t_fig			*next;
}				t_fig;

typedef struct	s_light
{
	t_p3	o;
	double	br;
	int		color;
	t_light	*next;
}				t_light;

typedef struct	s_cam
{
	int		idx;
	t_p3	o;
	t_p3	nv;
	int		fov;
	void	*img_ptr;
	int		*px_img;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	t_cam	*next;
}				t_cam;

typedef struct	s_scene
{
	int			res_init;
	int			xres;
	int			yres;
	int			cam_nb;
	t_light		*l;
	int			al_init;
	double		ambient_light;
	int			al_color;
	int			bgr;
}				t_scene;
