int		main(int argc, char **argv)
    void	parse(t_data *data, char *rt_file)
        int		get_next_line(int fd, char **line)
        void	parse_(t_data *data, char *str)
            ...
        void	ft_mlx_init(t_data *data)
    void	make_picture(t_data *data)
        void	scene_init(t_data *data)
        void	camera_create(t_data *data)
        t_ray	ray_primary(t_scene *scene, double u, double v)
        t_p3	ray_color(t_data *data, t_ray *r)
            t_bool	hit(t_fig *lst, t_ray *r, t_hit_record *rec)
                t_bool	hit_figures(t_fig *lst, t_ray *r, t_hit_record *rec)
                    t_bool	hit_sphere(t_fig *lst, t_ray *r, t_hit_record *rec)
                        void	set_face_normal(t_ray *r, t_hit_record *rec)
                    ...
            t_p3	phong_lighting(t_data *data, t_ray *r, t_hit_record *rec)
                t_p3	point_light_get(t_data *data, t_light *light, t_ray *r,
                    t_bool	in_shadow(t_fig *lst, t_ray light_ray, double light_len)
                        t_bool	hit(t_fig *lst, t_ray *r, t_hit_record *rec)
                            t_bool	hit_figures(t_fig *lst, t_ray *r, t_hit_record *rec)
                                t_bool	hit_sphere(t_fig *lst, t_ray *r, t_hit_record *rec)
                                    void	set_face_normal(t_ray *r, t_hit_record *rec)
                                ...
                    t_p3	diffuse(t_light *light, t_hit_record *rec)
                    t_p3	specular(t_light *light, t_ray *r, t_hit_record *rec)
                        t_p3	reflect(t_p3 v, t_p3 n)

if (--save)
void	make_picture(t_data *data)
void	make_bmp(t_data *data)
    static int		create_file(void)
    static void		create_header(t_scene scene, t_bmp_header *bmp_h,
    static void		write_header(int fd, t_bmp_header bmp_h, t_dib_header dib_h)
    static void		write_file(int fd, t_scene scene, t_mlx mlx)