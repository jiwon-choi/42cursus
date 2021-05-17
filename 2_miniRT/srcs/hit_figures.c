#include "../includes/minirt.h"

void	set_face_normal(t_ray *r, t_hit_record *rec)
{
	rec->front_face = vdot(r->dir, rec->normal) < 0;
	rec->normal = (rec->front_face) ? rec->normal : vscalarmul(rec->normal, -1);
}

t_bool	hit_sphere(t_fig *lst, t_ray *r, t_hit_record *rec)
{
	t_p3			oc;
	t_discriminant	d;

	oc = vsubstract(r->origin, lst->fig.sp.c);
	d.a = vdot(r->dir, r->dir);
	d.half_b = vdot(oc, r->dir);
	d.c = vdot(oc, oc) - pow(lst->fig.sp.r, 2);
	d.discriminant = d.half_b * d.half_b - d.a * d.c;
	if (d.discriminant < 0)
		return (FALSE);
	d.sqrtd = sqrt(d.discriminant);
	d.root = (-d.half_b - d.sqrtd) / d.a;
	if (d.root < rec->t_min || rec->t_max < d.root)
	{
		d.root = (-d.half_b + d.sqrtd) / d.a;
		if (d.root < rec->t_min || rec->t_max < d.root)
			return (FALSE);
	}
	rec->t = d.root;
	rec->p = ray_at(r, d.root);
	rec->normal = vscalardiv(vsubstract(rec->p, lst->fig.sp.c), lst->fig.sp.r);
	rec->albedo = lst->albedo;
	set_face_normal(r, rec);
	return (TRUE);
}

t_bool	hit_plane(t_fig *lst, t_ray *r, t_hit_record *rec)
{
	double	denominator;
	double	nom;
	double	t;

	denominator = vdot(r->dir, lst->fig.pl.n);
	nom = vdot(vsubstract(lst->fig.pl.p, r->origin), lst->fig.pl.n); 
	if (!denominator)
		return (FALSE);
	t = nom / denominator;
	if (t < rec->t_min || t > rec->t_max)
		return (FALSE);
	rec->t = t;
	rec->p = ray_at(r, t);
	rec->p = vadd(rec->p, vscalarmul(rec->normal, EPSILON));
	rec->normal = lst->fig.pl.n;
	rec->albedo = lst->albedo;
	set_face_normal(r, rec);
	return (TRUE);
}

t_bool	hit_square(t_fig *lst, t_ray *ray, t_hit_record *rec)
{
	t_p3 r;
	t_p3 side_v;
	double	denominator;
	double nom;
	double t;

	denominator = vdot(ray->dir, lst->fig.sq.n);
	if (!denominator)
		return (FALSE);
	nom = vdot(vsubstract(lst->fig.sq.c, ray->origin), lst->fig.sq.n); 
	t = nom / denominator;
	
	if (t < rec->t_min || t > rec->t_max)
		return (FALSE);

	r = vdefine(0, 1, 0);
	if(fabs(lst->fig.sq.n.y) == 1)
		r = vdefine(1, 0, 0);

	side_v =vcross(lst->fig.sq.n, r);

	t_p3 p = vadd(ray->origin, vscalarmul(ray->dir, t));
	t_p3 v = vsubstract(p,lst->fig.sq.c);

	double cosine = fabs(vdot(side_v, v) / (vlen(side_v) * vlen(v)));
	if (cosine < sqrt(2) / 2)
		cosine = cos(M_PI_2 - acos(cosine));
	double	limit = (lst->fig.sq.side / 2) / cosine;
	if (vlen(v) > limit)
		return (FALSE);
	if(t >= 0)
		{
			rec->t = t;
			rec->normal = lst->fig.sq.n;
			rec->p = ray_at(ray, t);
			// rec->p = vadd(rec->p, vscalarmul(rec->normal, EPSILON));
			rec->albedo = lst->albedo;
			set_face_normal(ray, rec);
			return(TRUE);
		}
	return (FALSE);
}

t_bool	hit_triangle(t_fig *lst, t_ray *r, t_hit_record *rec)
{
 	t_p3	n = vunit(vcross(vsubstract(lst->fig.tr.p2, lst->fig.tr.p1), vsubstract(lst->fig.tr.p3, lst->fig.tr.p1)));

	double	denominator = vdot(r->dir, n);
	if (!denominator)
		return (FALSE);
	double	nom = vdot(vsubstract(lst->fig.tr.p1, r->origin), n);
	double	t = nom / denominator;

	if (t < rec->t_min || t > rec->t_max)
		return (FALSE);

	t_p3	p = vadd(r->origin, vscalarmul(r->dir, t));
	t_p3	un = vcross(n, vsubstract(lst->fig.tr.p2, lst->fig.tr.p1));
	t_p3	vn = vcross(n, vsubstract(lst->fig.tr.p3, lst->fig.tr.p1));
	denominator = vdot(vsubstract(lst->fig.tr.p2, lst->fig.tr.p1), vn);
	if (fabs(denominator) < 0.001)
		return (FALSE);
	double	s = vdot(vsubstract(p, lst->fig.tr.p1), vn) / denominator;
	if (s < 0 || s > 1)
		return (FALSE);
	double tt = vdot(vsubstract(p, lst->fig.tr.p1), un) / -denominator;
	if (!(tt >= 0 && (s + tt) <= 1))
		return (FALSE);
	rec->t = t;
	rec->normal = n;
	rec->p = ray_at(r, t);
	rec->albedo = lst->albedo;
	set_face_normal(r, rec);

	return (TRUE);
}
typedef struct	s_cyvar
{
	double	r2;
	t_p3	top;
	t_p3	bot;
	t_p3	hc;
	t_p3	h;
	t_p3	w;
	t_p3	v;
	double	t;
	double	a;
	double	b;
	double	c;
	double	t1;
	double	t2;
	t_p3	p;
}				t_cyvar;

