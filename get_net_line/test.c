#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void)
{
	char *line;
	int ret;
	int fd;
	fd = open("test.txt", O_RDONLY);
	while ((ret = get_next_line(fd, &line)))
	{
		printf("ret : %d line : %s\n", ret, line);
		free(line);
	}
	printf("ret : %d line : %s\n", ret, line);
	free(line);
	return (0);
}
