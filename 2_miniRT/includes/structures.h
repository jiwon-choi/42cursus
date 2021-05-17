/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 21:29:23 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/05/17 18:12:44 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _STRUCTURES_H
# define _STRUCTURES_H

# define SP 0
# define PL 1
# define SQ 2
# define CY 3
# define TR 4

typedef int		t_bool;
typedef int		t_flag;

typedef struct	s_p3
{
	double	x;
	double	y;
	double	z;
}				t_p3;

typedef struct	s_sphere
{
	t_p3	c;
	double	r;
}				t_sp;

typedef struct	s_plane
{
	t_p3	p;
	t_p3	n;
}				t_pl;

typedef struct	s_square
{
	t_p3	c;
	t_p3	n;
	double	side;
}				t_sq;

typedef struct	s_cylinder
{
	t_p3	c;
	t_p3	n;
	double	r;
	double	height;
}				t_cy;

typedef struct	s_triangle
{
	t_p3	p1;
	t_p3	p2;
	t_p3	p3;
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
	t_p3			albedo;
	struct s_fig	*next;
}				t_fig;

typedef struct	s_cam
{
	t_p3			look_from;
	t_p3			look_at;
	int				fov;
	struct s_cam	*next;
}				t_cam;

typedef struct	s_hit_record
{
	t_p3	p;
	t_p3	normal;
	double	t_min;
	double	t_max;
	double	t;
	t_bool	front_face;
	t_p3	albedo;
}				t_hit_record;

typedef struct	s_ray
{
	t_p3	origin;
	t_p3	dir;
}				t_ray;

typedef struct	s_light
{
	t_p3			position;
	double			br;
	t_p3			color;
	struct s_light	*next;
}				t_light;

typedef struct	s_scene
{
	int			res_x;
	int			res_y;
	t_bool		res_ex;

	double		viewport_h;
	double		viewport_w;
	double		aspect_ratio;
	double		focal_length;
	t_p3		origin;
	t_p3		horizontal;
	t_p3		vertical;
	t_p3		l_l_corner;

	double		amb_ratio;
	t_p3		amb_color;
	t_bool		amb_ex;

	t_light		*light;
}				t_scene;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		*data;
	int		bpp;
	int		size_l;
	int		endian;
	t_cam	*first_cam;
	t_cam	*cam;
}				t_mlx;

typedef struct	s_data
{
	t_mlx	mlx;
	t_scene	scene;
	t_fig	*lst;
}				t_data;

typedef struct	s_matrix
{
	int		x;
	int		y;
	double	u;
	double	v;
}				t_matrix;

typedef struct	s_discriminant
{
	double	a;
	double	half_b;
	double	c;
	double	discriminant;
	double	sqrtd;
	double	root;
}				t_discriminant;

typedef struct	s_specular
{
	t_p3	specular;
	t_p3	light_dir;
	t_p3	view_dir;
	t_p3	reflect_dir;
	double	s_weight;
	double	shine;
	double	spec;
}				t_specular;

typedef struct	s_bmp_header
{
	char			type[2];
	unsigned int	size;
	unsigned int	reserved;
	unsigned int	offset;
}				t_bmp_header;

typedef struct	s_dib_header
{
	unsigned int	size;
	int				width;
	int				height;
	unsigned short	colplanes;
	unsigned short	bpp;
	unsigned int	compression;
	unsigned int	img_size;
	int				x_ppm;
	int				y_ppm;
	unsigned int	color_number;
	unsigned int	important_color;
}				t_dib_header;

typedef struct	s_cy_data
{
	double	r2;
	double	t;
	double	a;
	double	b;
	double	c;
	double	t1;
	double	t2;
	t_p3	top;
	t_p3	bot;
	t_p3	hc;
	t_p3	h;
	t_p3	w;
	t_p3	v;
	t_p3	p;
}				t_cy_data;

typedef struct	s_sq_data
{
	t_p3	r;
	t_p3	side_v;
	t_p3	p;
	t_p3	v;
	double	denominator;
	double	nom;
	double	t;
	double	cosine;
	double	limit;
}				t_sq_data;

typedef struct	s_tr_data
{
	t_p3	n;
	t_p3	p;
	t_p3	un;
	t_p3	vn;
	double	denominator;
	double	nom;
	double	t;
	double	s;
	double	tt;
}				t_tr_data;


#endif
