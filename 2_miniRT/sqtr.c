t_bool	hit_square(t_fig *lst, t_ray *ray, t_hit_record *rec)
{
	// t_p3 r;
	// t_p3 side_v;
	// double	denominator;
	// double nom;
	// double t;

	// denominator = vdot(ray->dir, lst->fig.sq.n);
	// nom = vdot(vsubstract(lst->fig.sq.c, ray->origin), lst->fig.sq.n); 
	// if (!denominator)
	// 	return (FALSE);
	// t = nom / denominator;
	
	// if (t < rec->t_min || t > rec->t_max)
	// 	return (FALSE);

	// r = vdefine(0, 1, 0);
	// if(fabs(lst->fig.sq.n.y) == 1)
	// 	r = vdefine(1, 0, 0);

	// side_v =vcross(lst->fig.sq.n, r);

	// t_p3 p = vadd(ray->origin, vscalarmul(ray->dir, t));
	// t_p3 v = vsubstract(p,lst->fig.sq.c);

	// double cosine = fabs(vdot(side_v, v) / (vlen(side_v) * vlen(v)));
	// if (cosine < sqrt(2) / 2)
	// 	cosine = cos(M_PI_2 - acos(cosine));
	// double	limit = (lst->fig.sq.side / 2) / cosine;
	// if (vlen(v) > limit)
	// 	return (FALSE);
	// if(t >= 0)
	// 	{
	// 		rec->t = t;
	// 		rec->p = ray_at(ray, t);
	// 		rec->normal = lst->fig.sq.n;
	// 		rec->p = vadd(rec->p, vscalarmul(rec->normal, EPSILON));
	// 		rec->albedo = lst->albedo;
	// 		set_face_normal(ray, rec);
	// 		return(1);
	// 	}
	// return (0);

	double	denom;
	double  nom;
	double	t;
	double	len;
	double	cosin;
	t_p3	d;
	t_p3	up;
	t_p3	axis;

	denom = vdot(lst->fig.sq.n, ray->dir);
	nom = vdot(vsubstract(ray->origin, lst->fig.sq.c),lst->fig.sq.n);
	if (denom == 0)
		return (0);
	t = - nom / denom;
	d = vsubstract(ray_at(ray, t), lst->fig.sq.c);
	up = vdefine(0, 1, 0);
	if (lst->fig.sq.n.y != 0 &&(lst->fig.sq.n.x == 0 && lst->fig.sq.n.z == 0))
		up = vdefine(0, 0, 1);
	axis = vcross(up, lst->fig.sq.n);
	cosin = fabs(vdot(up, d) / (vlen(up) * vlen(d)));
	if (cosin < sqrt(2) / 2)
		cosin = cos((M_PI / 2) - acos(cosin));
	len = lst->fig.sq.side / cosin;
	if (vlen(d) > len)
		return (0);
	if (t >= 0)
	{
		rec->t = t;
		rec->p = ray_at(ray, t);
		rec->normal = lst->fig.sq.n;
		rec->p = vadd(rec->p, vscalarmul(lst->fig.sq.n, EPSILON));
		return (1);
	}
	return (0);

}

int		tr_except(t_p3 a, t_p3 b, t_p3 c, t_p3 rec)
{
	t_p3	ba;
	t_p3	ca;
	t_p3	ha;

	ba = vsubstract(b, a);
	ca = vsubstract(c, a);
	ha = vsubstract(rec, a);
	if (vdot(vcross(ba, ca), vcross(ha, ca)) < 0)
		return (0);
	return (1);
}

int		tr_outside(t_ray *ray, t_fig *lst, double t)
{
	t_p3	hitray;

	hitray = ray_at(ray, t);
	if (!tr_except(lst->fig.tr.p1, lst->fig.tr.p2, lst->fig.tr.p3, hitray))
		return (0);
	if (!tr_except(lst->fig.tr.p2, lst->fig.tr.p3, lst->fig.tr.p1, hitray))
		return (0);
	if (!tr_except(lst->fig.tr.p3, lst->fig.tr.p1, lst->fig.tr.p2, hitray))
		return (0);
	return (1);
}

t_bool	hit_triangle(t_fig *lst, t_ray *r, t_hit_record *rec)
{
	t_p3	p1p2 = vsubstract(lst->fig.tr.p2, lst->fig.tr.p1);
	t_p3	p1p3 = vsubstract(lst->fig.tr.p3, lst->fig.tr.p1);

	t_p3 pvec = vcross(r->dir, p1p3);
	double det = vdot(p1p2, pvec);

	double invdet = 1 / det;
	t_p3 tvec = vsubstract(r->origin, lst->fig.tr.p1);
	double u = vdot(tvec, pvec) * invdet;

	if (u < 0 || u > 1)
		return (0);

	t_p3 qvec = vcross(tvec, p1p2);
	double v = vdot(r->dir, qvec) *invdet;
	if (v < 0 || u + v > 1)
		return (0);

	double t = vdot(p1p3, qvec) * invdet;

	t_p3 normal = vunit(vcross(vsubstract(lst->fig.tr.p2, lst->fig.tr.p1), vsubstract(lst->fig.tr.p3, lst->fig.tr.p1)));

	double denom = vdot(normal, r->dir);
	double nom = vdot(vsubstract(r->origin, lst->fig.tr.p1), normal);
	if (denom == 0)
		return (0);
	t = -nom / denom;
	if (!tr_outside(r, lst, t))
		return (0);
	if (t > EPSILON && t < rec->t)
	{
		rec->t = t;
		rec->p = ray_at(r, rec->t);
		rec->normal = normal;
		rec->p = vadd(rec->p, vscalarmul(rec->normal, EPSILON));
		return (1);
	}
	return (0);
}