void	t_select(double *t1, double *t2, int flag)
{
	double	tmp;

	if (flag == 1)
	{
		if (*t1 > *t2)
		{
			tmp = *t1;
			*t1 = *t2;
			*t2 = tmp;
		}
	}
	else
	{
		if (*t1 < *t2)
		{
			tmp = *t1;
			*t1 = *t2;
			*t2 = tmp;
		}
	}
	
}

double	intersect_check(t_cyvar var, double *t1, double *t2, int flag)
{
	double	root;
	double	t;

	root = (var.b * var.b) - (4 * var.a * var.c);
	if (root < 0)
		return (0);
	if (root > 0)
	{
		t = (var.b > 0) ? -0.5 * (var.b + sqrt(root)) : -0.5 * (var.b - sqrt(root));
		*t1 = t / var.a;
		*t2 = var.c / t;
		t_select(t1, t2, flag);
	}
	else if (root == 0)
	{
		if (fabs(vdot(var.v, var.h)) != 1)
		{
			*t1 = -var.b / (2 * var.a);
			*t2 = -(2 * var.a) / var.b;
		}
	}
	return (1);
}

double	cy_calc(t_cyvar var, t_hit_record *rec, int flag)
{	
	double	t;

	var.a = vdot(var.v, var.v) - pow(vdot(var.v, var.h), 2);
	var.b = (vdot(var.v, var.w) - (vdot(var.v, var.h) * vdot(var.w, var.h))) * 2;
	var.c = vdot(var.w, var.w) - pow(vdot(var.w, var.h), 2) - var.r2;
	if (!(intersect_check(var, &var.t1, &var.t2, flag)))
		return (0);
	if ((var.t1 < 0 && var.t2 < 0) || (var.t1 > rec->t_max && var.t2 > rec->t_max))
		return (0);
	if (var.t2 < 0)
		return (0);
	if (var.t1 > 0)
		t = var.t1;
	else
		t = var.t2;
	return (t);
}


double	ft_vec_dist(t_p3 a, t_p3 b)
{
	return (vlen(vsubstract(a, b)));
}

int		cy_boundary(t_fig *lst, t_ray *r, t_cyvar var)
{
	double	len;
	var.p = ray_at(r, var.t);
	len = sqrt(pow(lst->fig.cy.r, 2.0) + pow(lst->fig.cy.height, 2.0));
	if (ft_vec_dist(lst->fig.cy.c, var.p) > len)
		return (0);
	return (1);
}

t_p3	get_cy_normal(t_p3 pos, t_fig *lst)
{
	t_p3	tmp;
	t_p3	normal;

	tmp = vsubstract(pos, lst->fig.cy.c);
	normal = vunit(vsubstract(tmp, vscalarmul(lst->fig.cy.n, vdot(lst->fig.cy.n, tmp))));
	return (normal);
}

int		intersect_cylinder(t_fig *lst, t_ray *r, t_hit_record *rec, int flag)
{
	t_cyvar	var;

	var.r2 = lst->fig.cy.r * lst->fig.cy.r;
	var.top = vsubstract(lst->fig.cy.c, vscalarmul(lst->fig.cy.n, lst->fig.cy.height));
	var.bot = vadd(lst->fig.cy.c, vscalarmul(lst->fig.cy.n, lst->fig.cy.height));
	var.hc = vsubstract(var.top, var.bot);
	var.h = vunit(var.hc);
	var.w = vsubstract(r->origin, var.bot);
	var.v = r->dir;

	if (!(var.t = cy_calc(var, rec, flag)))
		return (0);
	if (!cy_boundary(lst, r, var))
		return (0);
	rec->t = var.t;
	rec->p = ray_at(r, var.t);
	rec->p = vadd(rec->p, vscalarmul(rec->normal, EPSILON));
	rec->normal = get_cy_normal(rec->p, lst);
	rec->albedo = lst->albedo;
	return (1);
}

t_bool	hit_cylinder(t_fig *lst, t_ray *r, t_hit_record *rec)
{
	int		i = 2;
	int		flag = 1;
	t_bool	res = FALSE;

	while (i--)
	{
		if ((res = intersect_cylinder(lst, r, rec, flag)))
			i = 0;
		flag = 0;
	}
	return (res);
}
