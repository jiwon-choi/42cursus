#include "../includes/minirt.h"

int		main(int argc, char **argv)
{
	char	*str;
	int		fd;

	t_scene		data;
	t_fig		*lst;

	lst = 0;
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (-1);
	while (get_next_line(fd, &str))
		parse(&data, &lst, str);
	free(str);
	return (0);

/*
	printf("R %d %d\n", data.x_res, data.y_res);
	printf("A %lf %x\n", data.ambient_lightning, data.ambient_color);
	while (data.light)
	{
		printf("x %lf, y %lf, z %lf\n", data.light->p.x, data.light->p.y, data.light->p.z);
		printf("brightness %lf, color %x\n", data.light->brightness, data.light->color);
		data.light = data.light->next;
	}

	printf("\n");
	while (lst)
	{
		printf("x %lf, y %lf, z %lf\n", lst->fig.sp.c.x, lst->fig.sp.c.y, lst->fig.sp.c.z);
		printf("diameter %lf, color %x\n", lst->fig.sp.diameter, lst->fig.sp.color);
		lst = lst->next;
	}
*/
}
