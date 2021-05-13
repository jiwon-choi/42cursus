#include "../includes/minirt.h"

void	parse(t_data *data, char *rt_file)
{
	char	*str;
	int		fd;

	data->lst = NULL;
	data->scene.light = NULL;
	data->mlx.cam = NULL;
	data->scene.res_ex = FALSE;
	data->scene.amb_ex = FALSE;

	if ((fd = open(rt_file, O_RDONLY)) == -1)
		exit(1);
	while (get_next_line(fd, &str))
	{
		parse_(data, str);
		free(str);
	}
	free(str);
}

int		main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2 || argc > 3)
		error_check(1, "");
	if (argc == 2 && ft_strncmp(argv[1] + ft_strlen(argv[1]) - 3, ".rt", 3))
		error_check(2, "");
	if (argc == 3 && ft_strncmp(argv[2], "--save", 6))
		error_check(3, "");
	parse(&data, argv[1]);
	//data.mlx.mlx_ptr = mlx_init();


	return (0);
}