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
	printf("%x\n", lst->fig.pl.color);
	printf("%x\n", lst->next->fig.sq.color);
	return (0);
}
