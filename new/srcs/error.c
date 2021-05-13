#include "../includes/minirt.h"

void	error_check(t_flag flag, char *err_msg)
{
	printf("Error\n");
	if (flag == 1)
		printf("Arguments count\n");
	else if (flag == 2)
		printf("Not rt file\n");
	else if (flag == 3)
		printf("Invalid option\n");
	else if (flag == 4)
		printf("Check contents : %s\n", err_msg);
	else if (flag == 5)
		printf("Memory error : %s\n", err_msg);
	else if (flag == 6)
		printf("Out of range : %s\n", err_msg);
	exit(1);
}

void	check_null(char **str)
{
	while (ft_isspace(**str))
		*str += 1;
	if (**str)
		error_check(4, "Arguments over\n");
}

void	check_values(double num, double min, double max, char *err_msg)
{
	if (min <= num && num <= max)
		return ;
	else
		error_check(6, err_msg);
}