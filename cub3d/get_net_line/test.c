#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void)
{
	char *line;
	int ret;
	int fd;
	int fd2;

	fd = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	ret = get_next_line(fd, &line);
		printf("ret : %d line : %s\n", ret, line);
		free(line);
	ret = get_next_line(fd2, &line);
		printf("ret : %d line : %s\n", ret, line);
		free(line);
	ret = get_next_line(fd2, &line);
		printf("ret : %d line : %s\n", ret, line);
		free(line);
	ret = get_next_line(fd, &line);
		printf("ret : %d line : %s\n", ret, line);
		free(line);
	ret = get_next_line(fd, &line);
		printf("ret : %d line : %s\n", ret, line);
		free(line);
	ret = get_next_line(fd2, &line);
		printf("ret : %d line : %s\n", ret, line);
		free(line);
	ret = get_next_line(fd, &line);
		printf("ret : %d line : %s\n", ret, line);
		free(line);
	ret = get_next_line(fd2, &line);
		printf("ret : %d line : %s\n", ret, line);
		free(line);
	ret = get_next_line(fd2, &line);
		printf("ret : %d line : %s\n", ret, line);
		free(line);
	ret = get_next_line(fd, &line);
		printf("ret : %d line : %s\n", ret, line);
		free(line);
	ret = get_next_line(fd2, &line);
		printf("ret : %d line : %s\n", ret, line);
		free(line);
	ret = get_next_line(fd2, &line);
		printf("ret : %d line : %s\n", ret, line);
		free(line);
	ret = get_next_line(fd2, &line);
		printf("ret : %d line : %s\n", ret, line);
		free(line);
	ret = get_next_line(fd2, &line);
		printf("ret : %d line : %s\n", ret, line);
		free(line);
	ret = get_next_line(fd2, &line);
		printf("ret : %d line : %s\n", ret, line);
		free(line);
	ret = get_next_line(fd2, &line);
		printf("ret : %d line : %s\n", ret, line);
		free(line);
	ret = get_next_line(fd2, &line);
		printf("ret : %d line : %s\n", ret, line);
		free(line);
	//while ((ret = get_next_line(fd, &line)))
	//{
//		printf("ret : %d line : %s\n", ret, line);
//		free(line);
//	}
//	printf("ret : %d line : %s\n", ret, line);
//	free(line);
	return (0);
}
