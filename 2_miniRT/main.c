#include <stdio.h>
#include "minirt.h"

int		main(int argc, char **argv)
{
	char	*str;
	int		fd;

	t_scene		data;
	t_fig		fig;
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (-1);
	while (get_next_line(fd, &str))
		parse(&data, &fig, str);
	printf("%d\n", data.x_res);
	printf("%lf\n", data.light->p.x);
	free(str);
	return (0);
}
