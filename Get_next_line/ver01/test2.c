#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
/** #include "get_next_line.c" */
/** #include "get_next_line_utils.c" */

int main()
{
	printf("\n");

	int fd = open("test.txt", O_RDONLY);
	printf("final result : \t%s\n", get_next_line(fd));

	printf("final result : \t%s\n", get_next_line(fd));
	//printf("result : \t%s\n\n", get_next_line(fd));
	return 0;
}

