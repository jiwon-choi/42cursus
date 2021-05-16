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
	nom = vdot(vsubstract(lst->fig.sq.c, ray->origin), lst->fig.sq.n); 
	if (!denominator)
		return (FALSE);
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
			rec->p = ray_at(ray, t);
			rec->normal = lst->fig.sq.n;
			rec->p = vadd(rec->p, vscalarmul(rec->normal, EPSILON));
			rec->albedo = lst->albedo;
			set_face_normal(ray, rec);
			return(TRUE);
		}
	return (FALSE);
}