#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char	*line = NULL;

	while (get_next_line(&line) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s", line);
	free(line);
}
