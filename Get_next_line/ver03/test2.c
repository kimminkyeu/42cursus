#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "for_test.h"
/** #include "get_next_line.c" */
/** #include "get_next_line_utils.c" */

int main()
{
	int fd = open("test.txt", O_RDONLY);
	char *str1 = get_next_line(fd);
	printf("str1 : %s", str1);

	char *str2 = get_next_line(fd);
	printf("str2 : %s", str2);

	char *str3 = get_next_line(fd);
	printf("str3 : %s", str3);

	char *str4 = get_next_line(fd);
	printf("str4 : %s", str4);

	char *str5 = get_next_line(fd);
	printf("str5 : %s", str5);

	char *str6 = get_next_line(fd);
	printf("str6 : %s", str6);

	char *str7 = get_next_line(fd);
	printf("str7 : %s", str7);

	char *str8 = get_next_line(fd);
	printf("str8 : %s", str8);

	return 0;
}

