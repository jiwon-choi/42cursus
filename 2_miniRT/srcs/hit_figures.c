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
	rec->oc_r = d.root;
	rec->p = ray_at(r, d.root);
	rec->normal = vscalardiv(vsubstract(rec->p,
				lst->fig.sp.c), lst->fig.sp.r);
	rec->albedo = lst->albedo;
	set_face_normal(r, rec);
	return (TRUE);
}
