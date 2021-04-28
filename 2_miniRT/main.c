#include <stdio.h>
#include "minirt.h"

int		main(int argc, char **argv)
{
	char	*str;
	int		fd;

	t_scene		data;
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (-1);
	while (get_next_line(fd, &str))
		parse(&data, str);
	printf("%d %d\n", data.x_res, data.y_res);
	printf("%lf\n", data.ambient_lightning);
	free(str);
	return (0);
}
